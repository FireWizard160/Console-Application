#include <stdio.h>

int main() {
    int z1,z2,z3,z4,z5,max,min,summe1,summe2,summe3,summe4,summe5;

    scanf("%d %d %d %d %d",&z1,&z2,&z3,&z4,&z5);
    summe1 = z1 + z2 + z3 + z4;
    summe2 = z2 + z3 + z4 + z5;
    summe3 = z1 + z3 + z4 + z5;
    summe4 = z1 + z2 + z4 + z5;
    summe5 = z1 + z2 + z3 + z5;
    min = summe1;
    max = summe1;

    if(min > summe2)
        min = summe2;
    if(min > summe3)
        min = summe3;
    if(min > summe4)
        min = summe4;
    if(min > summe5)
        min = summe5;



    if(max < summe2)
        max = summe2;
    if(max < summe3)
        max = summe3;
    if(max < summe4)
        max = summe4;
    if(max < summe5)
        max = summe5;
printf(": minimum sum: %d\n",min);
printf("maximum sum: %d\n",max);
return 0;
}









