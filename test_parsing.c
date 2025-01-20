#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> 
#include <string.h> 
#include <stdbool.h>
#include <errno.h>
#include <sys/stat.h> 
#include "./include/colors.h"
#include <unistd.h>

#define MAPS_DIRECTORY1 "maps/Good/" 
#define MAPS_DIRECTORY2 "maps/Bad/" 
#define CUB_EXECUTABLE "./cub3d" 


#define TERMINAL_WIDTH 100 // Largura do terminal
#define DELAY 30000        // Tempo de delay por frame (30ms)

// Variável de controle para o trem
int show_train = 1; // 1 = Funciona o trem, 0 = Após o trem, o resto do programa segue

void run_train(void)
{
    // Definição das linhas do "trem" com a nova mensagem
    char *train[] = {
        "            ___          _       ____     _          _____                 _     ",
        "    o O O / __|  _  _  | |__   |__ /  __| |   ___  |_   _|  ___    ___   | |_   ",
        "   o     | (__  | +| | | '_ \\   |_ \\ / _` |  |___|   | |   / -_)  (_-<   |  _|  ",
        "  TS__[O] \\___|  \\_,_| |_.__/  |___/ \\__,_|  _____  _|_|_  \\___|  /__/_  _\\__|  ",
        " {======_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|     _|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"| ",
        "./o--000\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-' "
    };

    int train_height = sizeof(train) / sizeof(char *); 
    int train_length = strlen(train[0]); 
    int frame = 0;

    int max_frame = TERMINAL_WIDTH + train_length;

    while (frame <= max_frame)
    {
        printf("\033[H\033[J");

        int row = 0;
        while (row < train_height)
        {
            int spaces = TERMINAL_WIDTH - frame; 

            int space_count = 0;
            while (space_count < spaces)
            {
                printf(" ");
                space_count++;
            }
            if (spaces + train_length > 0)
                printf(C"%s\n"RST, train[row]);
            else
                printf("\n"); 

            row++; // Avança para a próxima linha
        }
        printf(Y"\nAguarde, estamos rodando os testes...\n"RST);
        frame++;
        usleep(DELAY);
    }
    printf("\033[H\033[J");

    show_train = 0;
}


bool has_extension(const char *filename, const char *extension)
{
    size_t len = strlen(filename);
    size_t ext_len = strlen(extension);
    return len > ext_len && strcmp(filename + len - ext_len, extension) == 0;
}

void test_map_parsing(const char *map_path, const char *directory)
{
    char command[512];
    snprintf(command, sizeof(command), "%s %s > /dev/null 2>&1", CUB_EXECUTABLE, map_path);
    int exit_code = system(command);

    if (strcmp(directory, MAPS_DIRECTORY1) == 0)
    {
        if (exit_code == 0)
        {
            printf(G"\n[ PASS ] Mapa processado com sucesso: %s \n"RST, map_path);
        }
        else
        {
            printf(RED"\n[ NOT PASS ] Erro ao processar o mapa: %s\n"RST, map_path);
        }
    }
    else if (strcmp(directory, MAPS_DIRECTORY2) == 0)
    {
        if (exit_code != 0)
        {
            printf(G"\n[ PASS ] Erro esperado para o mapa: %s \n"RST, map_path);
        }
        else
        {
            printf(RED"\n[ NOT PASS ] Mapa processado com sucesso, mas deveria ter falhado: %s\n"RST, map_path);
        }
    }
}

void process_maps_in_directory(const char *directory)
{
    DIR *dir;
    struct dirent *ent;

    while(show_train)
        run_train();

    if ((dir = opendir(directory)) != NULL)
    {
        printf(B"\n\n *********** Testando mapas em %s: ***********\n"RST, directory);
        while ((ent = readdir(dir)) != NULL)
        {
            if (ent->d_name[0] == '.')
                continue;
            struct stat path_stat;
            char path[512];
            snprintf(path, sizeof(path), "%s%s", directory, ent->d_name);
            if (stat(path, &path_stat) != 0)
            {
                perror("Erro ao chamar stat");
                continue;
            }
            if (!S_ISDIR(path_stat.st_mode) && has_extension(ent->d_name, ".cub"))
            {
                test_map_parsing(path, directory);
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
    process_maps_in_directory(MAPS_DIRECTORY1);
    process_maps_in_directory(MAPS_DIRECTORY2);

    return EXIT_SUCCESS;
}