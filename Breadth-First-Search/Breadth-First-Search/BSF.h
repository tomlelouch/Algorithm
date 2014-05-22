//
//  BSF.h
//  Breadth-First Search
//
//  Created by Young on 5/21/14.
//  Copyright (c) 2014 Gatech. All rights reserved.
//

#ifndef __Breadth_First_Search__BSF__
#define __Breadth_First_Search__BSF__

#include <iostream>
#include <vector>
class node{
public:
    node(int index = 0 ,
         int data = 0 ,
         bool level = false ,
         node *parent = nullptr )
    : index ( index ) ,
      data ( data ) ,
      level ( level ) ,
      parent ( parent ){}
    
    void SetLevel( bool l );
    void SetParent ( node *p );
    int GetIndex();
    bool GetLevel();
private:
    int index = 0 ;
    int data = 0 ;
    bool level = false ;
    node *parent = nullptr ;
};

inline void node::SetLevel( bool l ){
    level = l ;
}

inline void node::SetParent( node *p ){
    parent = p ;
}

inline int node::GetIndex(){
    return index ;
}

inline bool node::GetLevel(){
    return level ;
}

void Breadth_First_Search(node *source , std::vector< std::vector<node *> > &Adj );

#endif /* defined(__Breadth_First_Search__BSF__) */
