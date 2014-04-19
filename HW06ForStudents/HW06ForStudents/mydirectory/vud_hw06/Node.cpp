#include "Node.h"

/********************************************************************
 * Class for holding a specificed value and the root for the
 * specificed value.
 *
 * Authors/copyright: Duncan Buell. All rights reserved.
 * Modifed by: Daniel Vu, Collin Haines, Kevin Silver, Julio Diaz
 * Speculated start date: January 2014
 * Submission Date: 24 April 2014
 *
 **/

static const string TAG = "Node: ";

/********************************************************************
 * Constructor.
 *
 * DUMMYX is defined as -1
 * DUMMYY is defined as -2
 *
 **/
Node::Node()
{
  this->parentValue= DUMMYX;
  this->currentValue = DUMMYX;
}

/********************************************************************
 * Destructor.
 **/
Node::~Node()
{
}

/********************************************************************
 * Accessors and mutators.
 **/

/********************************************************************
 * Accessor for the current value in a particular node.
 *
 * Returns:
 *   the current value of the node
 **/
int Node::getCurrentValue() const
{
  return this->currentValue;
} // int Node::getCurrentValue()

/********************************************************************
 * Accessor for the parent value in a particular node.
 *
 * Returns:
 *   the parent value of the node
 **/
int Node::getParentValue() const
{
  return this->parentValue;
} // int Node::getParentValue()

/********************************************************************
 * Mutator for the current value in a particular node.
 *
 * Parameters:
 *   value - integer to set the current value of the node
 *
 * Returns:
 *   none
 **/
void Node::setCurrentValue(int value)
{
  this->currentValue = value;
} // void Node::setCurrentValue(int value)

/********************************************************************
 * Mutator for the parent value in a particular node.
 *
 * Parameters:
 *   value - integer to set the parent value of the node
 *
 * Returns:
 *   none
 **/
void Node::setParentValue(int value)
{
  this->parentValue = value;
} // void Node::setParentValue(int value)

/********************************************************************
 * General functions.
 **/

/********************************************************************
 * Function to determine if the a node equals another node.
 *
 * As we are determining the path to make the tree, compare itself to
 * see if we are equal to each other.
 *
 * Parameters:
 *   that - the node that is being compared to.
 *
 * Returns:
 *   True: the node is equal to each other.
 *   False: the node is not equal to each other.
 **/
bool Node::equals(Node that)
{
  if (this->currentValue == that.getCurrentValue() &&
      this->parentValue == that.getParentValue())
  {
    return true;
  }
  return false;
} // bool Node::equals(Node that)

/********************************************************************
 * Function to determine if we are at the top of the tree or not.
 *
 * Returns:
 *   the equality comparision of the 'parentValue' and 'currentValue'
 **/
bool Node::atTop()
{
  return (this->parentValue == this->currentValue);
} // bool Node::atTop()

/********************************************************************
 * Usual 'toString', in this case a formatted line with the data
 * from the instance of this class.
 *
 * Returns:
 *   the usual 'string', in this case, a formatted node
 **/
string Node::toString() const
{
  string s = "";
  s += "(" + Utils::Format(getCurrentValue(), 3) + " -> ";
  s += Utils::Format(getParentValue(), 3) + ")";
  return s;
} // string Node::toString()
