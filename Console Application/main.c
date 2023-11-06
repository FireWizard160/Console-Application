#include <stdio.h>
#include <stdlib.h>


enum type {

    Termin_mit_freunden = 'f',
    Geschaeftlicher_Termin = 'b',
    Pause = 'p',


};

struct appointment {

    char type;
    int time;
    int duration;


};


void printAppointments(struct appointment *schedule, int length) {

    for (int i = 0; i <= length; ++i) {
        if (schedule[i].type != 0)
            printf("%d. %c: %d Uhr, Dauer %d h\n", i, schedule[i].type, schedule[i].time, schedule[i].duration);

    }
}

void printInformation(struct appointment *schedule, int length) {


    for (int i = 0; i <= length; ++i) {
        if (schedule[i].time + length > schedule[i + 1].time) {
            printf("Entweder Termin %d oder Termin %d sollte abgesagt werden\n", i, i + 1);
            break;
        }

        if (i == length) {
            printf("Der Kalender hat keine Kollisionen!\n");
        }
    }

    int cntPause = 0;
    int cntGeschaeftstermin = 0;
    int cntTerminFreunde = 0;

    for (int i = 0; i < 10; ++i) {
        if (schedule[i].type == Pause)
            cntPause++;

        if (schedule[i].type == Termin_mit_freunden)
            cntTerminFreunde++;


        if (schedule[i].type == Geschaeftlicher_Termin) {
            cntGeschaeftstermin++;

            for (int j = i + 1; j < 10; ++j) {
                if (schedule[j].type == Pause || schedule[i].type == Termin_mit_freunden)
                    break;

                if (schedule[j].type == Geschaeftlicher_Termin) {
                    printf("Die Termine %d und %d liegen hintereinander und sind beide Geschaeftstermine\n", i, j);
                }
            }
        }
    }


    printf("Sie haben %d Geschaeftstermin(e), %d Termin(e) mit freunden und %d Pause(n) in Ihrem Kalender",
           cntGeschaeftstermin, cntTerminFreunde, cntPause);


}

struct appointment createAppointment() {

    struct appointment newAppointment;
    while (1) {

        printf("Gib einen Typen ein: Freunde (f), Geschaeftlich (b), Pause (p): ");
        scanf("%c", &newAppointment.type);

        if (newAppointment.type == 'f' || newAppointment.type == 'b' || newAppointment.type == 'p') {
        } else {
            printf("Ungueltige Eingabe!");
            continue;
        }


        printf("Gib eine Uhrzeit ein (8-21): ");
        scanf("%d", &newAppointment.time);

        if (newAppointment.time < 8 || newAppointment.time > 21) {
            printf("Ungueltige Eingabe!");
            continue;
        }


        printf("Gib eine Dauer ein (1-14): ");
        scanf("%d", &newAppointment.duration);

        if (newAppointment.time + newAppointment.duration < 22 || newAppointment.duration == 0) {
            printf("Ungueltige Eingabe!");
            continue;
        }

        break;
    }


    return newAppointment;

}

void addAppointment(struct appointment *schedule, int *length) {

    if (*length == 10) {
        printf("Der Kalender ist voll!");
    }

}

void deleteAppointment(struct appointment *schedule, int *length) {

    if (*length == 0) {
        printf("Der Kalender ist leer!");
        return;
    }

    printAppointments(schedule, *length);


}


// printed das standard menü und scant eingabe
char menue() {
    char eingabe;

    printf("\nNeuen Termin (n), Termin loeschen (d), Termine auflisten (l), Informationen ausgeben (i), Programm beenden (x)\n");
    printf("Auswahl: \n");
    scanf(" %c", &eingabe);
    return eingabe;

}


int main() {
    int length = 9;
    struct appointment schedule[10];


    while (1) {
        switch (menue()) {

            case 'n':
                // neuen Termin erfassen

                addAppointment(schedule, &length);

                break;

            case 'd':
                // Termin löschen
                //deleteAppointment();

                break;

            case 'l':
                //aktuelle Termine auflisten
                //printAppointments();

                break;

            case 'i':
                //Informationen über Termine auflisten
                printInformation(schedule, length);


                break;

            case 'x':
                //Programm beenden
                return 0;

            default:
                printf("Ungueltige Eingabe!");
                continue;
        }
        break;
    }


}
