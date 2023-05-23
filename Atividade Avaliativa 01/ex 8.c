#include <stdio.h>

int main() {
    int numero, maior, menor;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    maior = menor = numero;

    while (numero >= 0) {
        if (numero > maior) {
            maior = numero;
        }
        if (numero < menor) {
            menor = numero;
        }
        printf("Digite outro numero inteiro: ");
        scanf("%d", &numero);
    }

    printf("O maior numero digitado foi %d e o menor foi %d.\n", maior, menor);

    return 0;
}

