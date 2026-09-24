#include <stdio.h>
int main()
{
    int noOfGuests, roomType, season, tP, duration, i = 1, rate = 0;
    float discount = 0.15,  revenue = 0.0, dP = 0, fP;

    printf("\n******** Hotel Booking System ********\n\n");
    printf("Enter no of guests: ");
    scanf("%d", &noOfGuests);

    while (i<= noOfGuests)
    {
        printf("\n1. Peak \n2. Off-Peak \nEnter season(1/2): ");
        scanf("%d", &season);
        printf("\n1. Standard \n2. Deluxe \n3. Suite \nEnter Room type: ");
        scanf("%d", &roomType);
        printf("\nEnter Stay Duration: ");
        scanf("%d", &duration);
        switch (season)
        {
        case 1:
            switch (roomType)
            {
            case 1:
                rate = 5000;
                break;
            
            case 2:
                rate = 8000;
                break;
            
            case 3:
                rate = 12000;
                break;
            
            default:
                printf("Invalid Input. Enter 1 or 2 or 3.");
                break;
            }
            break;
        
        case 2:
            switch (roomType)
            {
            case 1:
                rate = 3000;
                break;
            
            case 2:
                rate = 5000;
                break;
            
            case 3:
                rate = 8000;
                break;
            
            default:
                printf("Invalid Input. Enter 1 or 2 or 3.");
                break;
            }
            break;
        
        default:
            printf("Invalid Input. Enter 1 or 2.");
            break;
        }
    
        tP = duration * rate;   // Total Price

        if(duration > 7)
        dP = tP*discount;   // Discounted Price

        fP = tP - dP;       // Final Price after Discount

        printf("\nTotal Price(Rs): %d",tP);
        printf("\nDiscount(Rs): %.2f",dP);
        printf("\nFinal Amount(Rs): %.2f\n",fP);
        revenue += fP;
        
        if(i<noOfGuests)
        printf("\nEnter Details for Another Guest.\n");

        i++;
    }
    
    printf("\nTotal Revenue: %.2f",revenue);
    return 0;
}
