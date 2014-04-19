#include "UnionFind.h"
#include "Node.h"

/********************************************************************
 * Class for
 *
 * Authors/copyright: Duncan Buell. All rights reserved.
 * Modifed by: Daniel Vu, Collin Haines, Kevin Silver, Julio Diaz
 * Speculated start date: January 2014
 * Submission Date: 24 April 2014
 *
 **/

ostream& operator <<(ostream& outputStream, Node& node){
   return outputStream << node.toString();
}


ostream& operator <<(ostream& outputStream, UnionFind& uf){
   return outputStream << uf.toString();
}
