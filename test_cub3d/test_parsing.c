#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include "test_parsing_colors.h"

#define MAPS_DIRECTORY1 "./maps/Good/"
#define MAPS_DIRECTORY2 "./maps/Bad/"
#define CUB_EXECUTABLE ".././cub3d"

#define TERMINAL_WIDTH 100 // Largura do terminal
#define DELAY 30000        // Tempo de delay do trem (30ms)
#define TEST_DELAY 300000  // Delay entre testes (0.3s)

// Contadores globais de resultados
int pass_count = 0; 
int not_pass_count = 0;

// Controle para o trem
int show_train = 1;

void run_train(void)
{
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
                printf(C "%s\n" RST, train[row]);
            else
                printf("\n");

            row++;
        }
        printf(Y"\n_________________________________________ Aguarde, estamos rodando os testes...\n" RST);
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
            printf("\n\033[1;32m[ PASS ] Mapa processado com sucesso: %s \033[0m\n", map_path);
            pass_count++;
        }
        else
        {
            printf("\n\033[1;31m[ NOT PASS ] Erro ao processar o mapa: %s\033[0m\n", map_path);
            not_pass_count++;
        }
    }
    else if (strcmp(directory, MAPS_DIRECTORY2) == 0)
    {
        if (exit_code != 0)
        {
            printf("\n\033[1;32m[ PASS ] Erro esperado para o mapa: %s \033[0m\n", map_path);
            pass_count++;
        }
        else
        {
            printf("\n\033[1;31m[ NOT PASS ] Mapa processado com sucesso, mas deveria ter falhado: %s\033[0m\n", map_path);
            not_pass_count++;
        }
    }
    usleep(TEST_DELAY);
}

void process_maps_in_directory(const char *directory)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(directory)) != NULL)
    {
        printf(B "\n\n ************** Testando mapas em %s: **************\n" RST, directory);
        while ((ent = readdir(dir)) != NULL)
        {
            if (ent->d_name[0] == '.')
                continue;
            struct stat path_stat;
            char path[512];
            snprintf(path, sizeof(path), "%s%s", directory, ent->d_name);
            if (stat(path, &path_stat) != 0)
            {
                perror(RED "Erro ao chamar stat" RST);
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
        printf(RED "\nErro ao abrir diretório %s\n" RST, directory);
        perror(RED "Não foi possível abrir o diretório"RST);
    }
}

int main()
{
    while (show_train)
        run_train();

    process_maps_in_directory(MAPS_DIRECTORY1);
    process_maps_in_directory(MAPS_DIRECTORY2);

    // Exibe os resultados finais
    printf("\n\033[1;34m************** RESULTADO FINAL: **************\033[0m\n");
    printf("\033[1;32m[    PASS   ]: %d\033[0m\n", pass_count);
    printf("\033[1;31m[ NOT  PASS ]: %d\033[0m\n", not_pass_count);

    return EXIT_SUCCESS;
}