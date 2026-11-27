#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *proximo;
} No;

// Insere um novo nó no início e devolve o novo começo da lista.
No *inserirInicio(No *inicio, int valor)
{
    No *novo = malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return inicio;
    }

    novo->dado = valor;
    novo->proximo = inicio;

    return novo;
}

// Exibe todos os valores da lista.
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

// Libera a memória usada pelos nós.
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
        lista = inserirInicio(lista, valores[i]);

        printf("Lista após inserir %d: ", valores[i]);
        exibirLista(lista);
    }

    liberarLista(lista);

    return 0;
}
