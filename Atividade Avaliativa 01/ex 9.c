#include <stdio.h>

int main() {
    int opcao, quantidade;
    float valor, total = 0;

    printf("Bem-vindo(a) a nossa loja de frutas!\n\n");

    do {
        printf("Selecione a fruta desejada:\n");
        printf("1. Maçã - R$ 2,50\n");
        printf("2. Banana - R$ 1,50\n");
        printf("3. Laranja - R$ 3,00\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a quantidade de maçãs: ");
                scanf("%d", &quantidade);
                valor = quantidade * 2.5;
                total += valor;
                printf("Valor a ser pago: R$ %.2f\n\n", valor);
                break;
            case 2:
                printf("Digite a quantidade de bananas: ");
                scanf("%d", &quantidade);
                valor = quantidade * 1.5;
                total += valor;
                printf("Valor a ser pago: R$ %.2f\n\n", valor);
                break;
            case 3:
                printf("Digite a quantidade de laranjas: ");
                scanf("%d", &quantidade);
                valor = quantidade * 3;
                total += valor;
                printf("Valor a ser pago: R$ %.2f\n\n", valor);
                break;
            case 4:
                printf("O total a ser pago é de R$ %.2f\n", total);
                printf("Volte sempre!\n");
                break;
            default:
                printf("Opção inválida!\n\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}

