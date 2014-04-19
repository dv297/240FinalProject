#include "UnionFind.h"

/********************************************************************
 * Main class for doing the union-find algorithm.
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
 *   a - first number within the link being added
 *   b - second number within the link being added
 *
 * Returns:
 *   none
 *
 **/
void UnionFind::addLink(int a, int b)
{
  int larger; // Holds the larger value
  int smaller;  // Holds the smaller value
  
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
    nodes[larger].setParentValue(smaller);
  }
  
  parentNode = this->find(larger);
  currentNode = this->find(smaller);
  
  // Basically saying if we have hit root = root
  if(parentNode.equals(currentNode))
  {
    Node tempNode;
    tempNode.setCurrentValue(larger);
    tempNode.setParentValue(smaller);
    
    Utils::logStream << this->dumpPaths(smaller, larger) << endl;
    Utils::logStream.flush();
  }
  else
  {
    // Trying to incorporate rootOfSmaller and smallerNode
    Node tempNode;
    tempNode.setCurrentValue(larger);
    tempNode.setParentValue(smaller);
    
    Utils::logStream << TAG << "BUILD TREE BY ADDING ARC";
    Utils::logStream << tempNode.toString() << endl;
    Utils::logStream.flush();
    
    nodes[larger].setParentValue(smaller);
  }
  
  Utils::logStream << TAG << endl;
  Utils::logStream << this->toString() << endl;
  Utils::logStream.flush();
}

/********************************************************************
 * Function to find a value within a node.
 *
 * Parameters:
 *   value - integer to find within the node
 *
 * Returns:
 *   the number found
 *
 **/
Node UnionFind::find(int value)
{
  Node root;
  vector<Node> nodePath;
  
  root = this->find(value, nodePath);
  
  return root;
}

#warning - I'm lost as hell
/********************************************************************
 * Function to find again?
 * Makes the value you put in the root of a mini tree
 *
 * Parameters:
 *   value - integer to find within the node
 *   nodePath -
 *
 * Returns:
 *   the current node
 *
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
 * String function to dump the paths to the output file.
 * Run if rootOfSmaller.equals(thisValue), passed in smaller then larger
 *
 * Parameters:
 *   parent -
 *   current -
 *
 * Returns:
 *   s - the string that displays the paths of the algorithm
 *
 **/
string UnionFind::dumpPaths(int parent, int current)
{
  string s = "";
  
  Node currentValue;
  Node parentValue;
  
  vector<Node> pathParent;
  vector<Node> pathCurrent;
  
  parentValue = this->find(parent, pathParent);
  currentValue = this->find(current, pathCurrent);
  
  vector<Node>::iterator itSmaller = pathParent.end();
  vector<Node>::iterator itLarger = pathCurrent.end();
  
  while((*itSmaller).equals(*itLarger))
  {
    --itSmaller;
    --itLarger;
  }
  
  Node tempNode;
  
  tempNode.setCurrentValue(current);
  tempNode.setParentValue(parent);
  
  
  if(pathCurrent[0].getParentValue() !=( tempNode.getParentValue() ))
  {
    Utils::logStream << TAG << "FOUNDCYCLE IN ADDING ARC";
    Utils::logStream << tempNode.toString() << endl;
    std::string pathOne;
    std::string pathTwo;
    pathOne = tempNode.toString() + this->toStringPath(pathParent, *itSmaller);
    pathTwo = this->toStringPath(pathCurrent, *itLarger);
    while(pathOne.substr( pathOne.size()-12, pathOne.size() ) ==
          pathTwo.substr( pathTwo.size()-12, pathTwo.size()))
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
    Utils::logStream << TAG << "BUILD TREE BY ADDING ARC";
    Utils::logStream << tempNode.toString() << endl;
  }
  return s;
}

/********************************************************************
 * Usual 'toString', in this case a formatted line with the data
 * from the instance of the Node class.
 *
 * Returns:
 *   the usual 'string', in this case a <WHAT, IDK?>
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
 * Derivative function of the usual 'toString' method but in this
 * case it is dumping a formatted line of the path.
 *
 * This method traverses through the vector<Node> path passed in
 * from the front to the end.
 *
 * Parameters:
 *   path -
 *   bottom -
 *
 * Returns:
 *   the 'string' of each node
 *
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
