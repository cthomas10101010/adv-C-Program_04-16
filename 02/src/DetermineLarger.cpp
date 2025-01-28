#include "determineLarger.h"

// determineLarger
// Parameters:
//   intOne   - first integer
//   intTwo   - second integer
//   pLarger  - pointer to an int in which we store the larger value
void determineLarger(int intOne, int intTwo, int *pLarger)
{
    if (intOne > intTwo)
    {
        *pLarger = intOne;
    }
    else
    {
        *pLarger = intTwo;
    }
}
