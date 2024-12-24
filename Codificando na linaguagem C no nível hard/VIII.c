//Questão VII:
//Como implementar um sistema de arquivos virtual em C?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 100
#define MAX_FILESIZE 1024

typedef struct File {
    char name[MAX_FILENAME];
    char data[MAX_FILESIZE];
    int size;
} File;

File* filesystem[MAX_FILES];
int file_count = 0;

File* create_file(const char* name) {
    if (file_count >= MAX_FILES) return NULL;
    File* file = (File*)malloc(sizeof(File));
    strncpy(file->name, name, MAX_FILENAME);
    file->size = 0;
    filesystem[file_count++] = file;
    return file;
}

File* find_file(const char* name) {
    for (int i = 0; i < file_count; i++) {
        if (strncmp(filesystem[i]->name, name, MAX_FILENAME) == 0) {
            return filesystem[i];
        }
    }
    return NULL;
}

void write_file(File* file, const char* data) {
    strncpy(file->data, data, MAX_FILESIZE);
    file->size = strlen(data);
}

void read_file(File* file) {
    printf("Conteúdo do arquivo '%s': %s\n", file->name, file->data);
}

int main() {
    File* file1 = create_file("arquivo1.txt");
    write_file(file1, "Olá, mundo!");
    read_file(file1);

    File* file2 = create_file("arquivo2.txt");
    write_file(file2, "Este é um sistema de arquivos virtual.");
    read_file(file2);

    return 0;
}
