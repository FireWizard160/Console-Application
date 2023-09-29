#include <stdio.h>
#include <float.h>


int main() {
    double min = DBL_MAX, max = DBL_MIN, avg, wert, sum;
    int cnt = 0;


    do {


        printf(": ");
        scanf("%lf.2", &wert);
        if (wert <= 0) {


            break;
        }

        if (wert < min)
            min = wert;
        if (wert > max)
            max = wert;


        sum += wert;
        cnt++;


    } while (wert > 0);


    avg = sum / cnt;

    if (cnt == 0) {
        printf("no number entered");
        return 0;
    }

    printf("cnt: %d\n", cnt);
    printf("min: %.2lf\n", min);
    printf("max: %.2lf\n", max);
    printf("avg: %.2lf\n", avg);


    return 0;
}




