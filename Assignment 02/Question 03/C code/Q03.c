/*
Program: Greenhouse Temperature Monitoring System
Programmer: Abdul Wasy (26K-0023)
Dept: BSAI - 1A
Course: Programming Fundamentals
Instructor: Sir Syed Farooq Zaidi
Dated: November 03, 2026
*/


#include <stdio.h>

#define MAXH 50                     // maximum hourly readings (columns)
#define MAXS 20                     // maximum sensors (rows)

// Inputs all temperature readings into the 2D array
void inputReadings(int temp[][MAXH], int sensors, int hours)
{
    int i, j;
    for (i = 0; i < sensors; i++)
    {
        printf("Enter %d readings for Sensor %d: ", hours, i + 1);
        for (j = 0; j < hours; j++)
        {
            scanf("%d", &temp[i][j]);
        }
    }
}

// Analyzes the readings of ONE sensor; results are sent back through pointers
void analyzeSensor(int readings[], int hours, int *total, float *avg,
                   int *max, int *min, int *critical, int *warning, int *streak)
{
    int j;
    int current = 0;                // current run of readings >= 35

    *total = 0;
    *max = readings[0];             // start with the first reading
    *min = readings[0];
    *critical = 0;
    *warning = 0;
    *streak = 0;

    for (j = 0; j < hours; j++)
    {
        *total = *total + readings[j];

        if (readings[j] > *max)
            *max = readings[j];
        if (readings[j] < *min)
            *min = readings[j];

        if (readings[j] >= 40)      // critical reading
            (*critical)++;
        else if (readings[j] >= 35) // warning reading (35 to 39)
            (*warning)++;

        if (readings[j] >= 35)      // hot hour: extend the streak
        {
            current++;
            if (current > *streak)
                *streak = current;
        }
        else
        {
            current = 0;            // reading below 35 ends the streak
        }
    }

    *avg = (float)*total / hours;   // cast so the division keeps decimals
}

// Returns the sensor number (starting from 1) with the highest average
int highestAverageSensor(int temp[][MAXH], int sensors, int hours)
{
    int i, j;
    int sum;
    float avg;
    float bestAvg = -1000;          // lower than any possible average
    int bestSensor = 1;

    for (i = 0; i < sensors; i++)
    {
        sum = 0;
        for (j = 0; j < hours; j++)
        {
            sum = sum + temp[i][j];
        }
        avg = (float)sum / hours;

        if (avg > bestAvg)          // strictly greater keeps the first one on ties
        {
            bestAvg = avg;
            bestSensor = i + 1;
        }
    }
    return bestSensor;
}

int main()
{
    int temp[MAXS][MAXH];           // rows = sensors, columns = hours
    int sensors, hours;
    int i;
    int total, max, min, critical, warning, streak;
    float avg;
    int best;

    printf("Enter number of sensors: ");
    scanf("%d", &sensors);
    printf("Enter number of hourly readings: ");
    scanf("%d", &hours);

    inputReadings(temp, sensors, hours);

    printf("\n");
    for (i = 0; i < sensors; i++)
    {
        // pass only the row of this sensor (temp[i]) to the function
        analyzeSensor(temp[i], hours, &total, &avg, &max, &min,
                      &critical, &warning, &streak);

        printf("Sensor %d: Total=%d | Avg=%.2f | Max=%d | Min=%d | ",
               i + 1, total, avg, max, min);
        printf("Critical=%d | Warning=%d | Longest hot streak=%d\n",
               critical, warning, streak);
    }

    best = highestAverageSensor(temp, sensors, hours);

    // calculate the average of the best sensor again for the final report
    total = 0;
    for (i = 0; i < hours; i++)
    {
        total = total + temp[best - 1][i];
    }
    avg = (float)total / hours;

    printf("\nHighest average: Sensor %d (%.2f)\n", best, avg);

    return 0;
}
