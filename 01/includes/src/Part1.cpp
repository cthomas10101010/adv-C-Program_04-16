#include "Part1.h"
#include "TwoDArray.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// We'll fix maximum number of possible characters to store
static const int MAX_CHARACTERS = 50;

void runPart1()
{
    cout << "-------------------------------" << endl;
    cout << "         PART 1                " << endl;
    cout << " (Characters & Dragons) - 2D   " << endl;
    cout << "  Class Template Array         " << endl;
    cout << "-------------------------------" << endl;

    // Create 2D array of strings (row = each character, columns = their dragons)
    TwoDArray<string> charDragonArray(MAX_CHARACTERS);

    int currentRow = 0;

    while (true)
    {
        cout << "Would you like to enter a character? (y/n): ";
        char choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 'n' || choice == 'N')
        {
            break;
        }
        else if (choice == 'y' || choice == 'Y')
        {
            if (currentRow >= MAX_CHARACTERS)
            {
                cout << "Maximum character limit reached!" << endl;
                break;
            }

            cout << "Enter the character name: ";
            string characterName;
            getline(cin, characterName);

            cout << "How many dragons for " << characterName << "? ";
            int numDragons;
            cin >> numDragons;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (numDragons < 0)
            {
                cout << "Number of dragons cannot be negative. Defaulting to 0." << endl;
                numDragons = 0;
            }

            // Allocate that many columns in the row
            charDragonArray.allocateRow(currentRow, numDragons + 1);
            // Store the character name in column 0
            charDragonArray.setElement(currentRow, 0, characterName);

            for (int i = 1; i <= numDragons; ++i)
            {
                cout << "Enter name of dragon " << i << ": ";
                string dragonName;
                getline(cin, dragonName);
                charDragonArray.setElement(currentRow, i, dragonName);
            }

            currentRow++;
        }
        else
        {
            cout << "Invalid input. Please type 'y' or 'n'." << endl;
        }
    }

    // Display results
    cout << "\nYou entered the following characters and their dragons:\n" << endl;
    for (int row = 0; row < currentRow; ++row)
    {
        int cols = charDragonArray.getColsForRow(row);
        if (cols == 0) continue; // no data
        cout << "Character: " << charDragonArray.getElement(row, 0) << endl;
        if (cols > 1)
        {
            cout << "Dragons:";
            for (int col = 1; col < cols; ++col)
            {
                cout << " " << charDragonArray.getElement(row, col);
            }
            cout << endl;
        }
        cout << endl;
    }
}