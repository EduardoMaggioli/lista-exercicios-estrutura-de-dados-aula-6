#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contato
{
    char nome[50];
    char telefone[20];
    struct Contato *proximo;
} Contato;

void lerTexto(const char *mensagem, char *destino, int tamanho)
{
    printf("%s", mensagem);

    if (fgets(destino, tamanho, stdin) == NULL)
    {
        destino[0] = '\0';
        return;
    }

    if (strchr(destino, '\n') == NULL)
    {
        int caractere;

        while ((caractere = getchar()) != '\n' && caractere != EOF)
        {
            /* Descarta o restante da linha. */
        }
    }

    destino[strcspn(destino, "\n")] = '\0';
}

void cadastrarContato(Contato **inicio)
{
    Contato *novo = malloc(sizeof(Contato));

    if (novo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    lerTexto("Nome: ", novo->nome, sizeof(novo->nome));
    lerTexto("Telefone: ", novo->telefone, sizeof(novo->telefone));
    novo->proximo = NULL;

    if (*inicio == NULL)
    {
        *inicio = novo;
    }
    else
    {
        Contato *atual = *inicio;

        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }

        atual->proximo = novo;
    }

    printf("Contato cadastrado.\n");
}

Contato *buscarContato(Contato *inicio, const char *nome)
{
    Contato *atual = inicio;

    while (atual != NULL)
    {
        if (strcmp(atual->nome, nome) == 0)
        {
            return atual;
        }

        atual = atual->proximo;
    }

    return NULL;
}

void removerContato(Contato **inicio, const char *nome)
{
    Contato *atual = *inicio;
    Contato *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        printf("Contato não encontrado.\n");
        return;
    }

    if (anterior == NULL)
    {
        *inicio = atual->proximo;
    }
    else
    {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Contato removido.\n");
}

void listarContatos(Contato *inicio)
{
    if (inicio == NULL)
    {
        printf("A agenda está vazia.\n");
        return;
    }

    int numero = 1;
    Contato *atual = inicio;

    while (atual != NULL)
    {
        printf("%d. Nome: %s | Telefone: %s\n",
               numero, atual->nome, atual->telefone);

        atual = atual->proximo;
        numero++;
    }
}

void liberarContatos(Contato *inicio)
{
    Contato *atual = inicio;

    while (atual != NULL)
    {
        Contato *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main(void)
{
    Contato *agenda = NULL;
    char entrada[10];
    char nome[50];
    int opcao;

    do
    {
        printf("\n--- Agenda Telefônica ---\n");
        printf("1. Cadastrar contato\n");
        printf("2. Buscar contato\n");
        printf("3. Remover contato\n");
        printf("4. Listar contatos\n");
        printf("0. Sair\n");

        lerTexto("Escolha uma opção: ", entrada, sizeof(entrada));
        opcao = atoi(entrada);

        switch (opcao)
        {
            case 1:
                cadastrarContato(&agenda);
                break;

            case 2:
            {
                lerTexto("Digite o nome para buscar: ", nome, sizeof(nome));

                Contato *encontrado = buscarContato(agenda, nome);

                if (encontrado != NULL)
                {
                    printf("Nome: %s | Telefone: %s\n",
                           encontrado->nome, encontrado->telefone);
                }
                else
                {
                    printf("Contato não encontrado.\n");
                }

                break;
            }

            case 3:
                lerTexto("Digite o nome para remover: ", nome, sizeof(nome));
                removerContato(&agenda, nome);
                break;

            case 4:
                listarContatos(agenda);
                break;

            case 0:
                printf("Encerrando a agenda.\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    liberarContatos(agenda);
    return 0;
}
