/*******************************************************************************
* Cuyamaca College CS-281
* File name: Helicopter.cpp
* Description: Definition of the Helicopter class member functions.
* Developer: Andrew Gulla
*******************************************************************************/

#include "Helicopter.h"

// constructor
Helicopter::Helicopter()
{
    altitude = 0;
    distanceFlown = 0;
}

void Helicopter::ascend()
{
    altitude += 100;
}

bool Helicopter::descend()
{
    altitude -= 51;

    if (altitude < 0)
    {
        altitude = 0;
        return false;   // crash
    }

    return true;
}

void Helicopter::forward()
{
    distanceFlown += 200;
}

void Helicopter::land()
{
    altitude = 0;
    distanceFlown = 0;
}

int Helicopter::getAltitude() const
{
    return altitude;
}

int Helicopter::getDistanceFlown() const
{
    return distanceFlown;
}
