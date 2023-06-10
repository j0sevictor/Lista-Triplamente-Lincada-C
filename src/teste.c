#include <stdlib.h>
#include <stdio.h>
#include "listaLincada.h"

int main()
{

    elemento* e1 = criaElemento("Juazeiro", 700.3, 8230.43, 353454);
    elemento* e2 = criaElemento("Brejo", 650.3, 3240.43, 12313);
    elemento* e3 = criaElemento("Mauriti", 600.3, 10230.43, 40000);
    elemento* e4 = criaElemento("Milagres", 600.3, 1068, 62000);
    elemento* e5 = criaElemento("Barro", 500.3, 4050, 23452);

    Lista* lista = criarLista();
    
    addElementoOrdenado(lista, e1);
    addElementoOrdenado(lista, e2);
    addElementoOrdenado(lista, e3);
    addElementoOrdenado(lista, e4);
    addElementoOrdenado(lista, e5);

    printf("Cidade: %s\n", lista->primeiro[IDH]->proximo[AREA]->valor->nomeCidade);

    printLista(lista, AREA);

    freeLista(lista);
    return 0;
}