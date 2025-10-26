cmake_minimum_required(VERSION 4.0)
project(Coordinatrice C)

set(CMAKE_C_STANDARD 11)

add_executable(Coordinatrice main.c
        src/file.c
        src/indirizzo.c
        src/input.c
        src/database/aggiornamento.c
        src/database/database.c
        src/database/eliminazione.c
        src/database/lettura.c
        src/database/scrittura.c
        src/grafica/comandi.c
        src/grafica/grafica.c
        src/grafica/stampa.c)

# include il file di risorse Windows (.rc) per incorporare icona e informazioni di versione nell'eseguibile finale
set_source_files_properties(resources/resource.rc PROPERTIES LANGUAGE RC)
target_sources(Coordinatrice PRIVATE resources/resource.rc)

# aggiunge la cartella degli header ai search paths
target_include_directories(Coordinatrice PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
)