#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

// scrittura nel file .txt "Orario sessioni"
extern void ScritturaOrarioSessioni(char *nome, char *cognome, char *cartella, int sesso,
                                    int ore, int minuti, int giorno, int mese, int anno, bool check) {
    char *indirizzo = calloc(300, sizeof(char));
    strcat(indirizzo, cartella);
    strcat(indirizzo, "\\");
    strcat(indirizzo, nome);
    strcat(indirizzo, " ");
    strcat(indirizzo, cognome);
    strcat(indirizzo, "\\Orario sessioni.txt");

    // apertura file
    FILE *file = fopen(indirizzo, "a");

    // introduzione
    if (check == false) {
        // maschio
        if (sesso == 0)
            fprintf(file, "\n Ecco l'orario sessioni del Professore %s %s:\n\n", cognome, nome);
            // femmina
        else
            fprintf(file, "\n Ecco l'orario sessioni della Professoressa %s %s:\n\n", cognome, nome);
    }

    if (ore == 0 && minuti == 0) {
        fclose(file);
        free(indirizzo);

        return;
    }

    if (ore != 1 && minuti != 1) {
        fprintf(file, "| %s %s, in data %d/%d/%d, ha compiuto:\n\n", cognome, nome, giorno, mese, anno);
        fprintf(file, "\t- %d ore\n", ore);
        fprintf(file, "\t- %d minuti\n\n", minuti);
    } else if (ore != 1 && minuti == 1) {
        fprintf(file, "| %s %s, in data %d/%d/%d, ha compiuto:\n\n", cognome, nome, giorno, mese, anno);
        fprintf(file, "\t- %d ore\n", ore);
        fprintf(file, "\t- %d minuto\n\n", minuti);
    } else if (ore == 1 && minuti != 1) {
        fprintf(file, "| %s %s, in data %d/%d/%d, ha compiuto:\n\n", cognome, nome, giorno, mese, anno);
        fprintf(file, "\t- %d ora\n", ore);
        fprintf(file, "\t- %d minuti\n\n", minuti);
    } else if (ore == 1 && minuti == 1) {
        fprintf(file, "| %s %s, in data %d/%d/%d, ha compiuto:\n\n", cognome, nome, giorno, mese, anno);
        fprintf(file, "\t- %d ora\n", ore);
        fprintf(file, "\t- %d minuto\n\n", minuti);
    }

    fclose(file);
    free(indirizzo);
}

