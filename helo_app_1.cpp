/*******************************************************************************
* Cuyamaca College CS-281
* File name: helo_app_1.cpp
* Description: Application that flies a Helicopter object.
* Developer: Andrew Gulla
*******************************************************************************/

#include <iostream>
#include <cctype>
#include "Helicopter.h"

using std::cin;
using std::cout;

void displayStatus(const Helicopter& helo)
{
    cout << "\nAltitude: " << helo.getAltitude() << " ft";
    cout << " | Distance Flown: " << helo.getDistanceFlown() << " ft\n";
}

void cmdAscend(Helicopter& helo)
{
    helo.ascend();
    cout << "\nRotor power up! Ascending 100 ft.";
    displayStatus(helo);
}

bool cmdDescend(Helicopter& helo)
{
    bool safe = helo.descend();

    if (!safe)
    {
        cout << "\nCRASH! You slammed into the terrain.";
        cout << "\nMission failed.";
        cout << "\nDistance flown: " << helo.getDistanceFlown() << " ft\n";
        return false;
    }

    cout << "\nDescending 51 ft.";
    displayStatus(helo);
    return true;
}

void cmdForward(Helicopter& helo)
{
    helo.forward();
    cout << "\nAdvancing 200 ft toward objective.";
    displayStatus(helo);
}

void cmdLand(Helicopter& helo)
{
    cout << "\nLanding sequence initiated...";
    cout << "\nSafe touchdown.";
    cout << "\nTotal distance flown: " << helo.getDistanceFlown() << " ft\n";

    helo.land();
    displayStatus(helo);
}

int main()
{
    Helicopter helo;
    char command;

    cout << "Welcome, pilot.\n";
    cout << "Aircraft: Mi-8 Tactical Transport\n";
    cout << "Mission: Black Ops insertion beyond enemy lines.\n";
    cout << "Commands: A=Ascend, D=Descend, F=Forward, V=Land, Q=Quit\n";

    bool flying = true;

    while (flying)
    {
        cout << "\nEnter command: ";
        cin >> command;

        command = static_cast<char>(std::toupper(command));

        switch (command)
        {
        case 'A':
            cmdAscend(helo);
            break;

        case 'D':
            flying = cmdDescend(helo);
            break;

        case 'F':
            cmdForward(helo);
            break;

        case 'V':
            cmdLand(helo);
            break;

        case 'Q':
            if (helo.getAltitude() > 0)
            {
                cout << "\nYou abandoned the aircraft mid-air.";
                cout << "\nCRASH! Mission failed.";
                cout << "\nDistance flown: " << helo.getDistanceFlown() << " ft\n";
            }
            else
            {
                cout << "\nMission aborted safely on ground.\n";
            }
            flying = false;
            break;

        default:
            cout << "\nInvalid command.";
        }
    }

    return 0;
}
