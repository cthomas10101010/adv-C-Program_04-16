#include <iostream>
#include "Part1.h"
#include "Part2.h"

/**
 * @brief Main entry point. This function calls Part 1 and Part 2.
 */
int main()
{
    // Optionally, you can prompt the user for which part they wish to run.
    // Here both parts are run in sequence.
    runPart1();  // Handle Characters & Dragons (Part 1)
    runPart2();  // Handle Kingdoms & Armies (Part 2)

    // Program end
    return 0;
}
