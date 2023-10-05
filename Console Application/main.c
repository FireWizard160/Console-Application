#include <stdio.h>


int main() {
    char eingabe;
    int cntE = 0, cntA = 0;
    double guthaben = 100, steuer, avgA = 0, avgE = 0, betrag, ages, eges, steuerges, zs;
    printf("\n");

    do {
        printf("Guthaben: %.2lf Euro", guthaben);
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
                    printf("Gezahlte Steuern: %.2lf Euro", steuer);
                    printf("\n");
                }

                if (betrag > 20.00 && betrag <= 50.00) {
                    zs = betrag;
                    steuer = (zs - 20) * 0.1;
                    steuerges += steuer;
                    betrag -= steuer;
                    guthaben += betrag;
                    printf("Gezahlte Steuern: %.2lf Euro", steuer);
                    printf("\n");
                }

                if (betrag > 50.00 && betrag <= 200.00) {
                    zs = betrag;
                    steuer = ((zs - 50) * 0.2) + (30 * 0.1);
                    betrag -= steuer;
                    guthaben += betrag;
                    steuerges += steuer;

                    printf("Gezahlte Steuern: %.2lf Euro", steuer);
                    printf("\n");
                }
                if (betrag > 200) {
                    zs = betrag;
                    steuer = ((zs - 200) * 0.4) + (150 * 0.2) + (30 * 0.1);
                    betrag -= steuer;
                    guthaben += betrag;
                    steuerges += steuer;

                    printf("Gezahlte Steuern: %.2lf Euro", steuer);
                    printf("\n");

                }
                steuer = 0;
                eges += betrag;
                cntE++;

                break;
            case 's':


                guthaben += betrag;


                eges += betrag;
                cntE++;
                break;

            case 'k':
                if (betrag > guthaben) {
                    printf("Diese Kosten koennen nicht bezahlt werden.");
                    printf("\n");
                    continue;
                }
                guthaben -= betrag;
                ages += betrag;
                cntA++;
                break;


        }

    } while (eingabe != '=');

    printf("Restguthaben: %.2lf Euro", guthaben);
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

    printf("Gezahlte Steuern: %.2lf Euro", steuerges);
    printf("\n");


    return 0;
}




