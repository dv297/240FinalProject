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
  int getParentValue();
  void setCurrentValue(int value);
  void setParentValue(int value);

  bool equals(Node that);
  bool atTop();

  string toString();

private:
  int currentValue;
  int parentValue;

};

#endif // X_H
