#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int Sec){
    int MilliSec = 1000*Sec;
    int StartTime = clock();
    while(clock() < StartTime + MilliSec);
}

int main()
{
    int StartNum;
    printf("Choose a number to count down from:");
    scanf("%d",&StartNum);
    for(; StartNum > 0; StartNum--){
        printf("%d\n",StartNum);
        delay(1);
    }
    printf("Blast off to the moon!");
    return 0;
}
