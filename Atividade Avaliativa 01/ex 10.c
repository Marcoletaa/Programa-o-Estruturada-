#include <stdio.h>

int main() {
    int numeros[10];
    int soma = 0;
    int i;

    for (i = 0; i < 10; i++) {
        printf("Digite o %dº número: ", i+1);
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }

    printf("A média dos números é %.2f", (float)soma/10.0);

    return 0;
}

