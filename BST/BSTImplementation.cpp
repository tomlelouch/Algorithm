//
//  BSTImplementation.cpp
//  BST
//
//  Created by Young on 5/2/14.
//  Copyright (c) 2014 Gatech. All rights reserved.
//


#include "BST.h"
#include <iostream>
#include <vector>
using namespace std;
void BST::Insert(int key){
	InsertPrivate(key,root);
}

void BST::InsertPrivate(int key, TreeNode *&node){
	if (root != nullptr){
		if (node == nullptr){
		    node=new TreeNode(key , nullptr , nullptr);
		}
		else if (node->key > key ){
		    InsertPrivate(key , node->left);
		}
		else if (node->key < key ){
            InsertPrivate(key , node->right);
		}
	}
	else{
		root=new TreeNode(key,nullptr,nullptr);
		if (root == nullptr){
			cout<<"Root Insert failed!"<<endl;
		}
	}
	
}

int BST::FindSmallest(){
	return FindSmallestPrivate(root);
}

int BST:: FindSmallestPrivate(TreeNode *node){
	if (root != nullptr){
	    if (node->left != nullptr){
	    	return FindSmallestPrivate(node->left);
        }
	    else{
	    	return node->key;
	    }
	}
	else{
	    cout<<"Root is empty, Could not find the smallest!"
        <<endl;
	    return -10000;
	}
}

int BST::FindBiggest(){
    return FindBiggestPrivate(root);
}

int BST::FindBiggestPrivate(TreeNode *node){
    if (root != nullptr){
        if (node->right != nullptr){
            return FindBiggestPrivate(node->right);
        }
        else{
            return node->key;
        }
    }
    else{
        cout<<"Root is empty, could not find the biggest!"
            <<endl;
        return -20000;
    }
}

void BST::Inorder_Traversal(vector<int> &arr){
	Inorder_TraversalPrivate(arr , root);
}

void BST::Inorder_TraversalPrivate(vector<int> &arr , TreeNode *node){
	if (root != nullptr){
		if (node != nullptr){
	   	    Inorder_TraversalPrivate(arr , node->left);
		    arr.push_back(node->key);
		    Inorder_TraversalPrivate(arr , node->right);
        }
		else{
		    return;
		}
        
	}
	else{
	    cout<<"The tree is empty, could not Inorder Traversal"
		<<endl;
	}
}

void BST::DeleteNode(int key){
	DeleteNodePrivate(key , root);
}

void BST::DeleteNodePrivate(int key , TreeNode *parent){
	if (root != nullptr){
        
		if ( root->key == key){
			DeleteRoot();
			return;
		}
        
		if (parent->key < key && parent->right != nullptr){
			parent->right->key == key ? DeleteMatch(parent , parent->right , false)
			: DeleteNodePrivate(key , parent->right);
		}
		else if (parent->key > key && parent->left != nullptr){
			parent->left->key == key ? DeleteMatch(parent , parent->left , true)
			: DeleteNodePrivate(key , parent->left);
		}
		else{
			cout<<"There is no node containing key: "
            <<key<<endl;
		}
	}
	else{
		cout<<"The tree is empty, could not delete the node with key: "
        <<key<<endl;
		return;
	}
}

void BST::DeleteRoot(){
	if (root != nullptr){
		TreeNode *Temp=root;
		int rootkey=root->key;
		int SmallestKeyInRightSubTree;
		//case 0 -0 child
		if (root->left == nullptr && root->right == nullptr){
			root=nullptr;
			delete Temp;
            cout<<"The root containing key: "<<rootkey<<" was deleted -case 0"<<endl;
		}
        
		//case 1 -1 child
		else if (root->left != nullptr && root->right == nullptr){
			root=Temp->left;
            Temp->left=nullptr;
			delete Temp;
            cout<<"The root containing key: "<<rootkey<<" was deleted -case 1"<<endl;
		}
		else if (root->left == nullptr && root->right != nullptr){
			root=Temp->right;
            Temp->right=nullptr;
			delete Temp;
            cout<<"The root containing key: "<<rootkey<<" was deleted -case 1"<<endl;
		}
        
		//case 2 -2 child
		else{
            SmallestKeyInRightSubTree=FindSmallestPrivate(root->right);
            DeleteNodePrivate(SmallestKeyInRightSubTree, root);
            root->key=SmallestKeyInRightSubTree;
            cout<<"The root containing key: "<<rootkey<<" was deleted -case 2"<<endl;
        }
    }
    else{
            cout<<"The tree is empty, could not delete the root"<<endl;
    }
}

void BST::DeleteMatch(TreeNode *parent ,
                      TreeNode *match ,
                      bool left){
    if (root != nullptr){
        int matchkey=match->key;
        int SmallestKeyInRightSubTree;
        TreeNode *Temp=match;
        //case 0 -0 child
        if (match->left == nullptr && match->right == nullptr){
            left == true ? parent->left = nullptr :
            parent->right = nullptr;
            match=nullptr;
            delete Temp;
            cout<<"The match node containing key: "<<matchkey<<" was deleted -case 0"<<endl;
        }
        
        //case 1 -1 child
        else if (match->left != nullptr && match->right == nullptr){
            left == true ? parent->left = match->left :
            parent->right = match->left;
            match=nullptr;
            delete Temp;
            cout<<"The match node containing key: "<<matchkey<<" was deleted -case 1"<<endl;
        }
        
        else if (match->left == nullptr && match->right != nullptr ){
            left == true ? parent->left = match->right :
            parent->right = match->right;
            match=nullptr;
            delete Temp;
            cout<<"The match node containing key: "<<matchkey<<" was deleted -case 1"<<endl;
        }
        //case 2 -2 child
        else if (match->left != nullptr && match->right != nullptr){
            SmallestKeyInRightSubTree=FindSmallestPrivate(match->right);
            DeleteNodePrivate(SmallestKeyInRightSubTree, root);
            match->key=SmallestKeyInRightSubTree;
        }
    }
    else{
        cout<<"The root is empty, could not delete the match"<<endl;
    }
}
