 

#include "Shape.h"
#include <cstring>
using namespace std;
namespace sdds {
	istream& operator>>(istream& left, Shape& obj)
	{
		obj.getSpecs(left);
		return left;
	}
	ostream& operator<<(ostream& left, const Shape& obj)
	{
		obj.draw(left);
		return left;
	}
}