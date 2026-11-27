#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarefa
{
    int id;
    char descricao[100];
    int concluida;
    struct Tarefa *proximo;
} Tarefa;

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

int lerInteiro(const char *mensagem)
{
    char entrada[20];
    lerTexto(mensagem, entrada, sizeof(entrada));
    return atoi(entrada);
}

void cadastrarTarefa(Tarefa **inicio, int *proximoId)
{
    Tarefa *nova = malloc(sizeof(Tarefa));

    if (nova == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    nova->id = *proximoId;
    (*proximoId)++;

    lerTexto("Descrição da tarefa: ", nova->descricao,
             sizeof(nova->descricao));

    nova->concluida = 0;
    nova->proximo = NULL;

    if (*inicio == NULL)
    {
        *inicio = nova;
    }
    else
    {
        Tarefa *atual = *inicio;

        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }

        atual->proximo = nova;
    }

    printf("Tarefa cadastrada com o ID %d.\n", nova->id);
}

void listarTarefas(Tarefa *inicio)
{
    if (inicio == NULL)
    {
        printf("Não há tarefas cadastradas.\n");
        return;
    }

    Tarefa *atual = inicio;

    while (atual != NULL)
    {
        printf("ID: %d | Descrição: %s | Status: %s\n",
               atual->id,
               atual->descricao,
               atual->concluida ? "Concluída" : "Pendente");

        atual = atual->proximo;
    }
}

Tarefa *localizarTarefa(Tarefa *inicio, int id)
{
    Tarefa *atual = inicio;

    while (atual != NULL)
    {
        if (atual->id == id)
        {
            return atual;
        }

        atual = atual->proximo;
    }

    return NULL;
}

void removerTarefa(Tarefa **inicio, int id)
{
    Tarefa *atual = *inicio;
    Tarefa *anterior = NULL;

    while (atual != NULL && atual->id != id)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        printf("Tarefa não encontrada.\n");
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
    printf("Tarefa removida.\n");
}

void liberarTarefas(Tarefa *inicio)
{
    Tarefa *atual = inicio;

    while (atual != NULL)
    {
        Tarefa *proxima = atual->proximo;
        free(atual);
        atual = proxima;
    }
}

int main(void)
{
    Tarefa *lista = NULL;
    int proximoId = 1;
    int opcao;

    do
    {
        printf("\n--- Lista de Tarefas ---\n");
        printf("1. Cadastrar tarefa\n");
        printf("2. Listar tarefas\n");
        printf("3. Localizar tarefa pelo ID\n");
        printf("4. Marcar tarefa como concluída\n");
        printf("5. Remover tarefa\n");
        printf("0. Sair\n");

        opcao = lerInteiro("Escolha uma opção: ");

        switch (opcao)
        {
            case 1:
                cadastrarTarefa(&lista, &proximoId);
                break;

            case 2:
                listarTarefas(lista);
                break;

            case 3:
            {
                int id = lerInteiro("Digite o ID da tarefa: ");
                Tarefa *tarefa = localizarTarefa(lista, id);

                if (tarefa != NULL)
                {
                    printf("ID: %d | Descrição: %s | Status: %s\n",
                           tarefa->id,
                           tarefa->descricao,
                           tarefa->concluida ? "Concluída" : "Pendente");
                }
                else
                {
                    printf("Tarefa não encontrada.\n");
                }

                break;
            }

            case 4:
            {
                int id = lerInteiro("Digite o ID da tarefa: ");
                Tarefa *tarefa = localizarTarefa(lista, id);

                if (tarefa != NULL)
                {
                    tarefa->concluida = 1;
                    printf("Tarefa marcada como concluída.\n");
                }
                else
                {
                    printf("Tarefa não encontrada.\n");
                }

                break;
            }

            case 5:
            {
                int id = lerInteiro("Digite o ID da tarefa: ");
                removerTarefa(&lista, id);
                break;
            }

            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    liberarTarefas(lista);
    return 0;
}
