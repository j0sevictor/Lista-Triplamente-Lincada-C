#include <stdio.h>
#include "no.h"

typedef struct
{
    tNo** primeiro;
    tNo** ultimo;
    int qtdElementos;
}Lista;


// Protótipos
Lista* criarLista();
void freeLista(Lista* lista);

int addElementoOrdenado(Lista* lista, elemento* valor);
int removerElemento(Lista* lista, elemento* valor);

int listaVazia(Lista* lista);
void printLista(Lista* lista, PARAMETRO p);


// Funções
Lista* criarLista()
{
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista != NULL)
    {
        lista->qtdElementos = 0;
        lista->primeiro = (tNo**) malloc(NUM_PARAM * sizeof(tNo*));
        lista->ultimo = (tNo**) malloc(NUM_PARAM * sizeof(tNo*));

        if (lista->primeiro != NULL && lista->ultimo != NULL)
        {
            int i;
            for (i = 0; i < NUM_PARAM; i++)
            {
                lista->primeiro[i] = NULL;
                lista->ultimo[i] = NULL;
            }

            return lista;
        }
    }

    return NULL;
}

int addElementoOrdenado(Lista* lista, elemento* valor)
{
    tNo* noNovo = criarNo(valor);
    if (noNovo == NULL)
    {
        return 0;
    }

    int i;
    for (i = 0; i < NUM_PARAM; i++)
    {
        if (lista->primeiro[i] == NULL)
        {
            // Se a lista não tem elementos então o novoNo é o primeiro e o último
            lista->primeiro[i] = noNovo;
            lista->ultimo[i] = noNovo;
        }
        else
        {
            tNo* no = lista->primeiro[i];
            while (no != NULL)
            {
                int comp = compare(noNovo->valor, no->valor, i);
                if (comp == 0 || comp == 1)
                {
                    // A posição do novo no foi achada
                    noNovo->proximo[i] = no;

                    if (no->anterior[i] == NULL)
                    {
                        noNovo->anterior[i] = NULL;
                        lista->primeiro[i] = noNovo;
                    }
                    else
                    {
                        noNovo->anterior[i] = no->anterior[i];
                        no->anterior[i]->proximo[i] = noNovo;
                    }
                    no->anterior[i] = noNovo;

                    break;
                }

                no = no->proximo[i];
            }

            if (no == NULL)
            {
                // A posição do novo no é na última posição
                no = lista->ultimo[i];
                noNovo->proximo[i] = NULL;
                noNovo->anterior[i] = no;

                no->proximo[i] = noNovo;

                lista->ultimo[i] = noNovo;
            }
        }

    }

    lista->qtdElementos++;

    return 1;
}

int removerElemento(Lista* lista, elemento* valor)
{
    if (listaVazia(lista))
    {
        return 0;
    }

    int i;
    tNo* noRemover = NULL;
    tNo* no;
    for (i = 0; i < NUM_PARAM; i++)
    {
        no = lista->primeiro[i];
        while (no != NULL)
        {
            if (equals(valor, no->valor))
            {
                // No para ser removido foi achado
                if (noRemover == NULL)
                {
                    noRemover = no;
                }

                if (no->anterior[i] == NULL)
                {
                    // No a ser removido é o primeiro da lista
                    no->proximo[i]->anterior[i] = NULL;
                    lista->primeiro[i] = no->proximo[i];
                }
                else if (no->proximo[i] == NULL)
                {
                    // No a ser removido é o último da lista
                    no->anterior[i]->proximo[i] = NULL;
                    lista->ultimo[i] = no->anterior[i];
                }
                else
                {
                    no->anterior[i]->proximo[i] = no->proximo[i];
                    no->proximo[i]->anterior[i] = no->anterior[i];
                }

                break;
            }

            no = no->proximo[i];
        }
    }

    if (noRemover != NULL)
    {
        freeNo(noRemover);
        lista->qtdElementos--;
    }
    return 1;
}

void freeLista(Lista* lista)
{
    tNo* no = lista->ultimo[0];
    tNo* aux;
    int liberado = 0, sNo = sizeof(tNo), sElemento = sizeof(elemento);
    while (no != NULL)
    {
        aux = no;
        no = no->anterior[0];

        freeNo(aux);
        liberado += sNo + sElemento;
        lista->qtdElementos--;
    }
    printf("%d BYTES liberados.\n", liberado);
    free(lista);
}

int listaVazia(Lista* lista)
{
    return !(lista->qtdElementos);
}

void printLista(Lista* lista, PARAMETRO p)
{
    if (!validParam(p))
    {
        return;
    }

    tNo* no = lista->primeiro[p];
    while (no != NULL)
    {
        printElemento(no->valor);
        no = no->proximo[p];
    }
}
