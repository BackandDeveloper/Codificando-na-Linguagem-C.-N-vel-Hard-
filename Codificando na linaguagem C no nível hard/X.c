// Questão X:
// Como implementar um interpretador de uma linguagem de programação simples em C?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARS 100
#define MAX_VAR_NAME 100

typedef struct Variable {
    char name[MAX_VAR_NAME];
    int value;
} Variable;

Variable vars[MAX_VARS];
int var_count = 0;

Variable* find_var(const char* name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(vars[i].name, name) == 0) {
            return &vars[i];
        }
    }
    return NULL;
}

void set_var(const char* name, int value) {
    Variable* var = find_var(name);
    if (var) {
        var->value = value;
    } else {
        strncpy(vars[var_count].name, name, MAX_VAR_NAME);
        vars[var_count].value = value;
        var_count++;
    }
}

int eval_expr(const char* expr) {
    char var_name[MAX_VAR_NAME];
    int value;
    if (sscanf(expr, "%s = %d", var_name, &value) == 2) {
        set_var(var_name, value);
        return value;
    } else if (sscanf(expr, "%s", var_name) == 1) {
        Variable* var = find_var(var_name);
        if (var) {
            return var->value;
        }
    }
    return 0;
}

int main() {
    char line[256];
    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        int result = eval_expr(line);
        printf("Resultado: %d\n", result);
    }
    return 0;
}
