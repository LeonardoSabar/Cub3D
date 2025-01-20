#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // Para manipulação de diretórios
#include <string.h> // Para funções de string
#include <stdbool.h>

# define M      "\033[1;35m"   /* Bold Magenta */
# define RST    "\033[0m"      /* Reset to default color */

#define MAPS_DIRECTORY "maps/Good/" // Altere isso para o diretório onde estão seus mapas
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
    printf(M"Executando comando: %s\n"RST, command);
    int exit_code = system(command);
    if (exit_code != 0)
        printf("Erro ao processar o mapa: %s\n", map_path);
    else
        printf("Mapa processado com sucesso: %s\n", map_path);
}


int main()
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(MAPS_DIRECTORY)) != NULL)
    {
        printf("Testando mapas em %s:\n", MAPS_DIRECTORY);
        while ((ent = readdir(dir)) != NULL)
        {
            if (has_extension(ent->d_name, ".cub"))
            {
                char map_path[256];
                snprintf(map_path, sizeof(map_path), "%s%s", MAPS_DIRECTORY, ent->d_name);
                test_map_parsing(map_path);
            }
        }
        closedir(dir);
    }
    else
    {
        printf("mparse: %s\n", MAPS_DIRECTORY);
        perror("Não foi possível abrir o diretório");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}