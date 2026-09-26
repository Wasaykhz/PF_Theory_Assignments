/*
Program: Smart Campus Parking and Access Management System.
Programmer: Abdul Wasy (26K-0023)
Dept: BSAI - 1A
Course: Programming Fundamentals
Instructor: Sir Syed Farooq Zaidi
*/


#include <stdio.h>
#include <string.h>

int main() {
    printf("\n|********** Smart Campus Parking System **********|\n\n");

    int zone_A = 0, zone_B = 0, zone_C = 0, cap_A = 20, cap_B = 40, cap_C = 15,
    accepted = 0, rejected = 0, cars = 0, bikes = 0, vans = 0, t_Cap, t_Occ, 
    n, i = 0, valid, assigned;
    char vehicleType, Category, Permit, Emergency;
    char reason[200];

    printf("Enter no of Vehicles: ");
    scanf("%d",&n);

    for (i; i < n; i++)
    {
        valid = 0;      // 0 for False, 1 for true
        assigned = 0;   // 0 for False, 1 for true
        strcpy(reason, "");

        while (valid == 0)
        {
            printf("Enter Vehicle Type(C = Cars, B = Bikes, V = Van): ");
            scanf(" %c",&vehicleType);
            printf("Enter Category(F = Faculty, S = Students, G = Visitors/Guests): ");
            scanf(" %c",&Category);
            printf("Do you have Permit (Y for Yes, N for No): ");
            scanf(" %c",&Permit);

            if (vehicleType == 'C' || vehicleType == 'B' || vehicleType == 'V')
            {
                if (Category == 'F' || Category == 'S' || Category == 'G')
                {
                    if (Permit == 'Y' || Permit == 'N')
                    valid = 1;
                    else
                    printf("\nInvalid Permit Input. Enter Y or N\n");
                }
                else
                {
                    printf("\nInvalid Category Input. Enter F,S or G\n");
                }  
            }
            else
            {
                printf("\nInvalid Vehicle Type. Enter C,B or V\n");
            }
        }

        if (Permit == 'N')
        {
            printf("Do you have an emergency? Enter Y or N: ");
            scanf(" %c", &Emergency);
            while (Emergency != 'Y' && Emergency != 'N')
            {
                printf("\nInvalid Emergency Input.\nEnter Y or N: ");
                scanf(" %c", &Emergency);
            }
            
        }
        else
        Emergency = 'N';
        
        if (Permit == 'N' && Emergency == 'N')
        {
            strcpy(reason, "Invalid Permit\n");
        }
        else
        {
            if (Category == 'F')
            {
                if (vehicleType == 'V')
                {
                    if ((zone_A + 2) <= cap_A)
                    {
                        zone_A += 2;
                        assigned = 1;   // 1 for True and 0 for False
                    }
                    else
                    {
                        strcpy(reason, "No Available Space\n");
                    }
                }
                else
                {
                    if ((zone_A + 1) <= cap_A)
                    {
                        zone_A += 1;
                        assigned = 1;   // 1 for True and 0 for False
                    }
                    else
                    {
                        strcpy(reason, "No Available Space\n");
                    }
                }
            }
            else if (Category == 'S')
            {
                if (vehicleType == 'V')
                {
                    if ((zone_C + 2) <= cap_C)
                    {
                        zone_C += 2;
                        assigned = 1;   // 1 for True and 0 for False
                    }
                    else
                    {
                        strcpy(reason, "No Available Space in Zone C\n");
                    }
                }
                else
                {
                    if ((zone_B + 1) <= cap_B)
                    {
                        zone_B += 1;
                        assigned = 1;   // 1 for True and 0 for False
                    }
                    else
                    {
                        strcpy(reason, "No Available Space in Zone B\n");
                    }
                    
                }
            }
            else if (Category == 'G')
            {
                if (vehicleType == 'V')
                {
                    if ((zone_C + 2) <= cap_C)
                    {
                        zone_C += 2;
                        assigned = 1;   // 1 for True and 0 for False
                    }
                    else
                    {
                        strcpy(reason, "No Available Space in Zone C\n");
                    }
                }
                else
                {
                    if ((zone_C + 1) <= cap_C)
                    {
                        zone_C += 1;
                        assigned = 1;   // 1 for True and 0 for False
                    }
                    else
                    {
                        strcpy(reason, "No Available Space in Zone C\n");
                    }
                }
            }
        }

        if (assigned == 1)  //If Assigned is true
        {
            accepted += 1;
            if (vehicleType == 'C')
            {
                cars += 1;
            }
            else if (vehicleType == 'B')
            {
                bikes += 1;
            }
            else
            {
                vans += 1;
            }

            if (Category == 'F')
            {
            printf("\nVehicle Assigned to Zone A\n");
            printf("Remaining Capacity: %d\n", cap_A - zone_A);
            }
            else if (Category == 'S')
            {
                if (vehicleType == 'V')
                {
                    printf("\nVehicle Assigned to Zone C");
                    printf("\nRemaining Capacity: %d\n", cap_C - zone_C);
                }
                else
                {
                    printf("\nVehicle Assigned to Zone B");
                    printf("\nRemaining Capacity: %d\n", cap_B - zone_B);
                }
            }
            
            else
            {
            printf("\nVehicle Assigned to Zone C");
            printf("\nRemaining Capacity: %d\n", cap_C - zone_C);
            }
        }
        else
        {
            rejected += 1;
            printf("\nVehicle rejected: %s\n",reason);
        }
        if (i<n-1)
        {
            printf("\n\nEnter details for next vehicle\n\n");
        }
        
    }
    t_Occ = zone_A + zone_B + zone_C;   //Total Occupancy
    t_Cap = cap_A + cap_B + cap_C;      //Total Capacity
    
    printf("\n\n|********** Parking Summary **********|\n\n");
    printf("Total Vehicles Processed: %d\n", n);
    printf("Total Accepted Vehicles: %d\n", accepted);
    printf("Total Rejected Vehicles: %d\n", rejected);
    printf("Successfully Parked Cars: %d\n", cars);
    printf("Successfully Parked Bikes: %d\n", bikes);
    printf("Successfully Parked Vans: %d\n", vans);
    printf("Zone A Occupancy: %d/%d\n", zone_A, cap_A);
    printf("Zone A Remaining Capacity: %d\n", cap_A - zone_A);
    printf("Zone B Occupancy: %d/%d\n", zone_B, cap_B);
    printf("Zone B Remaining Capacity: %d\n", cap_B - zone_B);
    printf("Zone C Occupancy: %d/%d\n", zone_C, cap_C);
    printf("Zone C Remaining Capacity: %d\n", cap_C - zone_C);

    if (zone_A > zone_B && zone_A > zone_C)
    {
        printf("Zone A has the highest occupancy\n");
    }
    else if (zone_B > zone_A && zone_B > zone_C)
    {
        printf("Zone B has the highest occupancy\n");
    }
    else if (zone_C > zone_A && zone_C > zone_B)
    {
        printf("Zone C has the highest occupancy\n");
    }
    else
    {
        printf("All zones have equal occupancy\n");
    }

    if (t_Occ == t_Cap)
    {
        printf("Campus Parking Facility is Full\n");
    }
    else
    {
        printf("Campus Parking Facility is not Full\n");
    }
    return 0;
}
