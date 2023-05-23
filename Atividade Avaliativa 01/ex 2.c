#include <stdio.h>
#include <math.h>

int main(){
	float x1,x2,y1,y2,dist;
	
	printf("\nDigite o valor de X1: ");
	scanf("%f",&x1);
	
	printf("\nDigite o valor de X2: ");
	scanf("%f",&x2);
	
	printf("\nDigite o valor de Y1: ");
	scanf("%f",&y1);
	
	printf("\nDigite o valor de Y2: ");
	scanf("%f",&y2);
	
	dist = sqrt((pow((x2 - x1),2) + (pow((y2 - y1),2))));
	
	printf("\nA distancia e igual a %f",dist);
	
	return 0;
}
