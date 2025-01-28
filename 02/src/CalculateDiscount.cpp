#include "calculateDiscount.h"

// calculateDiscount
// Parameters:
//   listPrice        - original price (e.g., 100.00)
//   discountPercent  - discount percentage (e.g., 20 means 20%)
//   discountedPrice  - reference parameter used to store the calculated discounted price
void calculateDiscount(double listPrice, double discountPercent, double &discountedPrice)
{
    // Ensure discountPercent is in the correct range, but that
    // is optional – or you may assume user provides correct input.
    // Basic formula: discountedPrice = listPrice - (listPrice * discountPercent / 100)
    discountedPrice = listPrice - (listPrice * discountPercent / 100.0);
}
