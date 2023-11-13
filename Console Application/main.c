#include <stdio.h>

enum type {
    friends = 'f',
    business = 'b',
    pause = 'p',
};

struct appointment {
    char type;
    int time;
    int duration;
};


//Wandelt den Type in die ausgeschriebene Version um
char *getString(enum type appointmentType) {
    switch (appointmentType) {

        case friends:
            return "Freunde";
        case business:
            return "Geschaeftlich";
        case pause:
            return "Pause";
    }

    return 0;
}

//Printet alle aktuellen Termine
void printAppointments(struct appointment *schedule, int length) {
    // Wenn keine Termine vorhanen sind soll die Funktion nichts machen
    if (length == 0)
        return;


    //Printet alle Termine im array von 0 bis zur aktuellen Länge
    for (int i = 0; i < length; ++i) {
        printf("\n%d: %s: %d Uhr, Dauer %dh", i + 1, getString(schedule[i].type), schedule[i].time,
               schedule[i].duration);

    }
}


void printInformation(struct appointment *schedule, int length) {

    int collision = 0;
    for (int i = 0; i < length - 1; ++i) {
        //Kontrolliert ob sich Termine überschneiden
        if (schedule[i].time + schedule[i].duration > schedule[i + 1].time) {
            printf("\nEntweder Termin %d oder Termin %d sollte abgesagt werden", i + 1, i + 2);
            collision++;
        }


    }

    if (collision == 0) {
        printf("\nDer Kalender hat keine Kollisionen!");
    }


    int cntPause = 0;
    int cntGeschaeftstermin = 0;
    int cntTerminFreunde = 0;

    for (int i = 0; i < length; ++i) {
        if (schedule[i].type == pause)
            cntPause++;

        if (schedule[i].type == friends)
            cntTerminFreunde++;


        if (schedule[i].type == business) {
            cntGeschaeftstermin++;

            //Kontrolliert ob 2 Geschäftstermine hintereinander liegen --> printet es wenn das der Fall ist
            if (i != length - 1 && schedule[i + 1].type == business) {
                printf("\nDie Termine %d und %d liegen hintereinander und sind beide Geschaeftstermine.", i + 1, i + 2);

            }
        }
    }
    //printet Anzahl der jeweiligen Termine
    printf("\nSie haben %d Geschaeftstermin(e), %d Termin(e) mit Freunden und %d Pause(n) in Ihrem Kalender.",
           cntGeschaeftstermin, cntTerminFreunde, cntPause);
}

struct appointment createAppointment() {

    struct appointment newAppointment;

    while (1) {

        printf("\nGib einen Typen ein: Freunde (f), Geschaeftlich (b), Pause (p): ");
        scanf(" %c", &newAppointment.type);

        if (newAppointment.type != 'f' && newAppointment.type != 'b' && newAppointment.type != 'p') {

            printf("\nUngueltige Eingabe!");
            continue;
        }
        break;
    }

    while (1) {
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

    if (*length == 10) {
        printf("\nDer Kalender ist voll!");
        return;
    }

    struct appointment newAppointment = createAppointment();

    for (int i = *length; i >= 0; --i) {
        if (i == 0 || newAppointment.time > schedule[i - 1].time) {


            schedule[i] = newAppointment;
            (*length)++;
            break;

        }
        schedule[i] = schedule[i - 1];
    }
}

void deleteAppointment(struct appointment *schedule, int *length) {
    if (*length == 0) {
        printf("\nDer Kalender ist leer!");
        return;
    }

    int input = 0;

    printAppointments(schedule, *length);
    printf("\nWelchen dieser Termine moechten Sie loeschen? (1-%d): ", *length);

    while (1) {

        scanf("%d", &input);

        if (input < 1 || input > *length) {
            printf("Ungueltige Eingabe!");
            continue;

        }
        for (int i = input - 1; i < *length; ++i) {
            schedule[i] = schedule[i + 1];
        }

        printf("\nTermin %d wurde geloescht!", input);
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
