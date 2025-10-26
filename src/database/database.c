#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <direct.h>	// per '_mkdir'
#include "database/database.h"
#include "grafica/grafica.h"
#include "dirent.h"

// creazione cartella "coordinatrice"
extern void CartellaDatabase()
{
	// creazione cartella nel caso non esistesse
	if (_mkdir("C:\\ProgramData\\coordinatrice") == 0);
}

// creazione file .txt "nome cognome"
extern void FileDatabase(char* nome, char* cognome)
{
	char* indirizzo = calloc(300, sizeof(char));
	strcat(indirizzo, "C:\\ProgramData\\coordinatrice\\");
	strcat(indirizzo, nome);
	strcat(indirizzo, " ");
	strcat(indirizzo, cognome);
	strcat(indirizzo, ".txt");

	// creazione file "nome cognome.txt"
	FILE* file = fopen(indirizzo, "a");
	fclose(file);

	free(indirizzo);
}

// aggiornamento formato indirizzo
static void EliminazioneVirgolette(char* indirizzo)
{
	for (size_t i = 0; indirizzo[i] != 0; ++i)
	{
		if (indirizzo[i] == '"' || indirizzo[i] == '\n')
		{
			for (size_t j = i; indirizzo[j] != 0; ++j)
				indirizzo[j] = indirizzo[j + 1];

			if (i != 0)
				i -= 1;
		}
	}
}

// input indirizzo cartella desktop
extern char* IndirizzoCartella()
{
	char* indirizzo = calloc(300, sizeof(char));

	GoToXY(17, 3);
	printf("Inserisci l'indirizzo della cartella presa in esame:");

	GoToXY(17, 5);
	scanf("\n%[^\n]", indirizzo);

	// aggiornamento indirizzo
	EliminazioneVirgolette(indirizzo);

	// verifica esistenza della directory (cartella)
	DIR* directory = opendir(indirizzo);

	if (indirizzo[0] != '0' && directory == NULL)
		indirizzo[0] = '1';

	return indirizzo;
}

// creazione cartella del professore/professoressa
extern void CartellaProfessore(char* nome, char* cognome, char* cartella)
{
	char* indirizzo = calloc(300, sizeof(char));

	// indirizzo
	strcat(indirizzo, cartella);
	strcat(indirizzo, "\\");
	strcat(indirizzo, nome);
	strcat(indirizzo, " ");
	strcat(indirizzo, cognome);

	if (_mkdir(indirizzo) == 0);

	free(indirizzo);
}

// creazione file .txt "Orario sessioni"
extern void FileOrarioSessioni(char* nome, char* cognome, char* cartella)
{
	char* indirizzo = calloc(300, sizeof(char));

	// indirizzo
	strcat(indirizzo, cartella);
	strcat(indirizzo, "\\");
	strcat(indirizzo, nome);
	strcat(indirizzo, " ");
	strcat(indirizzo, cognome);
	strcat(indirizzo, "\\Orario sessioni.txt");

	FILE* file = fopen(indirizzo, "a");
	fclose(file);

	free(indirizzo);
}

// creazione file .txt "Orario totale"
extern void FileOrarioTotale(char* nome, char* cognome, char* cartella)
{
	char* indirizzo = calloc(300, sizeof(char));

	// indirizzo
	strcat(indirizzo, cartella);
	strcat(indirizzo, "\\");
	strcat(indirizzo, nome);
	strcat(indirizzo, " ");
	strcat(indirizzo, cognome);
	strcat(indirizzo, "\\Orario totale.txt");

	FILE* file = fopen(indirizzo, "a");
	fclose(file);

	free(indirizzo);
}