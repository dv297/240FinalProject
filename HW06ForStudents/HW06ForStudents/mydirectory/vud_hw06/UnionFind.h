/****************************************************************
 * Header for 'UnionFind' class
 *
 * Author/copyright: Duncan Buell. All rights reserved.
 * Used with permission:
 *   Daniel Vu, Collin Haines, Kevin Silver, Julio Diaz
 * Speculated start date: January 2014
 * Submission Date: 24 April 2014
 *
 **/

#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <map>
#include <vector>

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"

#include "Node.h"

class UnionFind
{
public:
  /****************************************************************
   * Constructors and destructors for the class.
   **/
  UnionFind();
  virtual ~UnionFind();

  /****************************************************************
   * General functions.
   **/
  void addLink(int a, int b);
  void dumpTrees();
  void buildTrees();
  Node find(int value);
  Node find(int value, vector<Node>& nodePath);

  string toString();

private:
  map<int, Node> nodes;

  /****************************************************************
   * General private functions.
   **/
  string dumpPaths(int smaller, int larger);
  string toStringPath(vector<Node> path, Node bottom);
  bool checkPathsEqual(vector<Node> path1, vector<Node> path2);
};

#endif // UNIONFIND_H
