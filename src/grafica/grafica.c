#include <stdio.h>
#include <windows.h>
#include "grafica/grafica.h"

// posizione specifica nello schermo
extern void GoToXY(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// stampa del pannello schermata iniziale
extern void BordiPannelloIndirizzo() {
    // prima riga
    GoToXY(1, 1);
    printf("%c", 201);

    for (size_t i = 0; i < X_INDIRIZZO - 4; ++i)
        printf("%c", 205);

    GoToXY(X_INDIRIZZO - 2, 1);
    printf("%c", 187);

    // righe centrali
    for (size_t i = 0; i < Y_INDIRIZZO - 4; ++i) {
        // colonna sinistra
        GoToXY(1, i + 2);
        printf("%c", 186);

        // colonna destra
        GoToXY(X_INDIRIZZO - 2, i + 2);
        printf("%c", 186);
    }

    // separatore in basso (orizzontale)
    GoToXY(3, 7);

    for (size_t i = 0; i < X_INDIRIZZO - 6; ++i)
        printf("%c", 196);

    // ultima riga
    GoToXY(1, Y_INDIRIZZO - 2);
    printf("%c", 200);

    for (size_t i = 0; i < X_INDIRIZZO - 4; ++i)
        printf("%c", 205);

    GoToXY(X_INDIRIZZO - 2, Y_INDIRIZZO - 2);
    printf("%c", 188);
}

// stampa del pannello schermata home
extern void BordiPannelloHome() {
    // prima riga
    GoToXY(1, 1);
    printf("%c", 201);

    for (size_t i = 0; i < X_HOME - 4; ++i)
        printf("%c", 205);

    GoToXY(X_HOME - 2, 1);
    printf("%c", 187);

    // righe centrali
    for (size_t i = 0; i < Y_HOME - 4; ++i) {
        // colonna sinistra
        GoToXY(1, i + 2);
        printf("%c", 186);

        // colonna destra
        GoToXY(X_HOME - 2, i + 2);
        printf("%c", 186);
    }

    // separatore in basso (orizzontale)
    GoToXY(3, 13);

    for (size_t i = 0; i < X_HOME - 6; ++i)
        printf("%c", 196);

    // ultima riga
    GoToXY(1, Y_HOME - 2);
    printf("%c", 200);

    for (size_t i = 0; i < X_HOME - 4; ++i)
        printf("%c", 205);

    GoToXY(X_HOME - 2, Y_HOME - 2);
    printf("%c", 188);
}

// stampa del pannello schermata numero professori
extern void BordiPannelloNumeroProfessori() {
    // prima riga
    GoToXY(1, 1);
    printf("%c", 201);

    for (size_t i = 0; i < X_NUMERO - 4; ++i)
        printf("%c", 205);

    GoToXY(X_NUMERO - 2, 1);
    printf("%c", 187);

    // righe centrali
    for (size_t i = 0; i < Y_NUMERO - 4; ++i) {
        // colonna sinistra
        GoToXY(1, i + 2);
        printf("%c", 186);

        // colonna destra
        GoToXY(X_NUMERO - 2, i + 2);
        printf("%c", 186);
    }

    // ultima riga
    GoToXY(1, Y_NUMERO - 2);
    printf("%c", 200);

    for (size_t i = 0; i < X_NUMERO - 4; ++i)
        printf("%c", 205);

    GoToXY(X_NUMERO - 2, Y_NUMERO - 2);
    printf("%c", 188);
}

// stampa del pannello schermata input
extern void BordiPannelloInput() {
    // prima riga
    GoToXY(1, 1);
    printf("%c", 201);

    for (size_t i = 0; i < X_INPUT - 4; ++i)
        printf("%c", 205);

    GoToXY(X_INPUT - 2, 1);
    printf("%c", 187);

    // righe centrali
    for (size_t i = 0; i < Y_INPUT - 4; ++i) {
        // colonna sinistra
        GoToXY(1, i + 2);
        printf("%c", 186);

        // colonna destra
        GoToXY(X_INPUT - 2, i + 2);
        printf("%c", 186);
    }

    // separatore in alto (orizzontale)
    GoToXY(3, 5);

    for (size_t i = 0; i < X_INPUT - 6; ++i)
        printf("%c", 196);

    // separatore (verticale)
    for (size_t i = 0; i < 11; ++i) {
        GoToXY(X_INPUT / 2 - 1, 6 + i);
        printf("%c", 179);
    }

    // ultima riga
    GoToXY(1, Y_INPUT - 2);
    printf("%c", 200);

    for (size_t i = 0; i < X_INPUT - 4; ++i)
        printf("%c", 205);

    GoToXY(X_INPUT - 2, Y_INPUT - 2);
    printf("%c", 188);
}

// stampa del pannello schermata eliminazione
extern void BordiPannelloEliminazione() {
    // prima riga
    GoToXY(1, 1);
    printf("%c", 201);

    for (size_t i = 0; i < X_ELIMINAZIONE - 4; ++i)
        printf("%c", 205);

    GoToXY(X_ELIMINAZIONE - 2, 1);
    printf("%c", 187);

    // righe centrali
    for (size_t i = 0; i < Y_ELIMINAZIONE - 4; ++i) {
        // colonna sinistra
        GoToXY(1, i + 2);
        printf("%c", 186);

        // colonna destra
        GoToXY(X_ELIMINAZIONE - 2, i + 2);
        printf("%c", 186);
    }

    // separatore in alto (orizzontale)
    GoToXY(3, 5);

    for (size_t i = 0; i < X_ELIMINAZIONE - 6; ++i)
        printf("%c", 196);

    // separatore in basso a destra (orizzontale)
    GoToXY(X_ELIMINAZIONE / 2 + 1, 18);

    for (size_t i = 0; i < X_ELIMINAZIONE / 2 - 4; ++i)
        printf("%c", 196);

    // separatore (verticale)
    for (size_t i = 0; i < 16; ++i) {
        GoToXY(X_ELIMINAZIONE / 2 - 1, 6 + i);
        printf("%c", 179);
    }

    // ultima riga
    GoToXY(1, Y_ELIMINAZIONE - 2);
    printf("%c", 200);

    for (size_t i = 0; i < X_ELIMINAZIONE - 4; ++i)
        printf("%c", 205);

    GoToXY(X_ELIMINAZIONE - 2, Y_ELIMINAZIONE - 2);
    printf("%c", 188);
}

// stampa opzioni utili nella schermata input indirizzo
extern void SuggerimentiIndirizzo() {
    // stampa uscita '0'
    GoToXY(15, Y_INDIRIZZO - 4);
    printf("- Inserisci '0' se desideri uscire dal programma");
}

// stampa opzioni utili nella schermata eliminazione
extern void SuggerimentiEliminazione() {
    // stampa titolo istruzioni
    GoToXY(47, 7);
    printf("Istruzioni delle pagine:");

    // stampa istruzioni eliminazione
    GoToXY(45, 9);
    printf("- Inserisci il 'numero' corrispondente");
    GoToXY(47, 10);
    printf("al professore che vuoi eliminare");

    // stampa scorrimento in avanti di una pagina
    GoToXY(45, 12);
    printf("- Inserisci '+' per andare avanti");

    // stampa scorrimento indietro di una pagina
    GoToXY(45, 14);
    printf("- Inserisci '-' per andare indietro");

    // uscita dalla pagina
    GoToXY(45, 16);
    printf("- Inserisci '0' per uscire");
}
