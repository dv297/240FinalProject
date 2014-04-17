//
//  Operator.cpp
//  Homework6GitHub
//
//  Created by Collin Haines on 4/16/14.
//  Copyright (c) 2014 Collin Haines. All rights reserved.
//

#include "UnionFind.h"
#include "Node.h"

ostream& operator <<(ostream& outputStream, Node& node){
   return outputStream << node.toString();
}


ostream& operator <<(ostream& outputStream, UnionFind& uf){
   return outputStream << uf.toString();
}
