#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() 
{
    printf("\n***** Class Result Processing *****\n\n");
    int n, m1, m2, m3, m4, m5;
    float avg;
    char result[30] = {};

    printf("Enter Subject 01 Marks: ");
    scanf("%d", &m1);
    printf("Enter Subject 02 Marks: ");
    scanf("%d", &m2);
    printf("Enter Subject 03 Marks: ");
    scanf("%d", &m3);
    printf("Enter Subject 04 Marks: ");
    scanf("%d", &m4);
    printf("Enter Subject 05 Marks: ");
    scanf("%d", &m5);

    if( m1 < 0 || m2 < 0 || m3 < 0 || m4 < 0 || m5 < 0 || m1 > 100 || m2 > 100 || m3 > 100 || m4 > 100 || m5 > 100)
    {
        printf("Invalid marks. Marks must be between 0 and 100.");
        exit(0);
    }
    

    avg = (m1 + m2 + m3 + m4 + m5)/5.0;

    if(m1 < 33 || m2 < 33 || m3 < 33 || m4 < 33 || m5 < 33)
    strcpy(result, "Fail - Subject Deficiency");

    else if(avg >= 80)
    strcpy(result, "Distinction");

    else if(avg >= 60)
    strcpy(result, "Pass");

    else if(avg < 60)
    strcpy(result, "Fail");

    printf("\nAverage: %.2f",avg);
    printf("\nResult: %s\n",result);
    return 0;
}
