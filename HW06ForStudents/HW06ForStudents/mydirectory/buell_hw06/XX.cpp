#include "XX.h"

static const string TAG = "ZORK: ";

XX::XX()
{
this->x = DUMMYX;
this->y = DUMMYY;
}

XX::~XX()
{
}

int XX::getX()
{
return this->x;
}

int XX::getY()
{
return this->y;
}

void XX::setX(int value)
{
this->x = value;
}

void XX::setY(int value)
{
this->y = value;
}

bool XX::equals(XX that)
{
if((this->x == that.getX()) &&
(this->y == that.getY()))
{
return true;
}

return false;
}

bool XX::z()
{
return (this->x = this->y);
}

string XX::toString()
{
string s = "";
s += "(" + Utils::Format(this->getX(), 3) + " -> ";
s += Utils::Format(this->getY(), 3) + ")";
return s;
}
