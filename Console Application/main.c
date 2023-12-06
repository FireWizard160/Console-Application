#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum genre {
    horror = 1,
    adventure = 2,
    romance = 3,
    nonfiction = 4,
} typedef genre;

// Struct für die Informationen von neuen Büchern
struct book {
    char title[32];
    int genre;
    int year;
    int amount;
} typedef book;

// Struct für die Informationen von ausgeborgten Büchern
struct borrowedBook {
    char title[32];
    char name[32];
} typedef borrowedBook;

// Liste für die eingelesenen Büchern book book
struct bookNode {
    struct bookNode *next;
    // struct für infotmationen über Bücher
    book book;
} typedef bookNode;

//Liste für die ausgeborgten Bücher
struct borrowNode {
    struct borrowNode *next;
    // struct für infotmationen über ausgeborgte Bücher
    borrowedBook borrowedBook;
} typedef borrowNode;

//Erstellt neue Note für die InventarListe
bookNode *createBookNode(book newBook) {
    bookNode *newBookNode = (bookNode *) malloc(sizeof(bookNode));
    newBookNode->book = newBook;
    newBookNode->next = NULL;
    return newBookNode;
}

//Fügt die Note vorne an die Inventarliste an
bookNode *addBookBefore(bookNode *newBookNode, bookNode *inventoryList) {
    newBookNode->next = inventoryList;
    return newBookNode;
}

//Erstellt neue Note für ein ausgeborgtes Buch
borrowNode *createBorrowNode(borrowedBook newBorrowedBook) {
    borrowNode *newBorrowNode = (borrowNode *) malloc(sizeof(borrowNode));
    newBorrowNode->borrowedBook = newBorrowedBook;
    newBorrowNode->next = NULL;
    return newBorrowNode;
}

//Fügt die Note vorne an die Ausborgerliste an
borrowNode *addBorrowBefore(borrowNode *newBorrowNode, borrowNode *borrowedBookList) {
    newBorrowNode->next = borrowedBookList;
    return newBorrowNode;
}

//freet Memory für die Inventar Liste
void freeInventoryMemory(bookNode *inventoryList) {
    if (inventoryList == NULL)
        return;
    freeInventoryMemory(inventoryList->next);

    free(inventoryList);

}

//freet die Ausborgerliste
void freeBorrowedBookMemory(borrowNode *borrowedBookList) {
    if (borrowedBookList == NULL)
        return;
    freeBorrowedBookMemory(borrowedBookList->next);

    free(borrowedBookList);

}

//macht aus den Zahlen vom Enum das jeweilige Wort
char *getString(enum genre genreType) {
    switch (genreType) {

        case horror:
            return "Horror";
        case adventure:
            return "Abenteuer";
        case romance:
            return "Romantik";
        case nonfiction:
            return "Sachbuch";

    }

    return 0;
}

//wollte das nicht dauernd selber schreiben lol
void printUngueltigeEingabe() {
    printf("\nUngueltige Eingabe!");
}

// Nimmt daten für ein neues Buch entgegen
book insertBook() {
    //struct indem die neuen Informationen gespeichert werden sollen
    struct book newBook;
    newBook.title[31] = '\0';
    int input = 0;


    while (1) {
        printf("\nGeben Sie den Titel ein: ");

        scanf("%s", newBook.title);

        //Wenn String zulang ist wird ein fehler ausgegeben
        if (newBook.title[31] != '\0') {
            printUngueltigeEingabe();
            continue;
        }
        break;
    }

    while (1) {
        printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4):");
        scanf("%d", &input);

        //Wenn eingegebene Zahl nicht zwischen 1 und 4 liegt wird ein Fehler geprintet
        if (input < 1 || input > 4) {
            printUngueltigeEingabe();
            continue;
        }

        //Wenn alles richtig ist wird das genre hinzugefügt
        newBook.genre = input;
        break;
    }

    while (1) {
        printf("\nGeben Sie das Erscheinungsjahr ein:");
        scanf("%d", &input);

        //Überprüft ob die Zahl größer als 1 ist wenn nicht wird eine Fehlermeldung ausgegeben
        if (input < 1) {
            printUngueltigeEingabe();
            continue;
        }
        newBook.year = input;
        break;
    }

    while (1) {
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        scanf("%d", &input);

        //Überprüft ob die Zahl größer als 1 ist wenn nicht wird eine Fehlermeldung ausgegeben
        if (input < 1) {
            printUngueltigeEingabe();
            continue;
        }
        newBook.amount = input;
        break;
    }
    return newBook;

}

//printet die Inventar Liste
void printList(bookNode inventoryList) {
    int i = 1;
    for (bookNode *n = &inventoryList; n != NULL; n = n->next, i++) {
        printf("\n%d: %s, %s (%d)",i, n->book.title, getString(n->book.genre), n->book.year);
    }
    printf("\n");
}

