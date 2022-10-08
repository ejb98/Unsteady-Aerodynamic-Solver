#include "Component.h"
#include "Ring.h"
#include "Velocity.h"
#include "Position.h"
#include <vector>
#include <cassert>

// Note: This function will directly modify the collocation point velocities for every step of the history
void calculateVelocities(std::vector<Component>& history, const std::vector<double>& time)
{
    assert(history.size() == time.size() && "calculateVelocities failed, history and time must be the same size");

    int numberOfTimeSteps{ static_cast<int>(time.size()) };
    double deltaTime{ time[1] - time[0] };

    std::vector<std::vector<Ring>> boundRingsHistory(numberOfTimeSteps);

    for (int step{ 0 }; step < numberOfTimeSteps; ++step)
    {
        boundRingsHistory[step] = history[step].surface.getRings();
    }

    for (int step{ 0 }; step < numberOfTimeSteps; ++step)
    {
        for (int index{ 0 }; index < boundRingsHistory[0].size(); ++index)
        {
            Velocity velocity{};
            Position currentPosition{ boundRingsHistory[step][index].getCollocationPoint().position };

            // If we are considering the last step...
            if (step == numberOfTimeSteps - 1)
            {
                Position onePositionPrevious{ boundRingsHistory[step - 1][index].getCollocationPoint().position };
                Position twoPositionsPrevious{ boundRingsHistory[step - 2][index].getCollocationPoint().position };

                // Backward differences method
                velocity.x = (3.0 * currentPosition.x - 4.0 * onePositionPrevious.x + twoPositionsPrevious.x) /
                    (2.0 * deltaTime);

                velocity.y = (3.0 * currentPosition.y - 4.0 * onePositionPrevious.y + twoPositionsPrevious.y) /
                    (2.0 * deltaTime);

                velocity.z = (3.0 * currentPosition.z - 4.0 * onePositionPrevious.z + twoPositionsPrevious.z) /
                    (2.0 * deltaTime);

            }
            // or we are considering any other step besides the first one (velocity already set to zero)...
            else if (step != 0)
            {
                Position onePositionPrevious{ boundRingsHistory[step - 1][index].getCollocationPoint().position };
                Position onePositionAfter{ boundRingsHistory[step + 1][index].getCollocationPoint().position };

                // Central differences method
                for (int component{ 0 }; component < 3; ++component)
                {
                    velocity.x = (onePositionAfter.x - onePositionPrevious.x) / (2.0 * deltaTime);
                    velocity.y = (onePositionAfter.y - onePositionPrevious.y) / (2.0 * deltaTime);
                    velocity.z = (onePositionAfter.z - onePositionPrevious.z) / (2.0 * deltaTime);
                }
            }

            // At this point the velocity for the collocation point in the current ring
            // in the group of rings in the current time step has been calculated. Now
            // we need to apply this velocity to the collocation point.

            Point newCollocationPoint{ boundRingsHistory[step][index].getCollocationPoint() };
            newCollocationPoint.velocity = velocity;

            // The position remains the same, the only member updated in the point is the velocity
            boundRingsHistory[step][index].setCollocationPoint(newCollocationPoint);
        }
    }

    for (int step{ 0 }; step < numberOfTimeSteps; ++step)
    {
        history[step].surface.setRings(boundRingsHistory[step]);
    }
}