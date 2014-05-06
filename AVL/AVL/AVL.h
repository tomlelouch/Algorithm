//
//  AVL.h
//  AVL
//
//  Created by Young on 5/4/14.
//  Copyright (c) 2014 Gatech. All rights reserved.
//

//#ifndef __AVL__AVL__
//#define __AVL__AVL__

#include <iostream>
class TreeNode{
public:
    TreeNode()=default;
    
    TreeNode(int k, int h, TreeNode *l, TreeNode *r):
            key(k) , height(h) , left(l) , right(r){};
    
    TreeNode(int k): key(k){};
    
    int       key    = 0;
    int       height = 0;
    TreeNode *left   = nullptr;
    TreeNode *right  = nullptr;
};


class AVL{
public:
    AVL()=default;
    void Insert(int key);
    
private:
    TreeNode* root = nullptr;
    TreeNode*& InsertPrivate(int key , TreeNode *&node);
    int Height(TreeNode *node);
    int Max(int a , int b);
    TreeNode* SingleRotationwithLeft(TreeNode *&node);
    TreeNode* SingleRotationwithRight(TreeNode *&node);
    TreeNode* DoubleRotationwithLeft(TreeNode *&node);
    TreeNode* DoubleRotationwithRight(TreeNode *&node);
};

inline void AVL::Insert(int key){
    InsertPrivate(key , root);
}

inline int AVL::Height(TreeNode *node){
    
    return node == nullptr ? -1 : node->height;
}

inline int AVL::Max(int a , int b){
    return a>b ? a : b;
}

//#endif /* defined(__AVL__AVL__) */
