#include <stdio.h>
#include <float.h>


int main() {
    int eingabe, cntE, cntA;
    double guthaben = 100, brutto, netto, steuer, steuerges, steuerfrei, avgA, avgE, betrag;


    do {

        printf("Typ:");
        scanf("%.2lf", &eingabe);
        printf("Betrag in Euro: ");
        scanf("2.lf", &betrag);

        if (eingabe < 0)
            printf("Der Betrag kann nicht negativ sein");



        switch (eingabe) {
            case 'e':

                if (betrag <= 20)
                    guthaben = +betrag;
                if (betrag > 20 && betrag <= 50)
                    steuer = (betrag - 20) * 0.1;
                steuerges = +steuer;
                guthaben = +eingabe;

                if (eingabe > 50 && eingabe <= 200)
                    guthaben = +20;
                steuer = (eingabe - 200) * 0.2;

                steuerges = +steuer;
                steuer = (eingabe - 20) * 0.1;
                steuerges = +steuer;
                guthaben = +eingabe;

                if (eingabe > 200)
                    steuer = (eingabe - 50) * 0.2;

                steuerges = +steuer;
                steuer = (eingabe - 20) * 0.1;
                steuerges = +steuer;
                guthaben = +eingabe;


                cntE++;

                break;
            case 's':
                guthaben = +betrag;


                cntE++;
                break;
            case 'k':
                if (eingabe > guthaben)
                    printf("Diese Kosten können nicht bezahlt werden");


                cntA++;
                break;
            case '=':


                break;
        }

    } while (eingabe == '=');

    printf("%d Einnahmen durchschnittlichem Wert %d Euro", cntE, avgE);
    printf("%d Einnahmen durchschnittlichem Wert %d Euro", cntA, avgA);


    return 0;
}




