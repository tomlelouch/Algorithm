//
//  main.cpp
//  AVL
//
//  Created by Young on 5/5/14.
//  Copyright (c) 2014 Gatech. All rights reserved.
//

#include <iostream>
#include <vector>
#include "AVL.h"

int main(int argc, const char * argv[])
{
    AVL tree;
    
    // This is for speed test
    for (int i=0;i<1000000000;i++){
        tree.Insert(i);
    }
    
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

