#include "UnionFind.h"

static const string TAG = "UnionFind: ";

/********************************************************************
 *
 **/
UnionFind::UnionFind()
{
}

/********************************************************************
 *
 **/
UnionFind::~UnionFind()
{
}

/********************************************************************
 *
 **/
void UnionFind::addLink(int a, int b)
{
  int larger; // Holds the larger value, originally whatever
  int smaller;  // Holds the smaller value, originally which
  
  Node parentNode;
  Node currentNode;
  
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
  
  // Checks if smallerNode has default values
  currentNode = nodes[smaller];
  
  if(currentNode.getCurrentValue() == DUMMYX)
  {
    nodes[smaller].setCurrentValue(smaller);
    nodes[smaller].setParentValue(smaller);
  }
  
  // Checks if largerNode has default values
  Node largerNode = nodes[larger];
  if(largerNode.getCurrentValue() == DUMMYX)
  {
    nodes[larger].setCurrentValue(larger);
    nodes[larger].setParentValue(smaller); // We changed this
  }
  
  parentNode = this->find(larger);
  currentNode = this->find(smaller);
  //links.push_back(  std::make_pair(rootOfSmaller.getCurrentValue(), smallerNode.getCurrentValue())  );
  
  // Basically saying if we have hit 1 -> 1
  if(parentNode.equals(currentNode))
  {
    Node tempNode;
    tempNode.setCurrentValue(larger);
    tempNode.setParentValue(smaller);
    Utils::logStream << TAG << "BUILD TREE BY ADDING ARC" << tempNode.toString() << endl;
    Utils::logStream.flush();
  }
  else
  {
    // Trying to incorporate rootOfSmaller and smallerNode
    Node tempNode;
    
    tempNode.setCurrentValue(smaller);
    tempNode.setParentValue(larger);
    
    Utils::logStream << TAG << "BUILD TREE BY ADDING ARC" << tempNode.toString() << endl;
    Utils::logStream.flush();
    
    nodes[larger].setParentValue(smaller);
  }
  
  Utils::logStream << TAG << endl;
  Utils::logStream << this->toString();
  Utils::logStream.flush();
}

/********************************************************************
 * 4-14-14
 * - Found in the .h file.
 **/
void UnionFind::dumpTrees()
{
  
}

/********************************************************************
 * 4-14-14
 * - In the Original Main.cpp there is a line "unionFind.buildTrees()"
 *   commented out.
 **/
void UnionFind::buildTrees()
{
  
}

/********************************************************************
 *
 **/
Node UnionFind::find(int value)
{
  Node root;
  vector<Node> nodePath;
  root = this->find(value, nodePath);
  return root;
}

/********************************************************************
 * Makes the value you put in the root of a mini tree
 **/
Node UnionFind::find(int value, vector<Node>& nodePath)
{
  Node root;
  
  root = nodes[value];
  nodePath.push_back(root);
  
  if(root.getCurrentValue() != root.getParentValue())
  {
    while(root.getCurrentValue() != root.getParentValue())
    {
      root = nodes[root.getParentValue()];
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
  
  // Note: Buell marks down if two declarations are on one line.
  Node thisValue;
  Node rootOfSmaller;
  vector<Node> pathSmaller;
  vector<Node> pathLarger;
  
  rootOfSmaller = this->find(smaller, pathSmaller);
  thisValue = this->find(larger, pathLarger);
  
  vector<Node>::iterator itSmaller = pathSmaller.end();
  vector<Node>::iterator itLarger = pathLarger.end();
  
  while((*itSmaller).equals(*itLarger))
  {
    --itSmaller;
    --itLarger;
  }
  
  Node topOfSmaller = *itSmaller;
  Node topOfLarger = *itLarger;
  Node tempNode;
  
  tempNode.setCurrentValue(larger);
  tempNode.setParentValue(smaller);
  
  Utils::logStream << TAG << "PATH ONE " << tempNode.toString() << this->toStringPath(pathSmaller, *itSmaller) << endl;
  Utils::logStream.flush();
  Utils::logStream << TAG << "PATH TWO " << this->toStringPath(pathLarger, *itLarger) << endl << endl;
  Utils::logStream.flush();
  
  return s;
}


/********************************************************************
 *
 **/
string UnionFind::toString()
{
  string s = "";
  map<int, Node>::iterator it;
  
  for(it = this->nodes.begin(); it != this->nodes.end(); ++it)
  {
    vector<Node> path;
    int value = it->first;
    Node node = this->find(value, path);
    s += this->toStringPath(path, node) + "\n";
  }
  return s;
}

/********************************************************************
 * Traverses through the vector<Node> path passed in from the front to the end
 * Returns the toString of each Node
 *
 * We had to change it to be from front to back ,not back to front.
 **/
string UnionFind::toStringPath(vector<Node> path, Node bottom)
{
  string s = "";
  
  for(vector<Node>::iterator it = path.begin(); it != path.end(); ++it)
  {
    s += (*it).toString();
    if( (*it).equals(bottom)) break;
  }
  return s;
}
