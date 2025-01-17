#include "DetermineLarger.h"

void determineLarger(int intOne, int intTwo, int* larger)
{
    if (intOne > intTwo)
        *larger = intOne;
    else
        *larger = intTwo;
}