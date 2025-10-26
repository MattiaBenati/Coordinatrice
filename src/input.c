#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "input.h"
#include "grafica/grafica.h"

// input caso da analizzare
extern int InputCaso() {
    int caso;

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(15, 11);
    printf("Inserisci il numero:");

    GoToXY(36, 11);
    scanf("%s", input);

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] < 48 || input[i] > 57) {
            check = false;
            break;
        }
    }

    caso = atoi(input);

    if (caso != 0 && caso != 1 && caso != 2 && caso != 3)
        check = false;

    free(input);

    // errore di immissione
    if (check == false)
        return -1;

    return caso;
}

// input indice del professore da eliminare
extern int InputEliminazione(int k, int pagina) {
    int indice;

    GoToXY(47, 20);
    printf("Inserisci il caso:");

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(66, 20);
    scanf("%s", input);

    // '0' = uscita programma
    // '-1' = errore
    // '-2' = '+'
    // '-3' = '-'

    if (strlen(input) == 1) {
        if (input[0] == '+') {
            free(input);
            return -2;
        } else if (input[0] == '-') {
            free(input);
            return -3;
        }
    }

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] < 48 || input[i] > 57) {
            check = false;
            break;
        }
    }

    indice = atoi(input);

    if (indice < 0 || indice > k)
        check = false;

    else if (indice != 0 && (indice < pagina * 6 || indice > (pagina + 1) * 6))
        check = false;

    // errore di immissione
    if (check == false)
        return -1;

    return indice;
}

// input numero di professori da analizzare
extern int InputNumeroProfessori() {
    int n;

    GoToXY(25, 3);
    printf("Quanti professori vuoi analizzare?");

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(25, 5);
    printf("Inserisci il numero: ");
    scanf("%s", input);

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] < 48 || input[i] > 57) {
            check = false;
            break;
        }
    }

    n = atoi(input);

    free(input);

    // errore di immissione
    if (check == false)
        return -1;

    return n;
}

// input nome del professore
extern char *InputNome() {
    char *nome = calloc(100, sizeof(char));

    GoToXY(24, 7);
    scanf("\n%[^\n]", nome);

    for (size_t i = 0; i < strlen(nome); ++i) {
        // errore di immissione
        if (nome[i] != '\'' && nome[i] != ' ' && (nome[i] < 65 || nome[i] > 122
                                                  || (nome[i] > 90 && nome[i] < 97))) {
            free(nome);
            return "0";
        }

        // da MAIUSCOLA a minuscola
        if (nome[i] <= 90 && nome[i] >= 65)
            nome[i] += 32;
    }

    // eliminazione spazi (fine parola)
    for (size_t i = strlen(nome) - 1; i > 0 && nome[i] == ' '; --i)
        nome[i] = 0;

    nome = realloc(nome, (strlen(nome) + 1) * sizeof(char));
    nome[strlen(nome)] = 0;

    return nome;
}

// input cognome del professore
extern char *InputCognome() {
    char *cognome = calloc(100, sizeof(char));

    GoToXY(27, 9);
    scanf("\n%[^\n]", cognome);

    for (size_t i = 0; i < strlen(cognome); ++i) {
        // errore di immissione
        if (cognome[i] != '\'' && cognome[i] != ' ' && (cognome[i] < 65 || cognome[i] > 122
                                                        || (cognome[i] > 90 && cognome[i] < 97))) {
            free(cognome);
            return "0";
        }

        // da MAIUSCOLA a minuscola
        if (cognome[i] <= 90 && cognome[i] >= 65)
            cognome[i] += 32;
    }

    // eliminazione spazi (fine parola)
    for (size_t i = strlen(cognome) - 1; i > 0 && cognome[i] == ' '; --i)
        cognome[i] = 0;

    cognome = realloc(cognome, (strlen(cognome) + 1) * sizeof(char));
    cognome[strlen(cognome)] = 0;

    return cognome;
}

// input sesso del professore
extern int InputSesso() {
    int sesso;

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(25, 11);
    scanf("%s", input);

    if (strlen(input) > 1)
        check = false;

    else if (input[0] != '1' && input[0] != '2')
        check = false;

    sesso = atoi(input);

    free(input);

    // errore di immissione
    if (check == false)
        return -1;

    return sesso - 1;
}

// input obiettivo mensile del professore
extern int InputObiettivo() {
    int obiettivo;

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(36, 15);
    scanf("%s", input);

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] < 48 || input[i] > 57) {
            check = false;
            break;
        }
    }

    obiettivo = atoi(input);

    free(input);

    // errore di immissione
    if (check == false)
        return -1;

    return obiettivo;
}

// input ore del professore
extern int InputOre() {
    int ore;

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(65, 7);
    scanf("%s", input);

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] < 48 || input[i] > 57) {
            check = false;
            break;
        }
    }

    ore = atoi(input);

    free(input);

    // errore di immissione
    if (check == false)
        return -1;

    return ore;
}

// input minuti del professore
extern int InputMinuti() {
    int minuti;

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(67, 9);
    scanf("%s", input);

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] < 48 || input[i] > 57) {
            check = false;
            break;
        }
    }

    minuti = atoi(input);

    free(input);

    // errore di immissione
    if (check == false)
        return -1;

    return minuti;
}

// input giorno del professore
extern int InputGiorno() {
    int giorno;

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(68, 11);
    scanf("%s", input);

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] < 48 || input[i] > 57) {
            check = false;
            break;
        }
    }

    giorno = atoi(input);

    if (giorno <= 0)
        check = false;

    else if (giorno > 31)
        check = false;

    free(input);

    // errore di immissione
    if (check == false)
        return -1;

    return giorno;
}

// input mese del professore
extern int InputMese() {
    int mese;

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(66, 13);
    scanf("%s", input);

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] < 48 || input[i] > 57) {
            check = false;
            break;
        }
    }

    mese = atoi(input);

    if (mese <= 0)
        check = false;

    else if (mese > 12)
        check = false;

    free(input);

    // errore di immissione
    if (check == false)
        return -1;

    return mese;
}

// input anno del professore
extern int InputAnno() {
    int anno;

    char *input = calloc(100, sizeof(char));
    bool check = true;

    GoToXY(65, 15);
    scanf("%s", input);

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] < 48 || input[i] > 57) {
            check = false;
            break;
        }
    }

    anno = atoi(input);

    if (anno <= 1900)
        check = false;

    free(input);

    // errore di immissione
    if (check == false)
        return -1;

    return anno;
}
