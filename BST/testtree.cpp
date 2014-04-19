#include <iostream>
#include "BST.h"
#include <vector>
using namespace std;

int main(){
	BST tree;
	vector<int>sort1;
	vector<int>sort2;
	tree.Insert(10);
	tree.Insert(5);
	tree.Insert(15);
	tree.Insert(18);
	tree.Insert(19);
	tree.Insert(1);
	tree.Insert(0);
	tree.Insert(14);
	tree.Insert(6);
	tree.Insert(7);
	tree.Insert(13);
	tree.Insert(3);
	tree.Insert(4);
	tree.Inorder_Traversal(sort1);
	for (auto itr:sort1){
		cout<<itr<<" ";
	}
	cout<<endl;
	tree.RemoveNode(10);
	tree.Inorder_Traversal(sort2);
	for (auto itr:sort2){
		cout<<itr<<" ";
	}
	return 0;
}