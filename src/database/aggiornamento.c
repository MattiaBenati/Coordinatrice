#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database/aggiornamento.h"
#include "grafica/comandi.h"

// aggiornamento database (sesso, obiettivo, ore, minuti, giorno, mese, anno)
extern void AggiornamentoDatabase(char *nome, char *cognome, int obiettivo, int *ore, int *minuti,
                                  int *giorno, int *mese, int *anno) {
    char *indirizzo = calloc(300, sizeof(char));
    strcat(indirizzo, "C:\\ProgramData\\coordinatrice\\");
    strcat(indirizzo, nome);
    strcat(indirizzo, " ");
    strcat(indirizzo, cognome);
    strcat(indirizzo, ".txt");

    // apertura file
    FILE *file_lettura = fopen(indirizzo, "r");

    struct professore *professori = malloc(sizeof(struct professore)); // struct temporanea
    professori->nome = nome;
    professori->cognome = cognome;

    // lettura dati dal file .txt
    fscanf(file_lettura, "%d\n%d\n%d\n%d\n%d\n%d\n%d", &professori->sesso, &professori->obiettivo,
           &professori->ore, &professori->minuti, &professori->giorno, &professori->mese, &professori->anno);

    fclose(file_lettura);

    // apertura file
    FILE *file_scrittura = fopen(indirizzo, "w");

    // aggiornamento obiettivo, ore, minuti ed ultima data
    professori->minuti += *minuti;

    if (professori->minuti >= 60) {
        professori->ore += 1;
        professori->minuti -= 60;
    }

    professori->ore += *ore;
    professori->obiettivo = obiettivo;

    // sostituzione ultima data
    if (*anno > professori->anno || (*anno <= professori->anno && *mese > professori->mese)
        || (*anno <= professori->anno && *mese <= professori->mese && *giorno > professori->giorno)) {
        fprintf(file_scrittura, "%d\n%d\n%d\n%d\n%d\n%d\n%d", professori->sesso, professori->obiettivo,
                professori->ore, professori->minuti, *giorno, *mese, *anno);
    }

    // mantenimento ultima data
    else {
        fprintf(file_scrittura, "%d\n%d\n%d\n%d\n%d\n%d\n%d", professori->sesso, professori->obiettivo,
                professori->ore, professori->minuti, professori->giorno, professori->mese, professori->anno);

        // aggiornamento dati
        int day = professori->giorno;
        int month = professori->mese;
        int year = professori->anno;

        *giorno = day;
        *mese = month;
        *anno = year;
    }

    // aggiornamento dati
    int hours = professori->ore;
    int minutes = professori->minuti;

    *ore = hours;
    *minuti = minutes;

    fclose(file_scrittura);
    free(professori);
}
