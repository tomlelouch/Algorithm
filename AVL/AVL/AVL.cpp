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
    leftchild->height = Max( Height(leftchild->left) , Height(leftchild->right) ) + 1;
    return leftchild;
    
}


TreeNode* AVL::SingleRotationwithRight(TreeNode *&node){
    
    TreeNode *rightchild = node->right;
    node->right = rightchild->left;
    rightchild->left = node;
    node->height = Max( Height(node->left) , Height(node->right) ) + 1;
    rightchild->height = Max( Height(rightchild->left) , Height(rightchild->right) ) + 1;
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


int AVL::FindSmallestPrivate(TreeNode *&node){
    
    if (root != nullptr){
        if (node->left != nullptr){
            return FindSmallestPrivate(node->left);
        }
        else{
            return node->key;
        }
    }
    else{
        cout<<"The AVL tree is empty, could not find the smallest key"<<endl;
        return -10000;
    }
    
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
        node->height = Max( Height(node->left) , Height(node->right) ) + 1;
        return node;
    }
    else{
        root = new TreeNode(key);
        return root;
    }
    
}


TreeNode*& AVL::SearchPrivate(int key , TreeNode *&node){
    
    if (root != nullptr){
        if (node->key == key){
            return node;
        }
        else if (node->key > key && node->left != nullptr){
            return SearchPrivate(key , node->left);
        }
        else if (node->key < key && node->right != nullptr){
            return SearchPrivate(key , node->right);
        }
        else{
            cout<<"Could not find the node, return nullptr"<<endl;
            return node->right == nullptr ? node->right : node->left;
        }
    }
    else{
        cout<<"The AVL Tree is empty, return nullptr"<<endl;
        return root;
    }
    
}


void AVL::Delete(int key){
    
    root = DeletePrivate(key , root);
    if ( Height(root->left) - Height(root->right) == 2 ){
        root =
        Height(root->left->left) > Height(root->left->right) ?
        SingleRotationwithLeft(root)
        : DoubleRotationwithLeft(root);
    }
    else if( Height(root->left) - Height(root->right) == -2 ){
        root =
        Height(root->right->right) > Height(root->right->left) ?
        SingleRotationwithRight(root)
        : DoubleRotationwithRight(root);
    }
    
}


TreeNode*& AVL::DeletePrivate(int key , TreeNode *&MatchNodeParent){
    
    if (root != nullptr){
        //int SmallestKeyInright
        if ( root->key == key ){
            root = DeleteRoot(root);
            return root;
        }
        else if ( MatchNodeParent->key > key && MatchNodeParent->left != nullptr ){
            if (MatchNodeParent->left->key == key){
                MatchNodeParent = DeleteMatch( MatchNodeParent , MatchNodeParent->left , true);
            }
            else{
                MatchNodeParent->left = DeletePrivate( key , MatchNodeParent->left );
                if ( Height(MatchNodeParent->left->right) - Height(MatchNodeParent->left->left) == 2 ){
                    //do the rotation of MatchNodeParent->left
                    MatchNodeParent->left =
                    Height(MatchNodeParent->left->right->left) > Height(MatchNodeParent->left->right->right) ?
                    DoubleRotationwithRight(MatchNodeParent->left)
                    : SingleRotationwithRight(MatchNodeParent->left);
                }
                else if ( Height(MatchNodeParent->left->right) - Height(MatchNodeParent->left->left) == -2 ){
                    MatchNodeParent->left =
                    Height(MatchNodeParent->left->left->right) > Height(MatchNodeParent->left->left->left) ?
                    DoubleRotationwithLeft(MatchNodeParent->left)
                    : SingleRotationwithLeft(MatchNodeParent->left);
                }
            }
        }
        else if ( MatchNodeParent->key < key && MatchNodeParent->right != nullptr ){
            if (MatchNodeParent->right->key == key){
                MatchNodeParent = DeleteMatch( MatchNodeParent , MatchNodeParent->right , false);
            }
            else {
                MatchNodeParent->right = DeletePrivate( key , MatchNodeParent->right);
                if ( Height(MatchNodeParent->right->left) - Height(MatchNodeParent->right->right) == 2 ){
                    MatchNodeParent->right =
                    Height(MatchNodeParent->right->left->right) > Height(MatchNodeParent->right->left->left) ?
                    DoubleRotationwithLeft(MatchNodeParent->right)
                    : SingleRotationwithLeft(MatchNodeParent->right);
                }
                else if ( Height(MatchNodeParent->right->left) - Height(MatchNodeParent->right->right) == -2 ){
                    MatchNodeParent->right =
                    Height(MatchNodeParent->right->right->left) > Height(MatchNodeParent->right->right->right) ?
                    DoubleRotationwithRight(MatchNodeParent->right)
                    : SingleRotationwithLeft(MatchNodeParent->right);
                }
            }
        }
        else{
            cout<<"There is no node containing key value: "
            << key << " , return nullptr"<< endl;
            return MatchNodeParent->right == nullptr ? MatchNodeParent->right
                   : MatchNodeParent->left;
        }
        MatchNodeParent->height = Max( Height(MatchNodeParent->left) , Height(MatchNodeParent->right) ) + 1;
        
        return MatchNodeParent;
    }
    else{
        cout<<"The AVL Tree is empty,could not delete the node containing keyvalue: "
        << key << " ,return nullptr"<< endl;
        return root;
    }
    
}


