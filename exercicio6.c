#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *proximo;
} No;

typedef struct
{
    int quantidade;
    int maior;
    int menor;
    long long soma;
    double media;
} Estatisticas;

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

// Calcula todas as estatísticas em uma única passagem pela lista.
Estatisticas calcularEstatisticas(No *inicio)
{
    Estatisticas resultado = {0, 0, 0, 0, 0.0};

    if (inicio == NULL)
    {
        return resultado;
    }

    No *atual = inicio;
    resultado.maior = inicio->dado;
    resultado.menor = inicio->dado;

    while (atual != NULL)
    {
        resultado.quantidade++;
        resultado.soma += atual->dado;

        if (atual->dado > resultado.maior)
        {
            resultado.maior = atual->dado;
        }

        if (atual->dado < resultado.menor)
        {
            resultado.menor = atual->dado;
        }

        atual = atual->proximo;
    }

    resultado.media = (double)resultado.soma / resultado.quantidade;
    return resultado;
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

    Estatisticas resultado = calcularEstatisticas(lista);

    if (resultado.quantidade == 0)
    {
        printf("A lista está vazia.\n");
    }
    else
    {
        printf("Quantidade: %d\n", resultado.quantidade);
        printf("Maior valor: %d\n", resultado.maior);
        printf("Menor valor: %d\n", resultado.menor);
        printf("Soma: %lld\n", resultado.soma);
        printf("Média: %.2f\n", resultado.media);
    }

    liberarLista(lista);
    return 0;
}
