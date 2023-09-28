#include <stdio.h>


int main() {
    float min, max, cnt, avg, wert, sum;



    do {



        printf(": ");
        scanf("%f.2", &wert);
        if (wert <= 0 ) {
            printf("no number entered");
        }

        if (wert < min)
            min = wert;
        if (wert > max)
            max = wert;


        sum = sum + wert;
        cnt++;




    } while (wert > 0);


    avg = sum / cnt;

    printf("cnt: %f\n", cnt);
    printf("min: %.2f\n", min);
    printf("max: %.2f\n", max);
    printf("avg: %.2f\n", avg);


    return 0;
}




