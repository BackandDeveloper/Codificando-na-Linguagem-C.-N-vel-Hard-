//Questão IX:
//Como implementar um coletor de lixo (garbage collector) básico em C?


#include <stdio.h>
#include <stdlib.h>

typedef struct Object {
    int ref_count;
    int value;
} Object;

Object* create_object(int value) {
    Object* obj = (Object*)malloc(sizeof(Object));
    obj->ref_count = 1;
    obj->value = value;
    return obj;
}

void retain(Object* obj) {
    obj->ref_count++;
}

void release(Object* obj) {
    if (--obj->ref_count == 0) {
        free(obj);
    }
}

int main() {
    Object* obj1 = create_object(42);
    retain(obj1);
    printf("Valor: %d, Contagem de Referências: %d\n", obj1->value, obj1->ref_count);
    release(obj1);
    release(obj1);
    return 0;
}
