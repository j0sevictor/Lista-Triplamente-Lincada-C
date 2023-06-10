#include <locale.h>
#include "listaLincada.h"

#define MAX_LINHA 128
#define SEPARADOR ";"

void removeQuotationAndComma(char* str);
void removeLineBreak(char* str);
void printMenu();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    FILE* csv = fopen("../cidades.csv", "r");
    if (csv == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    char linha[MAX_LINHA];
    char* campo;
    int qtd = 0;

    // Pulando a primeira linha
    fgets(linha, MAX_LINHA, csv);

    Lista* listaCidades = criarLista();
    if (listaCidades == NULL)
    {
        printf("Erro ao criar a lista.");
        return 1;
    }
    elemento* cidade;
    
    // Carrega os dados do arquivo csv e os coloca na lista de cidades
    while (fgets(linha, MAX_LINHA, csv) != NULL)
    {
        removeLineBreak(linha);

        cidade = criaElementoVazio();
        if (cidade == NULL)
        {
            continue;
        }

        //Pulando a numeração das linhas
        strtok(linha, SEPARADOR);

        // Lê o nome da cidade
        campo = strtok(NULL, SEPARADOR);
        removeQuotationAndComma(campo);
        strcpy(cidade->nomeCidade, campo);

        // Lê os dados numéricos. Ordem População, IDH e área
        campo = strtok(NULL, SEPARADOR);
        removeQuotationAndComma(campo);
        cidade->populacao = atoi(campo);

        campo = strtok(NULL, SEPARADOR);
        removeQuotationAndComma(campo);
        cidade->idh = atof(campo);

        campo = strtok(NULL, SEPARADOR);
        removeQuotationAndComma(campo);
        cidade->area = atof(campo);
        
        addElementoOrdenado(listaCidades, cidade);

        if (qtd >= 3)
        {
            break;
        }
        qtd++;
    }

    int opc = 0;
    while (opc != 4)
    {
        printMenu();
        printf("\nEscolha uma das opções: ");
        scanf("%d", &opc);
        system("cls");

        switch (opc)
        {
            case 1: 
            {
                int param = 0;
                while (!validParam(param - 1))
                {
                    printf("Escolha um parâmero de ordenação:\n");
                    printf("1. IDH\n");
                    printf("2. Area\n");
                    printf("3. População\n");
                    scanf("%d", &param);
                    system("cls");
                }

                printLista(listaCidades, param);
                system("pause");
            }
            break;

            default:
            break;
        }
    }

    fclose(csv);
    freeLista(listaCidades);
    return 0;
}

void printMenu()
{
    printf("-=--=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n");
    printf("     Sistema Lista Triplamente Encadeada     \n");
    printf("-=--=--=--=--=--=--=--=--=--=--=--=--=--=--=-\n");
    printf("Menu: \n");
    printf("1. Ver as cidades\n");
    printf("2. Pesquisar uma cidade\n");
    printf("3. Excluir uma cidade\n");
    printf("4. Sair\n");
}


void removeQuotationAndComma(char* str)
{
    if (str == NULL)
    {
        return;
    }

    char newStr[strlen(str)];
    int index = 0, i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '.')
        {
            newStr[index] = ',';
            index++;
        }
        else if (str[i] != '"' && str[i] != ',')
        {
            newStr[index] = str[i];
            index++;
        }

        i++;
    }
    newStr[index] = '\0';

    strcpy(str, newStr);
    return;
}

void removeLineBreak(char* str)
{
    int final = strlen(str) - 1;
    if (str[final] == '\n')
    {
        str[final] = '\0';
    }

    return;
}