#include <stdio.h>

int main() {
    int dig1, dig2, dig3,octazahl, z1,z2,z3;

    scanf("%1d%1d%1d", &dig1, &dig2, &dig3);


    if(dig1<8&&dig2<8&&dig3<8)
     octazahl=dig1 * 8 * 8 + dig2 * 8 + dig3 * 1;
    printf(": dec.:%d\n", octazahl);

    z1=octazahl%10;
    octazahl/=10;
    z2=octazahl%10;
    octazahl/=10;
    z3=octazahl%10;


    printf("ZS: %d",z1+z2+z3);



    return 0;
}