//printet Ausborgerliste
void printBorrowedBookList(borrowNode *borrowedBookList) {
    int i = 1;
    for (borrowNode *n = borrowedBookList; n != NULL; n = n->next, i++) {
        printf("\n%d: %s geliehen von %s ",i, n->borrowedBook.title, n->borrowedBook.name);
    }
    printf("\n");
}

//Liest daten um ein Buch auszuborgen ein
borrowNode *borrowBook(bookNode *inventoryList, int inventoryListSize, borrowNode *borrowedBookList, int *borrowedBookListSize) {

    //variable zur ermittlung welcher Knoten aus der Liste gelöscht werden soll
    int borrowIndex = 0;
    char borrowerName[32];
    borrowerName[31] = '\0';

    //speichert Namen des Ausborgers und welchen Buchtitel
    struct borrowedBook newBorrowedBook;

    if (inventoryList == NULL) {
        printf("\n\nEs sind keine Buecher im Inventar vorhanden.");
        return 0;
    }

    printList(*inventoryList);

    while (1) {
        printf("\nWelchen Titel moechten Sie leihen? (1-%d): ", inventoryListSize);
        scanf("%d", &borrowIndex);

        if (borrowIndex < 1 || borrowIndex > inventoryListSize) {
            printUngueltigeEingabe();
            continue;
        }

        //Erstellt kopien zum Durchiterieren der Liste
        bookNode *copyInventoryList = inventoryList;
        bookNode *copyInventoryList2 = inventoryList;


        for (int i = 1; i < borrowIndex; i++) {
            if (copyInventoryList->next == NULL && borrowIndex == 1)
                break;

            copyInventoryList = copyInventoryList->next;
        }

        // Kopiert den Titel des Buches welches man ausborgen will in den struct
        strcpy(newBorrowedBook.title, copyInventoryList->book.title);

        printf("\nGeben Sie Ihren Namen ein: ");
        scanf("%s", borrowerName);

        if (borrowerName[31] != '\0') {
            printUngueltigeEingabe();
            continue;
        }

        // Kopiert den Name des Ausborgers welcher man ausborgen will in den struct
        strcpy(newBorrowedBook.name, borrowerName);

        // Überprüft ob der Titel bereits ausgeliehen wurde
        // Man kommt nur in das if wenn die ausborgerliste nicht leer ist
        if (borrowedBookList != NULL) {
            for (borrowNode *n = borrowedBookList; n != NULL; n = n->next) {

                //Schaue ob der Name und der Titel schon in der Ausborgerliste vorhanden ist
                //Wenn ja wird Fehldermeldung geprintet und returnt
                //Ansonsten wird das fertige struct returnt
                if (strcmp(n->borrowedBook.name, borrowerName) == 0 &&
                    strcmp(newBorrowedBook.title, n->borrowedBook.title) == 0) {
                    printf("\nSie haben diesen Titel bereits ausgeliehen!");
                    return borrowedBookList;
                }
            }
        }
        //checkt ob es noch exemplare von Buch, welches man ausborgen will, vorhanden sind
        if (copyInventoryList->book.amount == 0) {
            printf("\nBereits alle Exemplare ausgeliehen!");
            return borrowedBookList;
        }

        // Wenn die Liste Leer ist soll nur eine Note erstellt werden die auf Null zeigt
        if (borrowedBookList == NULL) {
            borrowedBookList = createBorrowNode(newBorrowedBook);
        } else {

            //Ansonsten wird die Note erstellt und vorne dazugehängt
            borrowedBookList = addBorrowBefore(createBorrowNode(newBorrowedBook), borrowedBookList);
        }

        //Scheife zum Minusrechnen des amounts von einem Buch
        // Durch die Liste durchiterieren bis der Ausborgtitel gleich dem Buchtitel ist und dann abziehen
        for (copyInventoryList2 = inventoryList;
             copyInventoryList2 != NULL; copyInventoryList2 = copyInventoryList2->next) {

            if (strcmp(borrowedBookList->borrowedBook.title, copyInventoryList2->book.title) == 0) {
                copyInventoryList2->book.amount--;
            }
        }
        break;
    }
    //Listengröße entsprechend reduzieren
    (*borrowedBookListSize)++;
    return borrowedBookList;
}

