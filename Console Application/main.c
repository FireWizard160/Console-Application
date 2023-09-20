#include <stdio.h>

int main() {
    int hours,minute;

    scanf("%:%d",&hours,&minute);


    switch (hours) {

        case 0:printf("24h time: 12h time: 12:%d AM\n",minute); break;
        case 1:printf("24h time: 12h time:  1:%d AM\n",minute); break;
        case 2:printf("24h time: 12h time:  2:%d AM\n",minute); break;
        case 3:printf("24h time: 12h time:  3:%d AM\n",minute); break;
        case 4:printf("24h time: 12h time:  4:%d AM\n",minute); break;
        case 5:printf("24h time: 12h time:  5:%d AM\n",minute); break;
        case 6:printf("24h time: 12h time:  6:%d AM\n",minute); break;
        case 7:printf("24h time: 12h time:  7:%d AM\n",minute); break;
        case 8:printf("24h time: 12h time:  8:%d AM\n",minute); break;
        case 9:printf("24h time: 12h time:  9:%d AM\n",minute); break;
        case 10:printf("24h time: 12h time: 10:%d AM\n",minute); break;
        case 11:printf("24h time: 12h time: 11:%d AM\n",minute); break;
        case 12:printf("24h time: 12h time: 12:%d PM\n",minute); break;
        case 13: printf("24h time: 12h time:  1:%d PM\n",minute); break;
        case 14: printf("24h time: 12h time:  2:%d PM\n",minute); break;
        case 15: printf("24h time: 12h time:  3:%d PM\n",minute); break;
        case 16: printf("24h time: 12h time:  4:%d PM\n",minute); break;
        case 17: printf("24h time: 12h time:  5:%d PM\n",minute); break;
        case 18: printf("24h time: 12h time:  6:%d PM\n",minute); break;
        case 19: printf("24h time: 12h time:  7:%d PM\n",minute); break;
        case 20: printf("24h time: 12h time:  8:%d PM\n",minute); break;
        case 21: printf("24h time: 12h time:  9:%d PM\n",minute); break;
        case 22: printf("24h time: 12h time: 10:%d PM\n",minute); break;
        case 23: printf("24h time: 12h time: 11:%d PM\n",minute); break;
        case 24: printf("24h time: 12h time: 00:%d AM\n",minute); break;

            printf("Fehler");
    }


    return 0;
}


