//
//  BST.h
//  BST
//
//  Created by Young on 5/2/14.
//  Copyright (c) 2014 Gatech. All rights reserved.
//

#ifndef BST_H
#define BST_H
#include <vector>
class TreeNode{
public:
	TreeNode(int k=0,
             TreeNode *l=nullptr,
             TreeNode *r=nullptr)
    :key(k),left(l),right(r){};
	int key;
	TreeNode *left;
	TreeNode *right;
};

class BST{
public:
	BST(TreeNode *r=nullptr):root(r){};
	void Insert(int key);
	int FindSmallest();
    int FindBiggest();
	void Inorder_Traversal(std::vector<int> &arr);
	void DeleteNode(int key);
private:
	TreeNode *root;
	void InsertPrivate(int key,TreeNode *&node);
	int FindSmallestPrivate(TreeNode *node);
    int FindBiggestPrivate(TreeNode *node);
	void Inorder_TraversalPrivate(std::vector<int> &arr , TreeNode *node);
	void DeleteNodePrivate(int key , TreeNode *parent);
	void DeleteRoot();
	void DeleteMatch(TreeNode *parent , TreeNode *match , bool left);
};


#endif
