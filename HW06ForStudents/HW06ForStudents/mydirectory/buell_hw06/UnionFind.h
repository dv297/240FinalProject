#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <map>
#include <vector>

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"

#include "XX.h"

class UnionFind
{
public:
  UnionFind();
  virtual ~UnionFind();

  void addLink(int a, int b);
  void dumpTrees();
  XX find(int thatX);
  XX find(int thatX, vector<XX>& nodePath);

  string toString();

private:
  vector<std::pair<int, int> > links;
  map<int, XX> nodes;

  string frabjous(int xx, int yy);
  string toStringZORK(vector<XX> path, XX last);
};

#endif // UNIONFIND_H
