#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *proximo;
} No;

// Insere um novo nó no final da lista.
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

    // Se a lista estiver vazia, o novo nó será o primeiro.
    if (inicio == NULL)
    {
        return novo;
    }

    // Percorre a lista até encontrar o último nó.
    No *atual = inicio;
    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }

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
    int valores[] = {10, 20, 30};

    for (int i = 0; i < 3; i++)
    {
        lista = inserirFinal(lista, valores[i]);

        printf("Lista após inserir %d: ", valores[i]);
        exibirLista(lista);
    }

    liberarLista(lista);
    return 0;
}

/*
Comparação:
Na inserção no final, o algoritmo percorre a lista para encontrar
o último nó. Na inserção no início, não é necessário percorrer:
basta ligar o novo nó ao início atual da lista.
*/
