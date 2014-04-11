#ifndef X_H
#define X_H

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"

#define DUMMYX -1
#define DUMMYY -2

class XX
{
public:
  XX();
  virtual ~XX();

  int getX();
  int getY();
  void setX(int value);
  void setY(int value);

  bool equals(XX that);
  bool z();

  string toString();

private:
  int x;
  int y;

};

#endif // X_H