//Funktion zur Rückgabe von Büchern
borrowNode * returnBook(borrowNode *borrowedBookList, bookNode *inventoryList, int *borrowedBookListSize, int inventoryListSize) {

    //Wenn die Ausborgerliste leer ist kann nix zurückgegeben werden
    if (borrowedBookList == NULL) {
        printf("\n\nEs sind keine Titel ausgeliehen!");
        return borrowedBookList;
    }

    printBorrowedBookList(borrowedBookList);

    int input = 0;
    //variable zum zwischenspeichern damit ADresse nicht verloren geht
    borrowNode *freeNode;
    borrowNode *copyBorrowedBookList = borrowedBookList;
    bookNode *copyInventoryList = inventoryList;
    while (1) {

        printf("\nWelchen Titel moechten Sie retournieren? (1-%d):", *borrowedBookListSize);
        scanf("%d", &input);

        //checkt ob der Input richtig ist wenn nicht wird Fehlermeldung geprintet
        if (input < 1 || input > *borrowedBookListSize) {
            printUngueltigeEingabe();
            continue;
        }

        //If um Edgecase zu vermeiden wenn das erste Element gelöscht werden soll
        if (input == 1) {
            //Amount entsprechend erhöhen wenn Ausborgertitel und Buchtitel gleich sind
            if (strcmp(copyBorrowedBookList->borrowedBook.title, copyInventoryList->book.title) == 0) {
                copyInventoryList->book.amount++;
                break;
            }

            //borrowedBookList zwischenspeichern um es nicht zu verlieren
            freeNode = borrowedBookList;
            //Listenanfang auf das nächste Element setzen
            borrowedBookList = borrowedBookList->next;
            //erstes Element freigeben
            free(freeNode);
            break;
        }

        //Iteriert zu dem Knoten den wir löschen wollen
        for (int i = 1; i < input - 1; ++i, copyBorrowedBookList = copyBorrowedBookList->next);

        //Speichert den Knoten zwischen damit wir ihn nicht verlieren
        freeNode = copyBorrowedBookList->next;

        //Iteriert durch die Liste und erhöht amount um eins wenn Richtiger Knoten gefunden worden ist
        for (; copyInventoryList != NULL; copyInventoryList = copyInventoryList->next) {
            if (strcmp(copyBorrowedBookList->borrowedBook.title, copyInventoryList->book.title) == 0) {
                copyInventoryList->book.amount++;
                break;
            }
        }

        //setzt den Pointer von next auf next next
        copyBorrowedBookList->next = copyBorrowedBookList->next->next;
        //zu löschender Knoten wird freigegeben
        free(freeNode);
        break;
    }
    (*borrowedBookListSize)--;
    return borrowedBookList;
}

//Printet die Liste aufsteigend nach dem Erscheinungsjahr
void printListInOrder(bookNode inventoryList, int inventoryListSize) {
    book booksInOrder[inventoryListSize];
    if (inventoryListSize == 0) {
        return;
    }
    if (inventoryListSize == 1) {
        printList(inventoryList);
        return;
    }

    int i = 0;
    for (bookNode *n = &inventoryList; n != NULL; n = n->next) {
        booksInOrder[i] = n->book;
        i++;

    }
    i = 1;
    book temp;
    for (int j = 0; j < inventoryListSize; ++i) {
        if (booksInOrder[j].year > booksInOrder[i].year) {
            temp = booksInOrder[j];
            booksInOrder[j] = booksInOrder[i];
            booksInOrder[i] = temp;

        }
        if (i == inventoryListSize - 1) {
            j++;
            i = 1;
            if (j == inventoryListSize - 1) {
                break;
            }
        }

    }

    for (int j = 0; j < inventoryListSize; ++j) {

        printf("\n%d: %s, %s (%d)", j + 1, booksInOrder[j].title, getString(booksInOrder[j].genre),
               booksInOrder[j].year);
    }
    printf("\n");
}

int main() {
    //Bücherliste, Inventarliste
    struct bookNode *inventoryList = NULL;
    //Ausborgerliste
    struct borrowNode *borrowedBookList = NULL;

    int inventoryListSize = 0;
    int borrowedBookListSize = 0;

    char input;

    while (1) {

        printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)");
        printf("\nAuswahl: ");
        scanf(" %c", &input);

        switch (input) {
            case 'n':
                // Erstellt neues Buch und fügt es vorne an die Inventarliste an
                inventoryList = addBookBefore(createBookNode(insertBook()), inventoryList);
                inventoryListSize++;
                break;

            case 'b':
                // Liest den Namen einer Person und ein Buch was man ausborgen möchte ein und fügt die Informatioen
                // am Anfang der Ausborgerliste an
                borrowedBookList = borrowBook(inventoryList, inventoryListSize, borrowedBookList,&borrowedBookListSize);

                break;

            case 'r':
                // Löscht einen Eintrag aus der Ausborgerliste, Option um ein ausgeborgtes Buch zurückzugeben
                borrowedBookList = returnBook(borrowedBookList, inventoryList, &borrowedBookListSize,
                                              inventoryListSize);
                break;

            case 'l':
                // Gibt unsortierte Inventarliste aus
                printList(*inventoryList);

                break;

            case 's':
                // gibt sortierte Inventarliste aus
                printListInOrder(*inventoryList, inventoryListSize);

                break;

            case 'x':
                //Beendet das programm und gibt die beiden listen Frei
                freeInventoryMemory(inventoryList);
                freeBorrowedBookMemory(borrowedBookList);
                return 0;


            default:
                //Printet Fehldermeldung bei falscher eingabe
                printUngueltigeEingabe();
                break;
        }
    }
}
