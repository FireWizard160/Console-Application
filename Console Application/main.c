#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    printf(": ");

    scanf("%d",&n);

    int array[n+1];

    for (int i = 0; i < n+1; ++i) {
        array[i] = i;

    }

     int temp = 0;
    for (int i = 2; i < n+1; ++i) {

        for (int j = 2; j < n+1; ++j) {
            temp = array[i]*j;

            if (temp >= n+1)
                break;

            array[temp] = 0;
        }


    }

    for (int i = 2, j = 0; i < n+1; ++i) {
        if (array[i] == 0)
            continue;


        printf("%d ",array[i]);


        j++;
        if (j == 10){
            printf("\n");
            j = 0;
        }

    }
    return 0;
}