// scrittura nel file .txt "Orario totale"
extern void ScritturaOrarioTotale(char *nome, char *cognome, char *cartella, int sesso, int obiettivo,
                                  int ore, int minuti, int giorno, int mese, int anno) {
    char *indirizzo = calloc(300, sizeof(char));
    strcat(indirizzo, cartella);
    strcat(indirizzo, "\\");
    strcat(indirizzo, nome);
    strcat(indirizzo, " ");
    strcat(indirizzo, cognome);
    strcat(indirizzo, "\\Orario totale.txt");

    // apertura file
    FILE *file = fopen(indirizzo, "w");

    // maschio
    if (sesso == 0)
        fprintf(file, "\n Ecco l'orario totale del Professore %s %s:\n\n", cognome, nome);
        // femmina
    else
        fprintf(file, "\n Ecco l'orario totale della Professoressa %s %s:\n\n", cognome, nome);

    if (ore != 1 && minuti != 1) {
        fprintf(file, "| %s %s, fino alla data %d/%d/%d, ha compiuto:\n\n", cognome, nome, giorno, mese, anno);
        fprintf(file, "\t- %d ore\n", ore);
        fprintf(file, "\t- %d minuti\n\n", minuti);
    } else if (ore != 1 && minuti == 1) {
        fprintf(file, "| %s %s, fino alla data %d/%d/%d, ha compiuto:\n\n", cognome, nome, giorno, mese, anno);
        fprintf(file, "\t- %d ore\n", ore);
        fprintf(file, "\t- %d minuto\n\n", minuti);
    } else if (ore == 1 && minuti != 1) {
        fprintf(file, "| %s %s, fino alla data %d/%d/%d, ha compiuto:\n\n", cognome, nome, giorno, mese, anno);
        fprintf(file, "\t- %d ora\n", ore);
        fprintf(file, "\t- %d minuti\n\n", minuti);
    } else if (ore == 1 && minuti == 1) {
        fprintf(file, "| %s %s, fino alla data %d/%d/%d, ha compiuto:\n\n", cognome, nome, giorno, mese, anno);
        fprintf(file, "\t- %d ora\n", ore);
        fprintf(file, "\t- %d minuto\n\n", minuti);
    }

    // righe separatrici
    for (size_t i = 0; i < 28; ++i) {
        fprintf(file, " -");
        if (i == 27)
            fprintf(file, "\n\n");
    }

    // all'utente mancano ore al raggiungimento dell'obiettivo
    if (ore < obiettivo) {
        size_t hours_remaining;
        size_t minutes_remaining;

        if (minuti == 0) {
            hours_remaining = obiettivo - ore;
            minutes_remaining = minuti;
        } else {
            hours_remaining = obiettivo - ore - 1;
            minutes_remaining = 60 - minuti;
        }

        if (hours_remaining != 1 && minutes_remaining != 1) {
            fprintf(file, "| %s %s deve ancora svolgere:\n\n", cognome, nome);
            fprintf(file, "\t- %d ore\n", hours_remaining);
            fprintf(file, "\t- %d minuti\n", minutes_remaining);
        } else if (hours_remaining != 1 && minutes_remaining == 1) {
            fprintf(file, "| %s %s deve ancora svolgere:\n\n", cognome, nome);
            fprintf(file, "\t- %d ore\n", hours_remaining);
            fprintf(file, "\t- %d minuto\n", minutes_remaining);
        } else if (hours_remaining == 1 && minutes_remaining != 1) {
            fprintf(file, "| %s %s deve ancora svolgere:\n\n", cognome, nome);
            fprintf(file, "\t- %d ora\n", hours_remaining);
            fprintf(file, "\t- %d minuti\n", minutes_remaining);
        } else if (hours_remaining == 1 && minutes_remaining == 1) {
            fprintf(file, "| %s %s deve ancora svolgere:\n\n", cognome, nome);
            fprintf(file, "\t- %d ora\n", hours_remaining);
            fprintf(file, "\t- %d minuto\n", minutes_remaining);
        }
    }

    // l'utente ha raggiunto l'obiettivo
    else if (ore == obiettivo && minuti == 0) {
        fprintf(file, "| %s %s, in data %d/%d/%d, ha raggiunto l'obiettivo di %d ore!",
                cognome, nome, giorno, mese, anno, obiettivo);
    }

    // l'utente è in straordinario
    else {
        size_t hours_extraordinary = ore - obiettivo;
        size_t minutes_extraordinary = minuti;

        if (hours_extraordinary != 1 && minutes_extraordinary != 1) {
            fprintf(file, "| %s %s e' in straordinario di:\n\n", cognome, nome);
            fprintf(file, "\t- %d ore\n", hours_extraordinary);
            fprintf(file, "\t- %d minuti", minutes_extraordinary);
        } else if (hours_extraordinary != 1 && minutes_extraordinary == 1) {
            fprintf(file, "| %s %s e' in straordinario di:\n\n", cognome, nome);
            fprintf(file, "\t- %d ore\n", hours_extraordinary);
            fprintf(file, "\t- %d minuto", minutes_extraordinary);
        } else if (hours_extraordinary == 1 && minutes_extraordinary != 1) {
            fprintf(file, "| %s %s e' in straordinario di:\n\n", cognome, nome);
            fprintf(file, "\t- %d ora\n", hours_extraordinary);
            fprintf(file, "\t- %d minuti", minutes_extraordinary);
        } else if (hours_extraordinary == 1 && minutes_extraordinary == 1) {
            fprintf(file, "| %s %s e' in straordinario di:\n\n", cognome, nome);
            fprintf(file, "\t- %d ora\n", hours_extraordinary);
            fprintf(file, "\t- %d minuto", minutes_extraordinary);
        }
    }

    fclose(file);
    free(indirizzo);
}
