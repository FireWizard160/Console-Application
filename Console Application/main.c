#include <stdio.h>
#include <float.h>


int main() {
    char eingabe;
    int cntE = 0, cntA = 0;
    double guthaben = 100, steuer, avgA = 0, avgE = 0, betrag, ages, eges, steuerges, zsm;
    printf("\n");

    do {
        printf("Guthaben: %.2f Euro", guthaben);
        printf("\n");
        printf("Typ: ");
        printf("\n");

        scanf(" %c", &eingabe);
        if (eingabe == '=')
            break;


        if (eingabe != '=') {
            printf("Betrag in Euro: ");
            printf("\n");
            scanf(" %lf", &betrag);
        }
        if (betrag < 0) {
            printf("Der Betrag kann nicht negativ sein.");
            printf("\n");
            continue;
        }


        switch (eingabe) {
            case 'e':

                if (betrag <= 20.00) {
                    guthaben = guthaben + betrag;
                    printf("Gezahlte Steuern: %.2f Euro", steuer);
                    printf("\n");
                }

                if (betrag > 20.00 && betrag <= 50.00) {
                    zsm = betrag;
                    steuer = (zsm - 20) * 0.1;
                    steuerges += steuer;
                    betrag = betrag - steuer;
                    guthaben += betrag;
                    printf("Gezahlte Steuern: %.2f Euro", steuer);
                    printf("\n");
                }

                if (betrag > 50.00 && betrag <= 200.00) {
                    zsm = betrag;
                    steuer = ((zsm - 50) * 0.2) + (30 * 0.1);
                    betrag = betrag - steuer;
                    guthaben = guthaben + betrag;
                    steuerges = steuerges + steuer;

                    printf("Gezahlte Steuern: %.2f Euro", steuer);
                    printf("\n");
                }
                if (betrag > 200) {
                    zsm = betrag;
                    steuer = ((zsm - 200) * 0.4) + (150 * 0.2) + (30 * 0.1);
                    betrag = betrag - steuer;
                    guthaben = guthaben + betrag;
                    steuerges += steuer;

                    printf("Gezahlte Steuern: %.2f Euro", steuer);
                    printf("\n");

                }
                eges = eges + betrag;
                cntE++;

                break;
            case 's':


                guthaben = guthaben + betrag;


                eges = eges + betrag;
                cntE++;
                break;

            case 'k':
                if (betrag > guthaben) {
                    printf("Diese Kosten koennen nicht bezahlt werden.");
                    printf("\n");
                    continue;
                }
                guthaben = guthaben - betrag;
                ages = ages + betrag;
                cntA++;
                break;

            case '=':

            // der case breakt das
                break;
        }

    } while (eingabe != '=');

    printf("Restguthaben: %.2f Euro", guthaben);
    printf("\n");

    if (cntE == 0) {
        printf("%d Einnahmen mit durchschnittlichem Wert %.2lf Euro", cntE, avgE);
        printf("\n");
    }

    else {
        avgE = eges / cntE;
        printf("%d Einnahmen mit durchschnittlichem Wert %.2lf Euro", cntE, avgE);
        printf("\n");
    }
    if (cntA == 0) {
        printf("%d Ausgaben mit durchschnittlichem Wert %.2lf Euro", cntA, avgA);
        printf("\n");
    }
    else {
        avgA = ages / cntA;
        printf("%d Ausgaben mit durchschnittlichem Wert %.2lf Euro", cntA, avgA);
        printf("\n");
    }

    printf("Gezahlte Steuern: %.2f Euro", steuerges);
    printf("\n");


    return 0;
}




