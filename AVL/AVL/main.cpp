//
//  main.cpp
//  AVL
//
//  Created by Young on 5/5/14.
//  Copyright (c) 2014 Gatech. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include "AVL.h"
using namespace std;
int main(int argc, const char * argv[])
{
    AVL tree;
    
    // This is for speed test
    
    /*const int s = 10000000;
	srand( time(0) );*/
    
	clock_t start2=clock();
    
	/*for (int i=0;i<s;i++){
		tree.Insert( rand()%(s*2) );
	}*/
    for (int i=0;i<10000000;i++){
        tree.Insert(i);
    }
    
	clock_t end2=clock();
	cout<<"Time taken for BST INSERT: "<< (double)(end2-start2)/(CLOCKS_PER_SEC)<<endl;
	
    
    // This is for functional test
     /*
    tree.Insert(20);
    tree.Insert(10);
    tree.Insert(30);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(25);
    tree.Insert(1);
    tree.Delete(20);*/
    return 0;
}

