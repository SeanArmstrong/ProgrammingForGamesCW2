#include "Shape.h"

std::ostream& operator<<(std::ostream& outStream, const Shape& shape){
	return shape.output(outStream);
}
