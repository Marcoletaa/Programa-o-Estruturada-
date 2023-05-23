#include <stdio.h>

int main(){
	int a,b,c,d,dif;
	
	printf("\nDigite o valor de A: ");
	scanf("%d",&a);
	
	printf("\nDigite o valor de B: ");
	scanf("%d",&b);
	
	printf("\nDigite o valor de C: ");
	scanf("%d",&c);
	
	printf("\nDigite o valor de D: ");
	scanf("%d",&d);
	
	dif = ((a*b) - (c*d));
	
	printf("\nA diferenca e igual a %d",dif);
	
	return 0;
}
