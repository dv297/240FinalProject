#include "UnionFind.h"

static const string TAG = "UnionFind: ";

UnionFind::UnionFind()
{
}

UnionFind::~UnionFind()
{
}

void UnionFind::addLink(int a, int b)
{
  int larger; // Holds the larger value, originally whatever
  int smaller;  // Holds the smaller value, originally which

  XX thisValue;
  XX rootOfSmaller;

  if(a <= b)
  {
     smaller = a;
     larger = b;
  }
  else
  {
     smaller = b;
     larger = a;
  }


  XX smallerNode = nodes[smaller];
  if(smallerNode.getX() == DUMMYX)
  {
     nodes[smaller].setX(smaller);
     nodes[smaller].setY(smaller);
  }
  XX largerNode = nodes[larger];
  if(largerNode.getX() == DUMMYX)
  {
     nodes[larger].setX(larger);
     nodes[larger].setY(larger);
  }
  rootOfSmaller = this->find(smaller);
  thisValue = this->find(larger); // possibly rename thisValue?
  if(rootOfSmaller.equals(thisValue))
  {
     XX tempNode;
     tempNode.setX(larger);
     tempNode.setY(smaller);
     Utils::logStream << tempNode.toString() << endl;
     Utils::logStream << this->frabjous(smaller, larger) << endl;
     Utils::logStream.flush();
  }
  else
  {
     XX tempNode;
     tempNode.setX(larger);
     tempNode.setY(smaller);
     Utils::logStream << tempNode.toString() << endl;
     Utils::logStream.flush();
     nodes[larger].setY(smaller);
  }
  Utils::logStream << TAG << endl;
  Utils::logStream << this->toString();
  Utils::logStream.flush();
}

/********************************************************************
 *
**/
XX UnionFind::find(int zz)
{
  XX root;
  vector<XX> nodePath;
  root = this->find(zz, nodePath);
  return root;
}

/********************************************************************
 *
**/
XX UnionFind::find(int zz, vector<XX>& nodePath)
{
  XX root;

  root = nodes[zz];
  nodePath.push_back(root);
  if(root.getX() != root.getY())
  {
     while(root.getX() != root.getY())
     {
        root = nodes[root.getY()];
        nodePath.push_back(root);
     }
  }
  return root;
}


/********************************************************************
 * Run if rootOfSmaller.equals(thisValue), passed in smaller then larger
**/
string UnionFind::frabjous(int smaller, int larger)
{
  string s = "";
  XX thisValue, rootOfSmaller;
  vector<XX> pathSmaller, pathLarger;
  rootOfSmaller = this->find(smaller, pathSmaller);
  thisValue = this->find(larger, pathLarger);
  vector<XX>::iterator itSmaller = pathSmaller.end();
  vector<XX>::iterator itLarger = pathLarger.end();
  --itSmaller;
  --itLarger;
  while( (*itSmaller).equals( (*itLarger) ))
  {
     --itSmaller;
     --itLarger;
  }
  XX topOfSmaller = *itSmaller;
  XX topOfLarger = *itLarger;
  XX tempNode;
  tempNode.setX(larger); // This makes it look like larger is the top one, then Y is bottom
  tempNode.setY(smaller);
  Utils::logStream << TAG << "PATH ONE " << tempNode.toString() << this->toStringZORK(pathSmaller, *itSmaller) << endl;
  cout << TAG << "PATH ONE " << tempNode.toString() << this->toStringZORK(pathSmaller, *itSmaller) << endl;
  Utils::logStream.flush();
  Utils::logStream << TAG << "PATH TWO " << this->toStringZORK(pathLarger, *itLarger) << endl << endl;
  cout << TAG << "PATH TWO " << this->toStringZORK(pathLarger, *itLarger) << endl << endl;
  Utils::logStream.flush();
  return s;
}


/********************************************************************
 *
**/
string UnionFind::toString()
{
  string s = "";
  map<int, XX>::iterator it;
  for(it = this->nodes.begin(); it != this->nodes.end(); ++it)
  {
     vector<XX> path;
     int usu = it->first;
     XX node = this->find(usu, path);
     s += this->toStringZORK(path, node) + "\n";
  }
  return s;
}

/********************************************************************
 *
**/
string UnionFind::toStringZORK(vector<XX> path, XX last)
{
  string s = "";
  for(vector<XX>::iterator it = path.end(); it != path.begin(); --it)
  {
     s += (*it).toString();
     if( (*it).equals(last)) break;
  }
  return s;
}
