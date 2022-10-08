#ifndef CALCULATEVELOCITIES_H
#define CALCULATEVELOCITIES_H

#include "Component.h"
#include <vector>

// Note: This function will directly modify the collocation point velocities for every step of the history
void calculateVelocities(std::vector<Component>& history, const std::vector<double>& time);

#endif
