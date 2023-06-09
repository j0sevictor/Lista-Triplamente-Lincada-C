#include "dado.h"

typedef struct no
{
    elemento* valor;
    struct no* proximo;
    struct no* anterior;
} tNo;

tNo* criarNo(elemento* valor)
{
    tNo* novoNo = (tNo*) malloc(sizeof(tNo)); 
    if (novoNo != NULL)
    {
        novoNo->valor = valor;
        novoNo->proximo = NULL;
        novoNo->anterior = NULL;
        return novoNo;
    }

    return NULL;
}

void freeNo(tNo* no)
{
    if (no == NULL)
    {
        return;
    }

    if (no->valor != NULL)
    {
        freeElemento(no->valor);
    }

    free(no);
}