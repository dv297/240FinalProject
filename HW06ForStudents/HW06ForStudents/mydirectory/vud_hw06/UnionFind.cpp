#include "UnionFind.h"

/********************************************************************
 * Class for
 *
 * Authors/copyright: Duncan Buell. All rights reserved.
 * Modifed by: Daniel Vu, Collin Haines, Kevin Silver, Julio Diaz
 * Speculated start date: January 2014
 * Submission Date: 24 April 2014
 *
 **/

static const string TAG = "UnionFind: ";

/********************************************************************
 * Constructor.
 **/
UnionFind::UnionFind()
{
}

/********************************************************************
 * Destructor.
 **/
UnionFind::~UnionFind()
{
}

/********************************************************************
 * Accessors and mutators.
 **/

/********************************************************************
 * General functions.
 **/

/********************************************************************
 * Function to add links to the union-find algorithm.
 *
 * Parameters:
 *   a - 
 *   b -
 *
 * Returns:
 *   none
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
    nodes[larger].setCurrentValue(larger);  // Maybe this is what causes the 4-16-14 inf loop
    nodes[larger].setParentValue(smaller); // We changed this
  }
  
  parentNode = this->find(larger);
  currentNode = this->find(smaller);

  //links.push_back(  std::make_pair(rootOfSmaller.getCurrentValue(), smallerNode.getCurrentValue())  );
  
  // Basically saying if we have hit root = root
  if(parentNode.equals(currentNode))
  {
    Node tempNode;
    tempNode.setCurrentValue(larger); // 4-16-14 Look at this
    tempNode.setParentValue(smaller);


    Utils::logStream << this->dumpPaths(smaller, larger) << endl;
    Utils::logStream.flush();
  }
  else
  {
    // Trying to incorporate rootOfSmaller and smallerNode

    Node tempNode;
    // 4-17-14, Matched set_Value to if statement above to print correctly.
    tempNode.setCurrentValue(larger); // ACTUALLY LOOK AT THIS
    tempNode.setParentValue(smaller);
    
    Utils::logStream << TAG << "BUILD TREE BY ADDING ARC" << tempNode.toString() << endl;
    Utils::logStream.flush();
    
    nodes[larger].setParentValue(smaller);
  }
  
  Utils::logStream << TAG << endl;
  Utils::logStream << this->toString() << endl;
  Utils::logStream.flush();
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
  Node current;
  
  current = nodes[value];
  nodePath.push_back(current);
  
  if(current.getCurrentValue() != current.getParentValue())
  {
    while(current.getCurrentValue() != current.getParentValue())
    {
      current = nodes[current.getParentValue()];
      nodePath.push_back(current);
    }
  }
  return current;
}


/********************************************************************
 * Run if rootOfSmaller.equals(thisValue), passed in smaller then larger
 **/
string UnionFind::dumpPaths(int parent, int current)
{
  string s = "";
  
  // Note: Buell marks down if two declarations are on one line.
  Node currentValue;
  Node parentValue;

  vector<Node> pathParent;
  vector<Node> pathCurrent;
  
  parentValue = this->find(parent, pathParent); // As of 4-16, this was backwards, changed 4-17
  currentValue = this->find(current, pathCurrent);
  
  vector<Node>::iterator itSmaller = pathParent.end();
  vector<Node>::iterator itLarger = pathCurrent.end();
  
  while((*itSmaller).equals(*itLarger))
  {
    --itSmaller;
    --itLarger;
  }
  
  //Node topOfSmaller = *itSmaller;
  //Node topOfLarger = *itLarger;
  Node tempNode;
  
  tempNode.setCurrentValue(current);
  tempNode.setParentValue(parent);


  if(pathCurrent[0].getParentValue() !=( tempNode.getParentValue() ))
  {
     Utils::logStream << TAG << "FOUNDCYCLE IN ADDING ARC" << tempNode.toString() << endl;
     std::string pathOne;
     std::string pathTwo;
     pathOne = tempNode.toString() + this->toStringPath(pathParent, *itSmaller); // took out tempNode.toString() 4-17i
     pathTwo = this->toStringPath(pathCurrent, *itLarger);
     while(pathOne.substr( pathOne.size()-12, pathOne.size() ) == pathTwo.substr( pathTwo.size()-12, pathTwo.size()))
     // 11 is the number of characters to represent one node.
     {
        pathOne = pathOne.substr(0, pathOne.size()-12);
        pathTwo = pathTwo.substr(0, pathTwo.size()-12);
     }
     Utils::logStream << TAG << "PATH ONE " << pathOne << endl;
     Utils::logStream << TAG << "PATH TWO " << pathTwo << endl << endl;
     Utils::logStream.flush();
  }
  else
  {
    Utils::logStream << TAG << "BUILD TREE BY ADDING ARC" << tempNode.toString() << endl;
  }
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
    if((*it).equals(bottom))
    {
      break;
    }
  }
  return s;
}
