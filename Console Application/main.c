#include <stdio.h>
#include <float.h>


int main() {
    int eingabe, cntE, cntA;
    double guthaben = 100, brutto, netto, steuer, steuerges, steuerfrei, avgA, avgE, betrag, ages, eges;


    do {

        printf("Typ:");
        scanf("%d", &eingabe);

        if (eingabe != '=') {
            printf("Betrag in Euro:\n");
            scanf("2.lf", &betrag);
        }
        if (betrag < 0) {
            printf("Der Betrag kann nicht negativ sein");
        }


        switch (eingabe) {
            case 'e':

                if (betrag <= 20) {
                    guthaben = +betrag;
                }

                if (betrag > 20 && betrag <= 50) {
                    steuer = (betrag - 20) * 0.1;
                    steuerges = +steuer;
                    guthaben = +betrag;
                }

                if (betrag > 50 && betrag <= 200) {
                    guthaben = +20;
                    steuer = (betrag - 70) * 0.2;
                    steuer =+ 30*0.1;

                    steuerges = +steuer;
                    guthaben = +betrag;
                }
                if (eingabe > 200) {
                    guthaben = +20;
                    steuer = +30 * 0.1;
                    steuer = +130 * 0.2;
                    steuer =+ (betrag-130)*0.4;


                }
                    eges = eges + eingabe - steuer;
                    cntE++;

                break;
            case 's':


                guthaben = +betrag;
                printf("Guthaben: %d",guthaben);

                avgE = avgE + eingabe;
                cntE++;
                break;
            case 'k':
                if (betrag > guthaben)
                    printf("Diese Kosten können nicht bezahlt werden");


                ages = ages + eingabe;
                cntA++;
                break;
            case '=':


                break;
        }

    } while (eingabe == '=');


    avgE=eges/cntE;
    avgA=ages/cntA;


    printf("%d Einnahmen durchschnittlichem Wert %d Euro\n", cntE, avgE);
    printf("%d Einnahmen durchschnittlichem Wert %d Euro\n", cntA, avgA);


    return 0;
}




