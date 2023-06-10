#include "dado.h"

typedef struct no
{
    elemento* valor;
    struct no** proximo;
    struct no** anterior;
} tNo;

tNo* criarNo(elemento* valor)
{
    tNo* novoNo = (tNo*) malloc(sizeof(tNo)); 
    if (novoNo != NULL)
    {
        novoNo->valor = valor;
        novoNo->proximo = (tNo**) malloc(NUM_PARAM * sizeof(tNo*));
        novoNo->anterior = (tNo**) malloc(NUM_PARAM * sizeof(tNo*));

        if (novoNo->proximo != NULL && novoNo->anterior != NULL)
        {
            int i;
            for (i = 0; i < NUM_PARAM; i++)
            {
                novoNo->proximo[i] = NULL;
                novoNo->anterior[i] = NULL;
            }
            
            return novoNo;
        }
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