/*******************************************************************************
* Cuyamaca College CS-281
* File name: Helicopter.h
* Description: Declaration of the Helicopter class.
* Developer: Andrew Gulla
*******************************************************************************/

#ifndef HELICOPTER_H
#define HELICOPTER_H

class Helicopter
{
private:
    int altitude;
    int distanceFlown;

public:
    // constructor
    Helicopter();

    // transformer (mutator) functions
    void ascend();
    bool descend();      // returns false if crash
    void forward();
    void land();

    // observer (getter) functions
    int getAltitude() const;
    int getDistanceFlown() const;
};

#endif
