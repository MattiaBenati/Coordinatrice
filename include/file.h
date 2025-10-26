#ifndef FILE_H
#define FILE_H
#include <stdbool.h>

extern void ScritturaOrarioSessioni(char *nome, char *cognome, char *cartella, int sesso,
                                    int ore, int minuti, int giorno, int mese, int anno, bool check);

extern void ScritturaOrarioTotale(char *nome, char *cognome, char *cartella, int sesso, int obiettivo,
                                  int ore, int minuti, int giorno, int mese, int anno);

#endif //FILE_H
