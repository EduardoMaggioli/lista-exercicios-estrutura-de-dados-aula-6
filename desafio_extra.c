int main(void)
{
    printf("TIPOS DE LISTAS ENCADEADAS\n\n");

    printf("Lista simplesmente encadeada:\n");
    printf("Cada no aponta para o proximo.\n");
    printf("Vantagem: simples e usa pouca memoria.\n");
    printf("Desvantagem: so permite percorrer para frente.\n");
    printf("Uso: pilhas e filas simples.\n\n");

    printf("Lista duplamente encadeada:\n");
    printf("Cada no aponta para o proximo e para o anterior.\n");
    printf("Vantagem: permite percorrer para frente e para tras.\n");
    printf("Desvantagem: usa mais memoria.\n");
    printf("Uso: listas com navegacao proximo e anterior.\n\n");

    printf("Lista circular:\n");
    printf("O ultimo no aponta para o primeiro.\n");
    printf("Vantagem: permite percorrer os elementos em ciclo.\n");
    printf("Desvantagem: exige cuidado para evitar loop infinito.\n");
    printf("Uso: organizar turnos em jogos ou processos.\n");

    return 0;
}
