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
  // Ensures that the smaller value is used as the parent node 
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
  
  parentNode = this->find(smaller);
  currentNode = this->find(larger);
  
  // If parent == current, then we have hit the top of the tree
  if(parentNode.equals(currentNode))
  {
    Node tempNode;
    tempNode.setCurrentValue(larger);
    tempNode.setParentValue(smaller);
    
    Utils::logStream << this->dumpPaths(smaller, larger) << endl;
    Utils::logStream.flush();
  }
  // If we are not at the top of the tree
  else
  {
    Node tempNode;
    tempNode.setCurrentValue(larger);
    tempNode.setParentValue(smaller);
    
    Utils::logStream << TAG << "BUILD TREE BY ADDING ARC";
    Utils::logStream << tempNode.toString() << endl;
    Utils::logStream.flush();
    
    // Connects the current node to the tree
    nodes[larger].setParentValue(smaller);
  }
  
  Utils::logStream << TAG << endl;
  Utils::logStream << this->toString() << endl;
  Utils::logStream.flush();
}

/********************************************************************
 * Function to find a node with a certain value in the tree. 
 * A vector of Nodes is created called nodePath.
 *
 * If the current node's parent does not have the same value
 * as the current node, a condition that implies one is located
 * at the top of the tree, then nodePath will push_back the current
 * node, move to the parent node, and repeat this 
 * until this condition is met. 
 *
 * This method is a container function for find(int, vector<Node>)
 * method. It instantiates the vector that will hold all of the 
 * parent nodes of a particular node.
 *
 * Parameters:
 *   value - integer value of the node desired
 *
 * Returns:
 *   The Node found
 *   If no Node is found, then a Node with 
 *   dummy currentValue and dummy parentValue
 *   is returned.
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
 *
 * If the current node's parent does not have the same value
 * as the current node, a condition that implies one is located
 * at the top of the tree, then nodePath will push_back the current
 * node, move to the parent node, and repeat this 
 * until this condition is met. 
 *
 * This method is a container function for find(int, vector<Node>)
 *
 * Parameters:
 *   value - integer value of the node desired
 *   nodePath - A vector that contains the current node
 *              and all of its parent nodes.
 *
 * Returns:
 *   The Node found
 *   if the desired node does not exist, then a node with
 *   dummy currentValue and dummy parentValue
 *   is returned.
 * 
 * Modifies:
 *   nodePath - the vector will get all the nodes connected
 *              inserted into it.
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
 * This function 
 * Run if rootOfSmaller.equals(thisValue), passed in smaller then larger
 *
 * Parameters:
 *   parent -
 *   current -
 *
 * Returns:
 *   s - the string that displays the paths of the algorithm
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
  
  
  if(pathCurrent[0].getParentValue() != ( tempNode.getParentValue() ))
  {
    Utils::logStream << TAG << "FOUNDCYCLE IN ADDING ARC";
    Utils::logStream << tempNode.toString() << endl;
    std::string pathOne;
    std::string pathTwo;
    pathOne = tempNode.toString() + this->toStringPath(pathParent, *itSmaller);
    pathTwo = this->toStringPath(pathCurrent, *itLarger);
    // This snippet fulfills the extra credit requirement
    // If the two paths contain the same nodes,
    // those nodes are cut from the string
    // so only unique paths are output
    while(pathOne.substr( pathOne.find_last_of("\(") , pathOne.size() ) ==
          pathTwo.substr( pathTwo.find_last_of("\(") , pathTwo.size()  ) )
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
