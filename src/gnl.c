#include "../include/cub3d.h"

#define BUFFER_SIZE 42 // Defina o tamanho do buffer conforme necessário

static char *read_line(int fd, char *buffer) {
    int bytes_read;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0) {
        return NULL; // EOF ou erro
    }
    buffer[bytes_read] = '\0'; // Null-terminate the string
    return buffer;
}

static char *extract_line(char *buffer) {
    char *line;
    int i = 0;

    while (buffer[i] && buffer[i] != '\n') {
        i++;
    }

    line = (char *)malloc(i + (buffer[i] == '\n' ? 2 : 1)); // +1 para o \0, +1 se houver \n
    if (!line) {
        return NULL;
    }

    for (int j = 0; j < i; j++) {
        line[j] = buffer[j];
    }
    line[i] = (buffer[i] == '\n') ? '\n' : '\0';
    return line;
}

char *get_next_line_call(int fd) {
    static char buffer[BUFFER_SIZE + 1];
    char *line;
    char *temp_buffer = read_line(fd, buffer);

    if (!temp_buffer) {
        return NULL; // EOF ou erro
    }

    line = extract_line(buffer);
    return line;
}

char *get_next_line(int fd) {
    char *line;

    while ((line = get_next_line_call(fd))) { // Mudança aqui para chamar get_next_line_call
        printf("%s", line);
        free(line);
    }
    return NULL; // Retorna NULL no final
}