#ifndef SHEDWAKE_H
#define SHEDWAKE_H

#include "Component.h"
#include <vector>

// Note: This function will directly modify the component at the current step of the history passed in
void shedWake(std::vector<Component>& history, int step);

#endif