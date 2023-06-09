#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LINHA 128
#define SEPARADOR ";"

void removeQuotationAndComma(char* str);
void removeLineBreak(char* str);

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

    while (fgets(linha, MAX_LINHA, csv) != NULL)
    {
        removeLineBreak(linha);
        printf("Linha: %s\n", linha);

        // Lê o nome da cidade
        campo = strtok(linha, SEPARADOR);
        removeQuotationAndComma(campo);

        // Lê os dados numéricos
        while (campo != NULL)
        {
            printf("-->Campo: %s\n", campo);
            campo = strtok(NULL, SEPARADOR);
            removeQuotationAndComma(campo);
        }
        

        if (qtd >= 10)
        {
            break;
        }
        qtd++;
    }

    fclose(csv);
    return 0;
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
        if (str[i] != '"' && str[i] != ','){
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