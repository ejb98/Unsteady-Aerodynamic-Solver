#include "Vector.h"
#include "dot.h"
#include "cross.h"
#include <iostream>

int main()
{
	Vector v1{ 1.0, 2.0, 3.0 };
	Vector v2{ 4.0, 5.0, 6.0 };

	double dotProduct{ dot(v1, v2) };
	Vector crossProduct{ cross(v1, v2) };

	std::cout << "The dot product is: " << dotProduct << '\n';
	std::cout << "The cross product is: [" << crossProduct.x << ", "
										   << crossProduct.y << ", "
										   << crossProduct.z << "]\n";

	return 0;
}