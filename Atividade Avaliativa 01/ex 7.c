#include <stdio.h>

int main() {
    int n, i, termoAnterior = 0, termoAtual = 1, proximoTermo;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("O enesimo termo da sequencia de Fibonacci eh 0.\n");
    } else if (n == 1) {
        printf("O enesimo termo da sequencia de Fibonacci eh 1.\n");
    } else {
        for (i = 2; i <= n; i++) {
            proximoTermo = termoAnterior + termoAtual;
            termoAnterior = termoAtual;
            termoAtual = proximoTermo;
        }
        printf("O enesimo termo da sequencia de Fibonacci eh %d.\n", termoAtual);
    }

    return 0;
}

