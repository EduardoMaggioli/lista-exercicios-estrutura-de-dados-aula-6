typedef struct No
{
    int dado;
    struct No *proximo;
} No;

/*
O campo "dado" guarda o valor armazenado no nó.

O ponteiro "proximo" guarda o endereço do próximo nó da lista.
Se for NULL, significa que este é o último nó.

O tipo "struct No *" indica que o ponteiro aponta para outro nó
da mesma estrutura.
*/

int main(void)
{
    return 0;
}
