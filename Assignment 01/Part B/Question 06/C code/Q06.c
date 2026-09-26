/*
Program: Smart EV Charging and Parking Management System
Programmer: Abdul Wasy (26K-0023)
Dept: BSAI - 1A
Course: Programming Fundamentals
Instructor: Sir Syed Farooq Zaidi
*/


#include <stdio.h>
#include <string.h>

int main()
{
    printf("<\n----- Smart EV Charging and Parking Management System ----->\n\n");

    char vehicleType, membership, disabledPriority, stationAvailable;
    int i, rate, currentBattery, requiredBattery, parkingDuration, currentTime,
        requiredCharging, parkingBase;

    double chargingDiscount, parkingDiscount, totalCost, parkingCost,
        totalDiscount, chargingCost, chargingBaseCost, discountedCost;

    char priority[100], status[100];

    i = 1;

    while (i)    // Taking Inputs from user
    {
        // Vehicle Type
        printf("Enter Vehicle Type (E for Electric, H for Hybrid): ");
        scanf(" %c", &vehicleType);

        while (vehicleType != 'E' && vehicleType != 'H')
        {
            printf("\nInvalid Vehicle Type.\n");
            printf("Enter Vehicle Type (E/H): ");
            scanf(" %c", &vehicleType);
        }

        // Current Battery Level
        printf("Enter Current Battery Level %%: ");
        scanf("%d", &currentBattery);

        while (currentBattery < 0 || currentBattery > 100)
        {
            printf("\nInvalid Current Battery Level %%.\n");
            printf("Enter value between 0 and 100: ");
            scanf("%d", &currentBattery);
        }

        // Required Battery Level
        printf("Enter Required Charging Level %%: ");
        scanf("%d", &requiredBattery);

        while (requiredBattery < 0 || requiredBattery > 100)
        {
            printf("\nInvalid Required Charging Level %%.\n");
            printf("Enter value between 0 and 100: ");
            scanf("%d", &requiredBattery);
        }

        // Parking Duration
        printf("Enter Parking Duration (in hours): ");
        scanf("%d", &parkingDuration);

        while (parkingDuration < 0)
        {
            printf("\nInvalid Parking Duration.\n");
            printf("Enter a non-negative value: ");
            scanf("%d", &parkingDuration);
        }

        // Current Time
        printf("Enter Current Time (in 24-hour format, e.g., 14 for 2 PM): ");
        scanf("%d", &currentTime);

        while (currentTime < 0 || currentTime > 23)
        {
            printf("\nInvalid Current Time.\n");
            printf("Enter value between 0 and 23: ");
            scanf("%d", &currentTime);
        }

        // Checking Membership
        printf("Are you a member? (Y/N): ");
        scanf(" %c", &membership);

        while (membership != 'Y' && membership != 'N')
        {
            printf("\nInvalid Membership Input.\n");
            printf("Enter (Y/N): ");
            scanf(" %c", &membership);
        }

        // Checking Disabled Priority
        printf("Do you have disabled priority? (Y/N): ");
        scanf(" %c", &disabledPriority);

        while (disabledPriority != 'Y' && disabledPriority != 'N')
        {
            printf("\nInvalid Disabled Priority Input.\n");
            printf("Enter (Y/N): ");
            scanf(" %c", &disabledPriority);
        }

        // Checking Station Availability
        printf("Is the charging station available? (Y/N): ");
        scanf(" %c", &stationAvailable);

        while (stationAvailable != 'Y' && stationAvailable != 'N')
        {
            printf("\nInvalid Station Availability Input.\n");
            printf("Enter (Y/N): ");
            scanf(" %c", &stationAvailable);
        }

        i = 0;
    }


    // Initializing Charging Values
    requiredCharging = 0;
    chargingBaseCost = 0;
    chargingDiscount = 0;
    chargingCost = 0;


    // Checking Charging Station Availability
    if (stationAvailable == 'N')
    {
        if (vehicleType == 'H')
        {
            strcpy(status, "Charging unavailable - Parking only.");
        }
        else
        {
            strcpy(status, "No charging slot available.");
        }

        strcpy(priority, "Not Applicable");
    }

    else
    {
        // Checking Hybrid Vehicle Eligibility
        if (vehicleType == 'H' && currentBattery >= 40)
        {
            strcpy(status, "Vehicle does not qualify for EV charging.");
            strcpy(priority, "Not Applicable");
        }

        else
        {
            // Checking Whether Charging is Required
            if (requiredBattery <= currentBattery)
            {
                strcpy(priority, "No charging required.");
                strcpy(status, "No Charging Required");
            }

            else
            {
                // Required Charging Calculation
                requiredCharging = requiredBattery - currentBattery;


                // Charging Priority Calculation
                if (currentBattery <= 15 && requiredBattery >= 80)
                {
                    strcpy(priority, "Emergency Charging Priority");
                }
                else if (disabledPriority == 'Y' ||
                         (membership == 'Y' && currentBattery <= 30))
                {
                    strcpy(priority, "Priority Charging");
                }
                else
                {
                    strcpy(priority, "Normal Charging");
                }


                // Peak / Off-Peak Charging Calculation
                if (currentTime < 17 || currentTime > 22)
                {
                    // Off-Peak Hours
                    strcpy(status, "Charging in Off-Peak Hours");

                    rate = 35;

                    chargingBaseCost = requiredCharging * rate;

                    // Member gets 20% discount during off-peak
                    // Emergency Priority gets no membership discount
                    if (membership == 'Y' &&
                        strcmp(priority, "Emergency Charging Priority") != 0)
                    {
                        chargingDiscount = chargingBaseCost * 0.20;
                    }
                    else
                    {
                        chargingDiscount = 0;
                    }
                }

                else
                {
                    // Peak Hours
                    strcpy(status, "Charging in Peak Hours");

                    rate = 50;

                    chargingBaseCost = requiredCharging * rate;

                    chargingDiscount = chargingBaseCost * 0.10;
                }

                // Final Charging Cost
                chargingCost = chargingBaseCost - chargingDiscount;
            }
        }
    }


    // Parking Base Cost Calculation
    if (parkingDuration <= 2)
    {
        parkingBase = 200;
    }
    else if (parkingDuration <= 5)
    {
        parkingBase = 400;
    }
    else
    {
        parkingBase = 700;
    }


    // Parking Discount Calculation
    if (disabledPriority == 'Y')
    {
        // Disabled-person priority gets free parking
        parkingDiscount = parkingBase;
    }
    else if (membership == 'Y')
    {
        // Member gets 20% parking discount
        parkingDiscount = parkingBase * 0.20;
    }
    else
    {
        parkingDiscount = 0;
    }


    // Final Parking Cost
    parkingCost = parkingBase - parkingDiscount;


    // Total Cost and Total Discount Calculation
    totalCost = chargingBaseCost + parkingBase;

    totalDiscount = chargingDiscount + parkingDiscount;

    discountedCost = totalCost - totalDiscount;


    // Parking Duration Warning
    if (parkingDuration > 8)
    {
        printf("\nLong-stay warning: Please relocate your vehicle after charging.\n");
    }
    else
    {
        printf("\nStandard parking duration.\n");
    }


    // Summary Output
    printf("\n-------- Summary --------\n");

    if (vehicleType == 'E')
    {
        printf("Vehicle Type: Electric Vehicle\n");
    }
    else
    {
        printf("Vehicle Type: Hybrid Vehicle\n");
    }

    printf("Current Battery Level: %d%%\n", currentBattery);

    printf("Required Charging Level: %d%%\n", requiredBattery);

    printf("Required Charging Amount: %d%%\n", requiredCharging);

    printf("Charging Priority: %s\n", priority);

    printf("Charging Status: %s\n\n", status);

    printf("Charging Base Cost: %.2f\n", chargingBaseCost);

    printf("Charging Discount: %.2f\n", chargingDiscount);

    printf("Charging Cost: %.2f\n\n", chargingCost);

    printf("Parking Base Cost: %.2f\n", (double)parkingBase);

    printf("Parking Discount: %.2f\n", parkingDiscount);

    printf("Parking Cost: %.2f\n\n", parkingCost);

    printf("Total Cost Before Discount: %.2f\n", totalCost);

    printf("Total Discount: %.2f\n", totalDiscount);

    printf("Final Payable Amount: %.2f\n", discountedCost);

    printf("-------------------------\n");

    return 0;
}
