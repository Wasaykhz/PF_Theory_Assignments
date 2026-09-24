#include<stdio.h>
int main(){
    int cF = 0, i = 1, rF, n;
    printf("\n***** Elevator Simulation *****\n\n");
    printf("Enter a number: ");
    scanf("%d", &n);

    for(i; i<=n; i++){
        printf("Enter Floor: ");
        scanf("%d", &rF);
        
        if(rF > cF)
        printf("Moving Up!!\n");
        
        else if(rF < cF)
        printf("Moving Down!!\n");

        else
        printf("Doors Opening!!\n");

        cF = rF;
    }
    return 0;
}
