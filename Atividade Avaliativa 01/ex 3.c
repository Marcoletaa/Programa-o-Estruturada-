#include <stdio.h>

int main() {
    const double PI = 3.14159; 
    double raio, volume, area;

    printf("Digite o valor do raio da esfera: ");
    scanf("%lf", &raio);

    volume = (4.0/3) * PI * raio * raio * raio; 
    area = 4 * PI * raio * raio; 

    printf("A área da superfície da esfera é: %lf\n", area);
    printf("O volume da esfera é: %lf\n", volume);

    return 0;
}

