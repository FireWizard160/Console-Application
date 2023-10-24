#include <stdio.h>
#include <stdlib.h>

#define anz 10


double praemien(double betraege[], int anzahl, double grenze, double praemie) {
    double summepraemien;
    for (int i = 0; i < anzahl; i++) {
        if (betraege[i] >= grenze) {
            betraege[i] += praemie;
            summepraemien += praemie;
        }

    }

    return summepraemien;


}

int eingabe(double betraege[], int max) {
    double ueberpruefung;
    int anzahl;
    for (int i = 0; i < max; i++) {

        printf("Zahl %d: ", i + 1);
        scanf(" %lf", &ueberpruefung);



        if (ueberpruefung < 0)
            return anzahl;


        betraege[i] = ueberpruefung;
        anzahl++;
    }
return anzahl;

}

double sum(double betraege[], int anzahl) {
    double summebetraege;
    for (int i = 0; i < anzahl; i++) {
        summebetraege += betraege[i];

    }

    return summebetraege;
}

int main() {
    double arr[anz] = {0};
    double grenze, praemie, gesamt;
    int n;

    n = eingabe(arr, anz);
    printf("Untergrenze: ");
    scanf("%lf", &grenze);
    printf("Praemie: ");
    scanf("%lf", &praemie);

    printf("Summe vor Praemien: %.2f\n", sum(arr, n));
    gesamt = praemien(arr, n, grenze, praemie);
    printf("Praemien gesamt: %.2f\n", gesamt);
    printf("Summe nach Praemien: %.2f\n", sum(arr, n));

    return 0;
}
