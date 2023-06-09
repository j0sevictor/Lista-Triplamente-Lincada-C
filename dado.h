#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* nomeCidade;
    float idh;
    float area;
    int populacao;
} elemento;

elemento* criaElemento(char* nome, float idh, float area, int populacao);
void freeElemento(elemento* elem);
int equals(elemento* e1, elemento* e2);

elemento* criaElemento(char* nome, float idh, float area, int populacao)
{
    elemento* elem = (elemento*) malloc(sizeof(elemento));
    if (elem == NULL)
    {
        return NULL;
    }

    strcpy(elem->nomeCidade, nome);
    elem->idh = idh;
    elem->area = area;
    elem->populacao = populacao;

    return elem;
}

void freeElemento(elemento* elem)
{
    if (elem == NULL){
        return;
    }

    if (elem->nomeCidade != NULL)
    {
        free(elem->nomeCidade);
    }

    free(elem);
}

int equals(elemento* e1, elemento* e2)
{
    return strcmp(e1->nomeCidade, e2->nomeCidade) == 0;
}