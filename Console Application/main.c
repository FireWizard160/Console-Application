#include <stdio.h>
#include <stdlib.h>

enum genre {
    horror = '1',
    adventure = '2',
    romance = '3',
    nonfiction = '4',
} typedef genre;

struct book {
    char title[32];
    int genre;
    int year;
    int amount;
} typedef book;


struct bookNode {
    struct bookNode *next;
    book book;
} typedef bookNode;

struct borrowNode {
    struct borrowNode *next;
    char title[32];
    char name[32];
} typedef borrowNode;

bookNode *createBookNode(book newBook) {
    bookNode *newBookNode = (bookNode *) malloc(sizeof(bookNode));
    newBookNode->book = newBook;
    newBookNode->next = NULL;
    return newBookNode;
}

bookNode *addBefore(bookNode *newBookNode, bookNode *inventoryList) {
    newBookNode->next = inventoryList;
    return newBookNode;
}

void freeMemory(bookNode *list) {
    if (list == NULL)
        return;
    freeMemory(list->next);

    free(list);

}

char *getString(enum genre genreType) {
    switch (genreType) {

        case 1:
            return "Horror";
        case 2:
            return "Abenteuer";
        case 3:
            return "Romantic";
        case 4:
            return "Sachbuch";

    }

    return 0;
}

void printUngueltigeEingabe() {
    printf("\nUngueltige Eingabe!");
}

book insertBook() {
    struct book newBook;
    newBook.title[31] = '\0';
    int input = 0;
    char charInput;

    while (1) {
        printf("\nGeben Sie den Titel ein: ");

        for (int i = 0; i < 32; ++i) {
            scanf("%c", &newBook.title[i]);
            if (newBook.title[i] == '\n' && i != 0){
                newBook.title[i] = '\0';
                break;
            }

        }


        break;

    }

    while (1) {
        printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4):");
        scanf("%d", &input);
        if (input < 1 || input > 4) {
            printUngueltigeEingabe();
            continue;
        }
        newBook.genre = input;
        break;
    }

    while (1) {
        printf("\nGeben Sie das Erscheinungsjahr ein:");
        scanf("%d", &input);

        if (input < 0) {
            printUngueltigeEingabe();
            continue;
        }
        newBook.year = input;
        break;
    }

    while (1) {
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        scanf("%d", &input);

        if (input < 0) {
            printUngueltigeEingabe();
            continue;
        }
        newBook.amount = input;
        break;
    }
    return newBook;

}

void borrowBook() {

}

void returnBook() {

}

void printList(bookNode inventoryList) {
    int i = 0;
    for (bookNode *n = &inventoryList; n != NULL; n = n->next) {
        i++;

        printf("\n%d: ", i);
        for (int j = 0; j < 32; ++j) {
            if (n->book.title[j] == '\0')
                break;

            printf("%c", n->book.title[j]);

        }
        printf(", %s (%d) ",getString(n->book.genre), n->book.year);

    }


}

void printListInOrder() {

}

int main() {
    struct bookNode *inventoryList = NULL;


    char input;

    while (1) {
        printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)");
        printf("\nAuswahl: ");
        scanf(" %c", &input);

        switch (input) {
            case 'n':
                inventoryList = addBefore(createBookNode(insertBook()), inventoryList);

                break;

            case 'b':
                borrowBook();


                break;

            case 'r':
                returnBook();

                break;

            case 'l':
                printList(*inventoryList);

                break;

            case 's':
                printListInOrder();

                break;

            case 'x':
                freeMemory(inventoryList);
                return 0;


            default:
                printUngueltigeEingabe();

                break;

        }


    }


    return 0;
}
