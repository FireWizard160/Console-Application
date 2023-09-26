#include <stdio.h>

int main() {
int noten, noten2, n1, n2, n3;


    scanf("%d", &noten);
    noten2 = noten;

printf("Noten: ");

if(noten > 999 || noten < 111 ){
    printf("Erwarte genau 3 Noten!\n");
return 0;
    }

    n1 = noten % 10;
    noten /= 10;
    n2 = noten % 10;
    noten /= 10;
    n3 = noten % 10;


if (n3 > 3 || n3 < 1) {
    printf("Erste Note muss zwischen 1 und 5 liegen!\n");
    return 0;
}

if (n2 > 5 || n2 < 1){
    printf("Zweite Note muss zwischen 1 und 5 liegen!\n");
    return 0;
}
if (n1 > 5 || n1 < 1){
    printf("Dritte Note muss zwischen 1 und 5 liegen!\n");
    return 0;
}

if ( n1 == 5 || n2 == 5 || n3 == 5 )
    printf("Nicht bestanden!\n");

else if ( n1 == 1 && n2 == 1 && n3 == 1 )
    printf("Ausgezeichneter Erfolg!\n");

else if ( noten2 == 211 || noten2 == 121 || noten2 == 112 )
    printf("Guter Erfolg!\n");

else printf("Bestanden.\n");

return 0;
}









