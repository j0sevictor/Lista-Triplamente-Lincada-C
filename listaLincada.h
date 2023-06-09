#include <stdio.h>
#include "No.h"

typedef struct
{
    tNo* primeiro;
    tNo* ultimo;
    int qtdElementos;
}Lista;


// Protótipos
Lista* criarLista();
void freeLista(Lista* lista);

int addElementoOrdenado(Lista* lista, elemento* valor);
elemento* getIndex(Lista* lista);

int listaVazia(Lista* lista);


// Funções
Lista* criarLista()
{
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista != NULL)
    {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        lista->qtdElementos = 0;

        return lista;
    }

    return NULL;
}

void freeLista(Lista* lista)
{
    tNo* aux;
    while (lista->primeiro != NULL)
    {
        aux = lista->primeiro;
        lista->primeiro = aux->proximo;
        lista->qtdElementos--;
        free(aux);
    }

    free(lista);
}

int listaVazia(Lista* lista)
{
    return !(lista->qtdElementos);
}
