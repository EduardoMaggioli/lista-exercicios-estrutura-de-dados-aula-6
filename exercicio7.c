#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *proximo;
} No;

// Insere o valor mantendo a lista em ordem crescente.
No *inserirOrdenado(No *inicio, int valor)
{
    No *novo = malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return inicio;
    }

    novo->dado = valor;

    // Insere no início se a lista estiver vazia
    // ou se o valor for menor que o primeiro.
    if (inicio == NULL || valor < inicio->dado)
    {
        novo->proximo = inicio;
        return novo;
    }

    // Avança até encontrar a posição correta.
    No *atual = inicio;

    while (atual->proximo != NULL &&
           atual->proximo->dado <= valor)
    {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;

    return inicio;
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
    No *lista = NULL;

    lista = inserirOrdenado(lista, 30);
    lista = inserirOrdenado(lista, 10);
    lista = inserirOrdenado(lista, 40);
    lista = inserirOrdenado(lista, 20);

    printf("Lista em ordem crescente: ");
    exibirLista(lista);

    liberarLista(lista);
    return 0;
}
