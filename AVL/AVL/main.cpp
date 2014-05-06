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
    for (int i=0;i<1000000000;i++){
        tree.Insert(i);
    }
    return 0;
}

