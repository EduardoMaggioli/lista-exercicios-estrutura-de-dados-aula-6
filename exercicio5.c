#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *proximo;
} No;

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

void removerInicio(No **inicio)
{
    if (*inicio == NULL)
    {
        return;
    }

    No *removido = *inicio;
    *inicio = (*inicio)->proximo;
    free(removido);
}

void removerFinal(No **inicio)
{
    if (*inicio == NULL)
    {
        return;
    }

    if ((*inicio)->proximo == NULL)
    {
        free(*inicio);
        *inicio = NULL;
        return;
    }

    No *atual = *inicio;

    while (atual->proximo->proximo != NULL)
    {
        atual = atual->proximo;
    }

    free(atual->proximo);
    atual->proximo = NULL;
}

void removerValor(No **inicio, int valor)
{
    if (*inicio == NULL)
    {
        return;
    }

    if ((*inicio)->dado == valor)
    {
        No *removido = *inicio;
        *inicio = (*inicio)->proximo;
        free(removido);
        return;
    }

    No *anterior = *inicio;
    No *atual = (*inicio)->proximo;

    while (atual != NULL && atual->dado != valor)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL)
    {
        anterior->proximo = atual->proximo;
        free(atual);
    }
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

    lista = inserirFinal(lista, 10);
    lista = inserirFinal(lista, 20);
    lista = inserirFinal(lista, 30);
    lista = inserirFinal(lista, 40);

    printf("Lista inicial: ");
    exibirLista(lista);

    removerInicio(&lista);
    printf("Após remover o início: ");
    exibirLista(lista);

    removerFinal(&lista);
    printf("Após remover o final: ");
    exibirLista(lista);

    removerValor(&lista, 20);
    printf("Após remover o valor 20: ");
    exibirLista(lista);

    liberarLista(lista);
    return 0;
}
