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
  Node find(int thatX);
  Node find(int thatX, vector<Node>& nodePath);

  string toString();

private:
  vector<std::pair<int, int> > links;
  map<int, Node> nodes;

  string frabjous(int xx, int yy);
  string toStringPath(vector<Node> path, Node last);
};

#endif // UNIONFIND_H
