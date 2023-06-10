#include <stdlib.h>
#include <string.h>

#define NUM_PARAM 3

#define IDH 0
#define AREA 1
#define POPULACAO 2

typedef int PARAMETRO;

typedef struct
{
    char nomeCidade[64];
    float idh;
    float area;
    int populacao;
} elemento;

elemento* criaElemento(char* nome, float idh, float area, int populacao);
void freeElemento(elemento* elem);
int equals(elemento* e1, elemento* e2);
int compare(elemento* e1, elemento* e2, PARAMETRO p);

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

int compare(elemento* e1, elemento* e2, PARAMETRO p)
{
    switch (p)
    {
        case IDH:
            if (e1->idh > e2->idh)
            {
                return 1;
            }
            else if (e1->idh == e2->idh)
            {
                return 0;
            }
            else
            {
                return -1;
            }
            break;
        case AREA:
            if (e1->area > e2->area)
            {
                return 1;
            }
            else if (e1->area == e2->area)
            {
                return 0;
            }
            else
            {
                return -1;
            }
            break;
        case POPULACAO:
            if (e1->populacao > e2->populacao)
            {
                return 1;
            }
            else if (e1->populacao == e2->populacao)
            {
                return 0;
            }
            else
            {
                return -1;
            }
            break;
    }

    return 2;
}