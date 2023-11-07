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

char *getString(enum type appointmentType) {
    switch (appointmentType) {

        case Termin_mit_freunden:
            return "Freunde";
            break;
        case Geschaeftlicher_Termin:
            return "Geschaeftlich";
            break;
        case Pause:
            return "Pause";
            break;
    }

return 0;
}

void printAppointments(struct appointment *schedule, int length) {

    if (length == 0)
        return;

    for (int i = 0; i < length; ++i) {
            printf("\n%d: %s: %d Uhr, Dauer %dh", i + 1, getString(schedule[i].type), schedule[i].time,
                   schedule[i].duration);

    }
}


void printInformation(struct appointment *schedule, int length) {

int temp = 0;
    for (int i = 0; i < length - 1; ++i) {
        if (schedule[i].time + schedule[i].duration > schedule[i + 1].time) {
            printf("\nEntweder Termin %d oder Termin %d sollte abgesagt werden", i, i + 1);
            temp++;
            break;
        }


    }

    if (temp == 0) {
        printf("\nDer Kalender hat keine Kollisionen!");
    }
    temp = 0;

    int cntPause = 0;
    int cntGeschaeftstermin = 0;
    int cntTerminFreunde = 0;

    for (int i = 0; i < length; ++i) {
        if (schedule[i].type == Pause)
            cntPause++;

        if (schedule[i].type == Termin_mit_freunden)
            cntTerminFreunde++;


        if (schedule[i].type == Geschaeftlicher_Termin) {
            cntGeschaeftstermin++;
            if (i != length - 1 && schedule[i+1].type == Geschaeftlicher_Termin){
                printf("\nDie Termine %d und %d liegen hintereinander und sind beide Geschaeftstermine.", i + 1, i + 2);

            }
        }
    }

    printf("\nSie haben %d Geschaeftstermin(e), %d Termin(e) mit Freunden und %d Pause(n) in Ihrem Kalender.",
           cntGeschaeftstermin, cntTerminFreunde, cntPause);


}

struct appointment createAppointment() {

    struct appointment newAppointment;

    while (1) {

        printf("\nGib einen Typen ein: Freunde (f), Geschaeftlich (b), Pause (p): ");
        scanf(" %c", &newAppointment.type);

        if (newAppointment.type == 'f' || newAppointment.type == 'b' || newAppointment.type == 'p') {
        } else {
            printf("\nUngueltige Eingabe!");
            continue;
        }
        break;
    }

    while(1) {
        printf("\nGib eine Uhrzeit ein (8-21): ");
        scanf(" %d", &newAppointment.time);

        if (newAppointment.time < 8 || newAppointment.time > 21) {
            printf("\nUngueltige Eingabe!");
            continue;
        }
        break;
    }

    while (1) {
        printf("\nGib eine Dauer ein (1-%d): ", 22 - newAppointment.time);
        scanf(" %d", &newAppointment.duration);

        if (newAppointment.time + newAppointment.duration > 22 || newAppointment.duration < 1) {
            printf("\nUngueltige Eingabe!");
            continue;
        }

        break;
    }


    return newAppointment;

}

void addAppointment(struct appointment *schedule, int *length) {
    struct appointment temp;


    if (*length == 10) {
        printf("\nDer Kalender ist voll!");
        return;
    }



     temp = createAppointment();


    for (int i = *length; i >= 0; --i) {
        if (i == 0 || temp.time >= schedule[i - 1].time){


            schedule [i] = temp;
            (*length)++;
            break;

        }
        schedule [i] = schedule[i - 1];


    }


}

void deleteAppointment(struct appointment *schedule, int *length) {
    int temp = 0;
    if (*length == 0) {
        printf("\nDer Kalender ist leer!");
        return;
    }
    printAppointments(schedule, *length);
    printf("\nWelchen dieser Termine moechten Sie loeschen? (1-%d): ", *length);

    while (1) {


        scanf("%d", &temp);

        if (temp < 1 || temp > *length) {
            printf("Ungueltige Eingabe!");
            continue;

        }
        for (int i = temp - 1; i < *length; ++i) {
            schedule[i] = schedule[i + 1];
        }

        printf("\nTermin %d wurde geloescht!", temp);
        (*length)--;
        break;
    }


}


// printed das standard menü und scant eingabe
char menue() {
    char eingabe;

    printf("\nNeuen Termin (n), Termin loeschen (d), Termine auflisten (l), Informationen ausgeben (i), Programm beenden (x)");
    printf("\nAuswahl: ");
    scanf(" %c", &eingabe);
    return eingabe;

}


int main() {
    int length = 0;
    struct appointment schedule[10];


    while (1) {
        switch (menue()) {

            case 'n':
                // neuen Termin erfassen

                addAppointment(schedule, &length);

                break;

            case 'd':
                // Termin löschen
                deleteAppointment(schedule, &length);

                break;

            case 'l':
                //aktuelle Termine auflisten
                printAppointments(schedule, length);

                break;

            case 'i':
                //Informationen über Termine auflisten
                printInformation(schedule, length);


                break;

            case 'x':
                //Programm beenden
                return 0;

            default:
                printf("\nUngueltige Eingabe!");
                continue;
        }

    }


}
