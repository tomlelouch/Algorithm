//
//  main.cpp
//  Breadth-First Search
//
//  Created by Young on 5/21/14.
//  Copyright (c) 2014 Gatech. All rights reserved.
//





#include <iostream>
#include "BSF.h"
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    vector< vector<node *> > Adj ;
    
    vector< node > Node;
    for ( int i = 0 ; i < 8 ; i++){
        // Generate the node information
        
        node N( i ) ;
        Node.push_back(N) ;
    }
    
    for (auto itr = Node.begin() ; itr != Node.end() ; ++itr){
        // Create Adjanct list to hold neighbors of given node
        
        vector< node * > TempRow;
        node *ptr = &(*(itr));
        TempRow.push_back( ptr );
        Adj.push_back( TempRow );
    }
    
    Adj.at(0).push_back(&Node[1]);
    Adj.at(0).push_back(&Node[2]);
    Adj.at(1).push_back(&Node[0]);
    Adj.at(0).push_back(&Node[2]);
    Adj.at(2).push_back(&Node[1]);
    Adj.at(2).push_back(&Node[3]);
    Adj.at(2).push_back(&Node[5]);
    Adj.at(3).push_back(&Node[2]);
    Adj.at(3).push_back(&Node[4]);
    Adj.at(3).push_back(&Node[6]);
    Adj.at(4).push_back(&Node[3]);
    Adj.at(4).push_back(&Node[7]);
    Adj.at(5).push_back(&Node[2]);
    Adj.at(5).push_back(&Node[6]);
    Adj.at(6).push_back(&Node[3]);
    Adj.at(6).push_back(&Node[5]);
    Adj.at(7).push_back(&Node[4]);
    
    Breadth_First_Search( &Node[0] , Adj );
    
    return 0;
}