TreeNode*& AVL::DeleteRoot(TreeNode *&node){
    
    int SmallestKeyInRightSubTree ;
    TreeNode* Temp = root ;
    
    // case 0 --- 0 child
    if ( root->left == nullptr && root->right == nullptr){
        root = nullptr;
        delete Temp;
        return root;
    }
    
    // case 1 --- only left child
    else if ( root->left != nullptr && root->right == nullptr){
        root = Temp->left;
        Temp->left = nullptr;
        delete Temp;
        return root;
    }
    // case 2 --- only right child
    else if ( root->right == nullptr && root->right != nullptr){
        root = Temp->right;
        Temp->right = nullptr;
        delete Temp;
        return root;
    }
    // case 3 --- two children
    else{
        SmallestKeyInRightSubTree = FindSmallestPrivate( root->right );
        root = DeletePrivate( SmallestKeyInRightSubTree , root );
        root->key = SmallestKeyInRightSubTree ;
        return root;
    }
    
}


TreeNode*& AVL::DeleteMatch(TreeNode *&parent , TreeNode *match , bool left){
    
    TreeNode *Temp = match;
    int SmallestKeyValueInRightSubTree;
    
    //case 0 --- no child
    if ( match->left == nullptr && match->right == nullptr){
       left == true ? parent->left = nullptr
        : parent->right = nullptr;
        match = nullptr;
        delete Temp;
        parent->height = Max( Height(parent->left) , Height(parent->right) ) + 1;
        return parent;
        
    }
    
    //case 1 --- only left child
    else if ( match->left != nullptr && match->right == nullptr){
        left == true ? parent->left = match->left
        : parent->right = match->left;
        match = nullptr;
        delete Temp;
        parent->height = Max( Height(parent->left) , Height(parent->right) ) + 1;
        return parent;
    }
    
    //case 2 --- only right child
    else if ( match->left == nullptr && match->right == nullptr){
        left == true ? parent->left = match->right
        : parent->right = match->right;
        match = nullptr;
        delete Temp;
        parent->height = Max( Height(parent->left) , Height(parent->right) ) + 1;
        return parent;
    }
    
    //case 3 --- two children
    else{
        SmallestKeyValueInRightSubTree = FindSmallestPrivate(match->right);
        DeletePrivate(SmallestKeyValueInRightSubTree , root);
        match->key = SmallestKeyValueInRightSubTree;
        parent->height = Max( Height(parent->left) , Height(parent->right) ) + 1;
        return parent;
    }
    
}
