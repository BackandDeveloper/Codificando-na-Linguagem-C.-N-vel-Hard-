// Questão VI:
// Como implementar uma tabela hash com tratamento de colisões por encadeamento em C?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

unsigned int hash(char* key) {
    unsigned int hash = 0;
    while (*key) hash = (hash << 5) + *key++;
    return hash % TABLE_SIZE;
}

void insert(char* key, int value) {
    unsigned int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(char* key) {
    unsigned int index = hash(key);
    Node* node = hashTable[index];
    while (node) {
        if (strcmp(node->key, key) == 0) return node->value;
        node = node->next;
    }
    return -1;
}

int main() {
    insert("chave1", 1);
    insert("chave2", 2);
    insert("chave3", 3);
    printf("Valor para 'chave1': %d\n", search("chave1"));
    printf("Valor para 'chave2': %d\n", search("chave2"));
    printf("Valor para 'chave3': %d\n", search("chave3"));
    return 0;
}
