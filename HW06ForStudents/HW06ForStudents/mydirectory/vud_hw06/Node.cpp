#include "Node.h"

static const string TAG = "Node: ";

/********************************************************************
 * DUMMYX is defined as -1
 * DUMMYY is defined as
 **/
Node::Node()
{
  this->currentValue = DUMMYX;
  this->nextValue = DUMMYY;
}

/********************************************************************
 *
 **/
Node::Node(int x, int y)
{
  this->currentValue = x;
  this->nextValue = y;
}

/********************************************************************
 *
 **/
Node::~Node()
{
}

/********************************************************************
 *
 **/
int Node::getCurrentValue()
{
  return this->currentValue;
}

/********************************************************************
 *
 **/
int Node::getNextValue()
{
  return this->nextValue;
}

/********************************************************************
 *
 **/
void Node::setCurrentValue(int value)
{
  this->currentValue = value;
}

/********************************************************************
 *
 **/
void Node::setNextValue(int value)
{
  this->nextValue = value;
}

/********************************************************************
 *
 **/
bool Node::equals(Node that)
{
  if (this->currentValue == that.getCurrentValue()
      && this->nextValue == that.getNextValue())
  {
    return true;
  }
  return false;
}

/********************************************************************
 * 4-7-14
 *   - It appears that this function is returning a boolean.
 - Line is originally shown as "   return (this-x = this->y)   "
 - Changed to double equals
 **/
bool Node::z()
{
  return (this->currentValue == this->nextValue);
}

/********************************************************************
 *
 **/
string Node::toString()
{
  string s = "";
  s += "(" + Utils::Format(this->getCurrentValue(), 3) + " -> ";
  s += Utils::Format(this->getNextValue(), 3) + ")";
  return s;
}
