#include <stdio.h>

int main() {
    int hours,minute;

    scanf("%02d:%02d",&hours,&minute);

    if(hours==00)
        printf("24h time: 12h time: 12:%02d AM", minute);
    else if (hours==12)
            printf("24h time: 12h time: 12:%02d PM", minute);
    else if(hours>12)
            printf("24h time: 12h time: %2d:%02d PM",hours - 12,minute);
    else printf("24h time: 12h time: %2d:%02d AM",hours,minute);

    return 0;
}









