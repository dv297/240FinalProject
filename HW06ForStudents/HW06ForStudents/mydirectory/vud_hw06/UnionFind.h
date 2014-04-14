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
  UnionFind();
  virtual ~UnionFind();

  void addLink(int a, int b);
  void dumpTrees();
  void buildTrees();
  Node find(int value);
  Node find(int value, vector<Node>& nodePath);

  string toString();

private:
  vector<std::pair<int, int> > links;
  map<int, Node> nodes;

  string frabjous(int smaller, int larger);
  string toStringPath(vector<Node> path, Node bottom);
};

#endif // UNIONFIND_H
