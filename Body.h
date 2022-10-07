#ifndef BODY_H
#define BODY_H

#include "Component.h"
#include <vector>

struct Body
{
	std::vector<Component> components{};
};

#endif