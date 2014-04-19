#ifndef BST_H
#define BST_H
#include <vector>

class TreeNode{
public:
	int element;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int key=0,TreeNode *l=nullptr, TreeNode *r=nullptr):element(key),left(l),right(r){};
};

class BST{
public:
	BST(TreeNode *r=nullptr):root(r){};
	void Insert(int key);
	void Delete();
	void Inorder_Traversal(std::vector<int> &arr);
	void RemoveNode(int key);
	int FindSmallest();

private:
	TreeNode *root;
	void insert(int key,TreeNode *&node);
	void delet(TreeNode *node);
	void inorder_traversal(TreeNode *node,std::vector<int> &arr);
	void removenode(int key,TreeNode *parent);
	void removerootmatch();
	int findsmallest(TreeNode *node);
	void removematch(TreeNode *parent,TreeNode *match, bool left);
};

void BST::insert(int key,TreeNode *&node){
	if (node==nullptr){
		node=new TreeNode(key,nullptr,nullptr);
		if (node==nullptr)
			std::cout<<"Insert error"<<std::endl;
	}
	else if (key>node->element)
		insert(key,node->right);
	else if (key<node->element)
		insert(key,node->left);
}

void BST::Insert(int key){
	insert(key,root);
}

void BST::inorder_traversal(TreeNode *node,std::vector<int> &arr){
	if (node==nullptr)
		return;
	else{
		inorder_traversal(node->left,arr);
		arr.push_back(node->element);
		inorder_traversal(node->right,arr);
	}
}

void BST::Inorder_Traversal(std::vector<int> &arr){
	inorder_traversal(root,arr);
}

int BST::FindSmallest(){
	return findsmallest(root);
}

int BST::findsmallest(TreeNode *node){
	if (root != nullptr){
		if (node->left != nullptr){
			return findsmallest(node->left);
		}
		else
			return node->element;
	}
	else{
		std::cout<<"The tree is empty"<<std::endl;
		return -100000;
	}
}

void BST::RemoveNode(int key){
	removenode(key,root);
};

void BST::removenode(int key,TreeNode *parent){
	if (root !=nullptr){
		if(root->element==key)
			removerootmatch();
		else{
			if(key < parent->element && parent->left!=nullptr){
				parent->left->element == key ?
				removematch(parent,parent->left,true):
				removenode(key,parent->left);	
			}
			else if(key > parent->element && parent->right!=nullptr){
				parent->right->element == key ?
				removematch(parent,parent->right,false):
				removenode(key,parent->right);
			}
			else
				std::cout<<"The key:"<<key<<"was not found in the tree"<<std::endl;
		}
	}
	else
		std::cout<<"The tree is empty"<<std::endl;
};

void BST::removerootmatch(){
	if (root != nullptr){
		TreeNode *delPtr = root;
		int rootKey = root->element;
		int SmallestInRightSubtree;
		//case 0 -0 child
		if (root->left == nullptr && root->right == nullptr){
			root=nullptr;
			delete delPtr;
		}
		// case 1 -1 child
		else if (root->left != nullptr && root->right == nullptr){
			root=root->left;
			delPtr->left=nullptr;
			delete delPtr;
			std::cout<<"The root node with key "<<rootKey<<" was deleted. "<<
					   "The new root contains key "<<root->element<<std::endl;
		}
		else if (root->left == nullptr && root->right != nullptr){
			root = root->right;
			delPtr->right = nullptr; //this line sometimes is unnecessary
			delete delPtr;
			std::cout<<"The root node with key "<<rootKey<<" was deleted. "<<
					   "The new root contains key "<<root->element<<std::endl;
		}
		// case 2 -2 children
		else{
			SmallestInRightSubtree=findsmallest(root->right);
			removenode(SmallestInRightSubtree,root); // double recursion
			root->element=SmallestInRightSubtree;
			std::cout<<"The root key containing key "<< rootKey <<
					   " was overwritten with key" <<SmallestInRightSubtree<<std::endl;
		}

	}
	else 
		std::cout<<"The tree is already empty"<<std::endl;
}

void BST::removematch(TreeNode *parent, TreeNode *match, bool left){
	if (root != nullptr){
		TreeNode *delPtr=match;
		int matchkey=match->element;
		int SmallestInRightSubtree;
		//case 0-0 child
		if (match->left == nullptr && match->right == nullptr){
			left == true ? parent->left = nullptr : parent->right=nullptr;
			delete delPtr;
			std::cout<<"The Node containing key "<< matchkey << " was removed"<<std::endl;
		}
		//case 1-1 child
		else if(match->left != nullptr && match->right == nullptr){
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = nullptr;
			delete delPtr;
		}
		else if(match->left == nullptr && match->right != nullptr){
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = nullptr;
			delete delPtr;
		}
		//case 2-2 children
		else{
			SmallestInRightSubtree = findsmallest (match->right);
			removenode(SmallestInRightSubtree,match);
			match->element=SmallestInRightSubtree;
		}
	}
	else 
		std::cout<<"The tree is empty"<<std::endl;
}

#endif