#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // Para manipulação de diretórios
#include <string.h> // Para funções de string
#include <stdbool.h>
#include <errno.h>
#include <sys/stat.h> // Necessário para a função stat
#include "./include/colors.h"

// Compilar usando o comando: gcc -o test_maps test_maps.c

#define MAPS_DIRECTORY1 "maps/Good/" // Primeiro diretório onde estão seus mapas
#define MAPS_DIRECTORY2 "maps/Bad/" // Segundo diretório onde estão seus mapas
#define CUB_EXECUTABLE "./cub3d" // O nome do seu executável

// Função para verificar se um arquivo tem a extensão correta
bool has_extension(const char *filename, const char *extension)
{
    size_t len = strlen(filename);
    size_t ext_len = strlen(extension);
    return len > ext_len && strcmp(filename + len - ext_len, extension) == 0;
}

void test_map_parsing(const char *map_path)
{
    char command[512];
    snprintf(command, sizeof(command), "%s %s", CUB_EXECUTABLE, map_path);
    int exit_code = system(command);
    if (exit_code != 0)
    {
        printf(RED"\n[  x  ] Erro ao processar o mapa: %s\n\n"RST, map_path);
    }
    else
        printf(G"\n[PASS] Mapa processado com sucesso: %s \n\n"RST, map_path);
}

void process_maps_in_directory(const char *directory)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(directory)) != NULL)
    {
        printf(B"\nTestando mapas em %s:\n\n"RST, directory);
        while ((ent = readdir(dir)) != NULL)
        {
            // Ignorar pastas ocultas (iniciadas com .)
            if (ent->d_name[0] == '.')
                continue; // Pular entrada que começa com '.'

            // Verificação se é um diretório usando stat
            struct stat path_stat;
            char path[512];
            snprintf(path, sizeof(path), "%s%s", directory, ent->d_name);
            if (stat(path, &path_stat) != 0)
            {
                perror("Erro ao chamar stat");
                continue; // Se houver erro, passa para a próxima entrada
            }

            // Se não é um diretório, testamos a extensão
            if (!S_ISDIR(path_stat.st_mode) && has_extension(ent->d_name, ".cub"))
            {
                test_map_parsing(path);
            }
        }
        closedir(dir);
    }
    else
    {
        printf("mparse: %s\n", directory);
        perror("Não foi possível abrir o diretório");
    }
}

int main()
{
    // Processa mapas nos dois diretórios
    process_maps_in_directory(MAPS_DIRECTORY1);
    process_maps_in_directory(MAPS_DIRECTORY2);

    return EXIT_SUCCESS;
}