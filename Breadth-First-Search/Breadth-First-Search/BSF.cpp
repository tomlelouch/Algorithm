//
//  BSF.cpp
//  Breadth-First Search
//
//  Created by Young on 5/21/14.
//  Copyright (c) 2014 Gatech. All rights reserved.
//

#include "BSF.h"
#include <vector>
#include <deque>
using namespace std;


void Breadth_First_Search(node *source , vector< vector<node *> > &Adj ){
    
    vector< node * > frontier ;
    (*source).SetLevel(true) ;
    frontier.push_back(source) ;
    while ( frontier.size() != 0 ){
        
        vector< node* > next;
        
        for ( auto &frontier_node : frontier ){
            for ( auto &neighbor : Adj.at( (*frontier_node).GetIndex() ) ){
                
                if ( (*neighbor).GetLevel() != true ){
                    
                    (*neighbor).SetLevel(true);
                    auto itr = Adj[ (*frontier_node).GetIndex() ].begin();
                    node * ptr =  *itr ;
                    (*neighbor).SetParent( ptr );
                    next.push_back(neighbor) ;
                    
                }
            }
        }
        frontier = next ;
    }
    
}