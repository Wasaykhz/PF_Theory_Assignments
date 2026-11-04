/*
Program: Cinema Hall Seat Booking Management System
Programmer: Abdul Wasy (26K-0023)
Dept: BSAI - 1A
Course: Programming Fundamentals
Instructor: Sir Syed Farooq Zaidi
Dated: October 27, 2026
*/

#include <stdio.h>

int main()
{
    int seats[50][50];          // 2D array: 0 = available, 1 = booked
    int rows, cols;             // number of rows and seats per row
    int i, j;                   // loop variables
    int rowFree;                // free seats in one row
    int totalFree = 0;          // free seats in the whole hall
    int k;                      // group size
    int mid;                    // middle row
    int d;                      // distance from the middle row
    int t;                      // 0 = row above middle, 1 = row below middle
    int row;                    // row currently being searched
    int count;                  // consecutive free seats seen so far
    int found = 0;              // 1 when a block has been found
    int foundRow = -1;          // row of the allocated block
    int startSeat = -1;         // first seat of the allocated block

    // ---------- 1. Input seating plan ----------
    printf("Enter number of rows (1-50): ");
    scanf("%d", &rows);
    printf("Enter number of seats per row (1-50): ");
    scanf("%d", &cols);

    printf("Enter seating status (0 = available, 1 = booked):\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &seats[i][j]);
        }
    }

    // ---------- 3. Availability report (counted first, printed with the result) ----------
    printf("\nFree seats per row: ");
    for (i = 0; i < rows; i++)
    {
        rowFree = 0;
        for (j = 0; j < cols; j++)
        {
            if (seats[i][j] == 0)   // seat is available
            {
                rowFree++;
            }
        }
        printf("%d ", rowFree);
        totalFree = totalFree + rowFree;
    }
    printf("  Total free: %d\n", totalFree);

    // ---------- 2. Display the seating arrangement ----------
    printf("\nCurrent seating plan:\n    ");
    for (j = 0; j < cols; j++)
    {
        printf("%d ", j);           // seat numbers start from 0
    }
    printf("\n");
    for (i = 0; i < rows; i++)
    {
        printf("R%-2d ", i);        // row numbers start from 0
        for (j = 0; j < cols; j++)
        {
            if (seats[i][j] == 0)
                printf("_ ");
            else
                printf("X ");
        }
        printf("\n");
    }

    // ---------- 4. Group booking input with validation ----------
    printf("\nEnter number of customers (k): ");
    scanf("%d", &k);
    if (k <= 0 || k > cols)
    {
        printf("Invalid group size! It must be between 1 and %d.\n", cols);
        return 0;                   // stop, nothing is changed
    }

    // ---------- 5. Search rows starting from the middle ----------
    mid = rows / 2;                 // integer division
    for (d = 0; d < rows && found == 0; d++)
    {
        for (t = 0; t < 2 && found == 0; t++)
        {
            if (t == 0)
                row = mid - d;      // smaller row number is searched first
            else
                row = mid + d;

            if (t == 1 && d == 0)
                continue;           // the middle row is already checked
            if (row < 0 || row >= rows)
                continue;           // row does not exist

            // count consecutive free seats in this row
            count = 0;
            for (j = 0; j < cols; j++)
            {
                if (seats[row][j] == 0)
                {
                    count++;
                }
                else
                {
                    count = 0;      // booked seat breaks the block
                }

                if (count == k)     // block of k free seats found
                {
                    found = 1;
                    foundRow = row;
                    startSeat = j - k + 1;
                    break;          // first block in the row is enough
                }
            }
        }
    }

    // ---------- 6 and 7. Confirm booking or show failure message ----------
    if (found == 1)
    {
        for (j = startSeat; j < startSeat + k; j++)
        {
            seats[foundRow][j] = 1; // mark seats as booked
        }
        totalFree = totalFree - k;

        printf("\nGroup of %d seated in Row %d, Seats %d to %d\n",
               k, foundRow, startSeat, startSeat + k - 1);

        printf("\nUpdated seating plan:\n    ");
        for (j = 0; j < cols; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
        for (i = 0; i < rows; i++)
        {
            printf("R%-2d ", i);
            for (j = 0; j < cols; j++)
            {
                if (seats[i][j] == 0)
                    printf("_ ");
                else
                    printf("X ");
            }
            printf("\n");
        }
        printf("\nRemaining available seats: %d\n", totalFree);
    }
    else
    {
        printf("\nSorry, no row has %d consecutive available seats.\n", k);
        printf("Seating plan unchanged.\n");
    }

    return 0;
}
