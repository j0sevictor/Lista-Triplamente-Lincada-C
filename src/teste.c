#include <stdlib.h>
#include <stdio.h>
#include "listaLincada.h"

int main()
{

    elemento* e1 = criaElemento("Juazeiro", 700.3, 8230.43, 353454);
    elemento* e2 = criaElemento("Brejo", 650.3, 3240.43, 12313);
    elemento* e3 = criaElemento("Mauriti", 600.3, 10230.43, 40000);

    Lista* lista = criarLista();
    
    addElementoOrdenado(lista, e1);
    addElementoOrdenado(lista, e2);
    addElementoOrdenado(lista, e3);

    printf("%s\n", lista->ultimo[IDH]->valor->nomeCidade);

    freeLista(lista);
    return 0;
}