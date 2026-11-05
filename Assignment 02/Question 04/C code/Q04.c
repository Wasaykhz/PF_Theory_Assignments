/*
Program: Bakery Festival Sales Management System
Programmer: Abdul Wasy (26K-0023)
Dept: BSAI - 1A
Course: Programming Fundamentals
Instructor: Sir Syed Farooq Zaidi
Dated: November 04, 2026
*/


#include <stdio.h>

// Asks for the number of festival days until a value from 1 to 7 is entered
int getValidDays()
{
    int days;

    printf("Enter number of festival days (1-7): ");
    scanf("%d", &days);

    while (days < 1 || days > 7)    // keep asking until valid
    {
        printf("Invalid! Enter a value between 1 and 7: ");
        scanf("%d", &days);
    }
    return days;
}

// Inputs the orders of one day, displays its summary and returns the day's total
float calculateDailySales(int dayNumber)
{
    int orders, i;
    float amount;
    float total = 0;
    float highest = 0;
    float average;

    printf("\nDay %d - Number of orders: ", dayNumber);
    scanf("%d", &orders);

    while (orders < 1)              // at least one order is expected
    {
        printf("Invalid! Enter at least 1 order: ");
        scanf("%d", &orders);
    }

    for (i = 1; i <= orders; i++)
    {
        printf("  Order %d amount (Rs.): ", i);
        scanf("%f", &amount);

        while (amount <= 0)         // ask again for the SAME order
        {
            printf("  Invalid! Amount must be greater than 0. Re-enter order %d: ", i);
            scanf("%f", &amount);
        }

        total = total + amount;
        if (amount > highest)       // track the highest order
            highest = amount;
    }

    average = total / orders;

    printf("\nTotal sales: Rs. %.2f\n", total);
    printf("Average order: Rs. %.2f\n", average);
    printf("Highest order: Rs. %.2f\n", highest);

    return total;
}

// Returns the day number (starting from 1) with the highest sales
int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    int i;
    int bestDay = 1;                // assume day 1 is highest

    for (i = 1; i < numberOfDays; i++)
    {
        if (dailySales[i] > dailySales[bestDay - 1])   // strictly greater keeps the earliest day on ties
        {
            bestDay = i + 1;
        }
    }
    return bestDay;
}

// Prints one * for every complete Rs. 100 of each day's sales
void displayBarChart(float dailySales[], int numberOfDays)
{
    int i, j;
    int stars;

    printf("\n===== DAILY SALES BAR CHART =====\n");
    for (i = 0; i < numberOfDays; i++)
    {
        stars = (int)(dailySales[i] / 100);   // dropping the decimal ignores the amount below 100

        printf("Day %d: ", i + 1);
        for (j = 0; j < stars; j++)
        {
            printf("*");
        }
        printf(" (Rs. %.2f)\n", dailySales[i]);
    }
}

int main()
{
    float dailySales[7];            // total sales of each day
    int days, i;
    int bestDay;
    float festivalTotal = 0;

    days = getValidDays();

    for (i = 0; i < days; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);   // store each day's total
        festivalTotal = festivalTotal + dailySales[i];
    }

    bestDay = findHighestSalesDay(dailySales, days);

    printf("\n===== FESTIVAL SUMMARY =====\n");
    printf("Total festival sales: Rs. %.2f\n", festivalTotal);
    printf("Day with highest sales: Day %d\n", bestDay);
    printf("Highest daily sales: Rs. %.2f\n", dailySales[bestDay - 1]);

    displayBarChart(dailySales, days);

    return 0;
}
