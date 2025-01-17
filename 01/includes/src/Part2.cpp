#include "Part2.h"
#include "ParallelVectors.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void runPart2()
{
    cout << "-------------------------------" << endl;
    cout << "         PART 2                " << endl;
    cout << "   (Kingdoms & Armies)         " << endl;
    cout << "-------------------------------" << endl;

    // Create a parallel vectors object to store kingdom names and corresponding army sizes.
    ParallelVectors<string, int> kingdomsArmies;

    while (true)
    {
        cout << "Would you like to enter a kingdom? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer

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

            // Store the kingdom name and its army size as a pair.
            kingdomsArmies.addPair(kingdomName, armySize);
        }
        else
        {
            cout << "Invalid input. Please type 'y' or 'n'." << endl;
        }
    }

    // Output the kingdoms and their corresponding army sizes.
    cout << "\nYou entered the following Kingdoms and their Army sizes:\n" << endl;

    for (size_t i = 0; i < kingdomsArmies.size(); ++i)
    {
        cout << "Kingdom: " << kingdomsArmies.getFirstAt(i)
             << ", Army Size: " << kingdomsArmies.getSecondAt(i) << endl;
    }
    cout << endl;
}
