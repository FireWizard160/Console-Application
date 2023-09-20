#include <stdio.h>

int main() {
    int dezimal, d1, d2, d3 , octazahl, z1, z2, z3;

    scanf("%d", &dezimal);
    d1 = dezimal % 10;
    dezimal /= 10;
    d2 = dezimal % 10;
    dezimal /= 10;
    d3 = dezimal % 10;



    if (d1 < 8 && d2 < 8 && d3 < 8)
    {
        octazahl = d3 * 8 * 8 + d2 * 8 + d1 * 1;
        printf(": dec.:%d\n", octazahl);

        z1 = octazahl % 10;
        octazahl /= 10;
        z2 = octazahl % 10;
        octazahl /= 10;
        z3 = octazahl % 10;


        printf("ZS: %d", z1 + z2 + z3);
    }

    return 0;
}