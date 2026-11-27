#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *proximo;
} No;

// Adiciona um nó no final para montar a lista do exemplo.
No *inserirFinal(No *inicio, int valor)
{
    No *novo = malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return inicio;
    }

    novo->dado = valor;
    novo->proximo = NULL;

    if (inicio == NULL)
    {
        return novo;
    }

    No *atual = inicio;

    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }

    atual->proximo = novo;
    return inicio;
}

// Retorna o endereço do nó encontrado ou NULL se não encontrar.
No *buscar(No *inicio, int valor, int *posicao)
{
    No *atual = inicio;
    int contador = 1;

    while (atual != NULL)
    {
        if (atual->dado == valor)
        {
            *posicao = contador;
            return atual;
        }

        atual = atual->proximo;
        contador++;
    }

    return NULL;
}

void liberarLista(No *inicio)
{
    No *atual = inicio;

    while (atual != NULL)
    {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main(void)
{
    No *lista = NULL;
    int valores[] = {10, 20, 30, 40};

    for (int i = 0; i < 4; i++)
    {
        lista = inserirFinal(lista, valores[i]);
    }

    int valor;
    int posicao = 0;

    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &valor);

    No *resultado = buscar(lista, valor, &posicao);

    if (resultado != NULL)
    {
        printf("Valor encontrado na posição %d.\n", posicao);
        printf("Endereço do nó: %p\n", (void *)resultado);
    }
    else
    {
        printf("Valor não encontrado. Retorno: NULL\n");
    }

    liberarLista(lista);
    return 0;
}
