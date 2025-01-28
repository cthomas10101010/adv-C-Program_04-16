#include "Part2.h"
#include "ParallelVectors.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

static const int MAX_KINGDOMS = 50;

void runPart2()
{
    cout << "-------------------------------" << endl;
    cout << "         PART 2                " << endl;
    cout << " (Kingdoms & Armies) - Two     " << endl;
    cout << "   Parallel Template Vectors   " << endl;
    cout << "-------------------------------" << endl;

    ParallelVectors<string, int> kingdomsAndArmies;

    while (true)
    {
        if (kingdomsAndArmies.size() >= MAX_KINGDOMS)
        {
            cout << "Maximum kingdom limit reached!" << endl;
            break;
        }

        cout << "Would you like to enter a kingdom? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 'n' || choice == 'N')
        {
            break;
        }
        else if (choice == 'y' || choice == 'Y')
        {
            cout << "Enter the name of the Kingdom: ";
            string kingdomName;
            getline(cin, kingdomName);

            cout << "Enter the size of the army for " << kingdomName << ": ";
            int armySize;
            cin >> armySize;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (armySize < 0)
            {
                cout << "Army size cannot be negative. Setting to 0." << endl;
                armySize = 0;
            }

            kingdomsAndArmies.addPair(kingdomName, armySize);
        }
        else
        {
            cout << "Invalid input. Please type 'y' or 'n'." << endl;
        }
    }

    cout << "\nYou entered the following Kingdoms and their Army sizes:\n" << endl;

    for (size_t i = 0; i < kingdomsAndArmies.size(); ++i)
    {
        cout << "Kingdom: " << kingdomsAndArmies.getFirstAt(i)
             << ", Army Size: " << kingdomsAndArmies.getSecondAt(i) << endl;
    }
    cout << endl;
}