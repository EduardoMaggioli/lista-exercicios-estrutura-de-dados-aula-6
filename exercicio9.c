#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *proximo;
} No;

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

// Une as listas alterando apenas os ponteiros.
No *unirListas(No *lista1, No *lista2)
{
    if (lista1 == NULL)
    {
        return lista2;
    }

    if (lista2 == NULL)
    {
        return lista1;
    }

    No *ultimo = lista1;

    while (ultimo->proximo != NULL)
    {
        ultimo = ultimo->proximo;
    }

    ultimo->proximo = lista2;

    return lista1;
}

void exibirLista(No *inicio)
{
    No *atual = inicio;

    while (atual != NULL)
    {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }

    printf("NULL\n");
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
    No *lista1 = NULL;
    No *lista2 = NULL;

    lista1 = inserirFinal(lista1, 10);
    lista1 = inserirFinal(lista1, 20);
    lista1 = inserirFinal(lista1, 30);

    lista2 = inserirFinal(lista2, 40);
    lista2 = inserirFinal(lista2, 50);
    lista2 = inserirFinal(lista2, 60);

    printf("Lista 1: ");
    exibirLista(lista1);

    printf("Lista 2: ");
    exibirLista(lista2);

    No *resultado = unirListas(lista1, lista2);

    printf("Resultado da união: ");
    exibirLista(resultado);

    // Libera a lista unida uma única vez.
    liberarLista(resultado);

    return 0;
}
