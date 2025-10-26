#ifndef DATABASE_H
#define DATABASE_H

extern void CartellaDatabase();

extern void FileDatabase(char *nome, char *cognome);

extern char *IndirizzoCartella();

extern void CartellaProfessore(char *nome, char *cognome, char *cartella);

extern void FileOrarioSessioni(char *nome, char *cognome, char *cartella);

extern void FileOrarioTotale(char *nome, char *cognome, char *cartella);

#endif //DATABASE_H
