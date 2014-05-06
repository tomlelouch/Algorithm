//
//  AVL.cpp
//  AVL
//
//  Created by Young on 5/4/14.
//  Copyright (c) 2014 Gatech. All rights reserved.
//

#include "AVL.h"

using namespace std;

TreeNode* AVL::SingleRotationwithLeft(TreeNode *&node){
    TreeNode *leftchild = node->left;
    node->left = leftchild->right;
    leftchild->right = node;
    node->height = Max(Height(node->left) , Height(node->right))+1;
    leftchild->height = Max(Height(leftchild->left) , Height(leftchild->right))+1;
    return leftchild;
}

TreeNode* AVL::SingleRotationwithRight(TreeNode *&node){
    TreeNode *rightchild = node->right;
    node->right = rightchild->left;
    rightchild->left = node;
    node->height = Max(Height(node->left) , Height(node->right))+1;
    rightchild->height = Max(Height(rightchild->left) , Height(rightchild->right));
    return rightchild;
}

TreeNode* AVL::DoubleRotationwithLeft(TreeNode *&node){
    node->left = SingleRotationwithRight(node->left);
    node = SingleRotationwithLeft(node);
    return node;
}

TreeNode* AVL::DoubleRotationwithRight(TreeNode *&node){
    node->right = SingleRotationwithLeft(node->right);
    node = SingleRotationwithRight(node);
    return node;
}


TreeNode*& AVL::InsertPrivate(int key , TreeNode *&node){
    if (root != nullptr){
        if (node == nullptr){
            node = new TreeNode(key);
        }
        else if (key < node->key){
            node->left = InsertPrivate(key , node->left);
            if ( Height(node->left) - Height(node->right) == 2){
                node = node->left->key > key ? SingleRotationwithLeft(node)
                : DoubleRotationwithLeft(node);
            }
        }
        else if (key > node->key){
            node->right = InsertPrivate(key , node->right);
            if (Height(node->right) - Height(node->left) == 2 ){
                node = node->right->key < key ? SingleRotationwithRight(node)
                : DoubleRotationwithRight(node);
            }
        }
        node->height = Max(Height(node->left) , Height(node->right) )+1;
        return node;
    }
    else{
        root = new TreeNode(key);
        return root;
    }
}