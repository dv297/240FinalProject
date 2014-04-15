#ifndef X_H
#define X_H

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"

#define DUMMYX -1
#define DUMMYY -2

class Node
{
public:
  Node();
  Node(int x, int y);
  virtual ~Node();

  int getCurrentValue();
  int getNextValue();
  void setCurrentValue(int value);
  void setNextValue(int value);

  bool equals(Node that);
  bool atTop();

  string toString();

private:
  int currentValue;
  int nextValue;

};

#endif // X_H
