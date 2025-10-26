#ifndef COMANDI_H
#define COMANDI_H

struct professore {
    char *nome;
    char *cognome;
    int sesso;
    int obiettivo;
    int ore;
    int minuti;
    int giorno;
    int mese;
    int anno;
};

extern void CancellazionePixel(int x, int y, int lunghezza);

extern void MaiuscMinusc(char *parola);

#endif //COMANDI_H
