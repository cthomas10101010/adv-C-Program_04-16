#include "CalculateDiscount.h"

//-----------------------------------------------------
// Function Name: calculateDiscount
// Purpose      : Calculate discounted price 
//-----------------------------------------------------
void calculateDiscount(double listPrice, double discountPercentage, double& discountedPrice)
{
    discountedPrice = listPrice - (listPrice * (discountPercentage / 100.0));
}
