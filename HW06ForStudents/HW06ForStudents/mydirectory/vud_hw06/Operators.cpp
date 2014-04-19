#include "UnionFind.h"
#include "Node.h"

/********************************************************************
 * Operator overlord class for Homework 6.
 *
 * Authors: Daniel Vu, Collin Haines, Kevin Silver, Julio Diaz
 * Copyright: All rights reserved.
 * Date: 16 April 2014
 * Submission Date: 24 April 2014
 *
 **/

/********************************************************************
 * Overloaded '<<' operator, not a 'Node' member function.
 *
 * Parameters:
 *   outputStream - out stream using 'iosfwd'
 *   node - 'Node' class calling for the 'toString()'
 *
 * Returns:
 *   the 'toString' within 'Node'
 **/
ostream& operator <<(ostream& outputStream, Node& node)
{
   return outputStream << node.toString();
} // ostream& operator <<(ostream& outputStream, Node& node)

/********************************************************************
 * Overloaded '<<' operator, not a 'UnionFind' member function.
 *
 * Parameters:
 *   outputStream - out stream using 'iosfwd'
 *   uf - 'UnionFind' class calling for the 'toString()'
 *
 * Returns:
 *   the 'toString' used within 'UnionFind'
 **/
ostream& operator <<(ostream& outputStream, UnionFind& uf)
{
   return outputStream << uf.toString();
} // ostream& operator <<(ostream& outputStream, UnionFind& uf)
