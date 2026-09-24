#include <stdio.h>
#include <stdlib.h>
int main() 
{
    printf("\n***** Online shopping Bill Calculator *****\n\n");
    int q, p ,sT;   // Products Quantity, Price, SubTotal
    float d, t, dA, fA;  // Discount, Tax, Discounted Amount, Final Amount

    printf("Enter Product Quantity: ");
    scanf("%d",&q);
    printf("Enter Product Price: ");
    scanf("%d",&p);
    printf("Enter Discount %%: ");
    scanf("%f",&d);
    printf("Enter Tax %%: ");
    scanf("%f",&t);

    if (q < 0 || p < 0 || d < 0 || t < 0 || d > 100 || t > 100)
    {
        printf("Invalid Input. Quantity and price cannot be negative, and discount and tax must be between 0%% and 100%%.");
        exit(0);
    }

    sT = q*p;
    dA = sT - (sT*d)/100;
    fA = dA + (dA*t)/100;

     // Bill
    printf("\n\n************ SHOPPING BILL ************\n");
    printf("Product Quantity : %d\n", q);
    printf("Price per Item   : %d\n", p);
    printf("Subtotal         : %d\n", sT);
    printf("Discount         : %.2f %%\n", d);
    printf("Discounted Amount: %.2f\n", dA);
    printf("Tax              : %.2f %%\n", t);
    printf("Final Bill       : %.2f\n", fA);
    printf("***************************************\n");

    return 0;
}
