#include "Part1.h"
#include "TwoDArray.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void runPart1()
{
    cout << "-------------------------------" << endl;
    cout << "         PART 1                " << endl;
    cout << "  (Characters & Dragons)       " << endl;
    cout << "-------------------------------" << endl;

    const int MAX_CHARACTERS = 50;
    TwoDArray<string> characterDragonArray(MAX_CHARACTERS);
    int currentRow = 0;

    while (true)
    {
        cout << "Would you like to enter a character? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 'n' || choice == 'N')
        {
            break;
        }
        else if (choice == 'y' || choice == 'Y')
        {
            cout << "Enter the character name: ";
            string characterName;
            getline(cin, characterName);

            cout << "How many dragons would you like to enter for " << characterName << "? ";
            int numDragons;
            cin >> numDragons;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (numDragons < 0)
            {
                cout << "Number of dragons cannot be negative. Setting to 0." << endl;
                numDragons = 0;
            }

            // Allocate columns: column 0 for the character name and subsequent columns for each dragon name.
            characterDragonArray.allocateRow(currentRow, numDragons + 1);
            characterDragonArray.setElement(currentRow, 0, characterName);

            // Use nested loop: inner loop records dragon names.
            for (int i = 0; i < numDragons; ++i)
            {
                cout << "Enter the name of dragon " << (i + 1) << ": ";
                string dragonName;
                getline(cin, dragonName);
                characterDragonArray.setElement(currentRow, i + 1, dragonName);
            }

            currentRow++;
            if (currentRow >= MAX_CHARACTERS)
            {
                cout << "Maximum character limit reached!" << endl;
                break;
            }
        }
        else
        {
            cout << "Invalid input. Please type 'y' or 'n'." << endl;
        }
    }

    // Output the data entered by the user.
    cout << "\nYou entered the following characters and their dragons:\n" << endl;
    for (int row = 0; row < currentRow; ++row)
    {
        string charName = characterDragonArray.getElement(row, 0);
        int cols = characterDragonArray.getColsForRow(row);

        cout << "Character: " << charName << endl;
        cout << "Dragons:";
        // Starting at col 1 since col 0 holds the character name.
        for (int col = 1; col < cols; ++col)
        {
            cout << " " << characterDragonArray.getElement(row, col);
        }
        cout << "\n" << endl;
    }
}
