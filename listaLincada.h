#include <stdio.h>
#include "No.h"

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

int listaVazia(Lista* lista);


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

void freeLista(Lista* lista)
{
    tNo* no = lista->ultimo[0];
    tNo* aux;
    while (no != NULL)
    {
        aux = no;
        no = no->anterior[0];

        freeNo(aux);
        lista->qtdElementos--;
    }

    free(lista);
}

int listaVazia(Lista* lista)
{
    return !(lista->qtdElementos);
}
