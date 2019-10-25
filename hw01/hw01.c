#include <stdio.h> //include standard lib
#include <math.h> //include math lib

int main() //define main function
{
	int n1; //Stdin#1
	int n2;	//Stdin#2

	scanf("%d %d", &n1,&n2); //Load stdin#1 & stdin#2

	int a = n1+n2; //Add
	int b = n1-n2; //Subtract
	int c = n1*n2; //Multiply
	float e = (float)a/2; //Avg

	if(n1 < -10000){
		printf("Vstup je mimo interval!\n"); //Out of spec
		return 0;
	}
	else if(n1 > 10000){
		printf("Vstup je mimo interval!\n"); //Out of spec
		return 0;
	}
	if(n2 < -10000){
		printf("Vstup je mimo interval!\n"); //Out of spec
		return 0;
	}	
	else if(n2 > 10000){
		printf("Vstup je mimo interval!\n"); //Out of spec
		return 0;
	}	
	else {
		if(n2 == 0){
			printf("Desitkova soustava: %i 0\n", n1); //print decimal
			printf("Sestnactkova soustava: %x 0\n", n1); //print hexadecimal
			printf("Soucet: %i + 0 = %i\n", n1,a); //print add
			printf("Rozdil: %i - 0 = %i\n", n1,b); //print substract
			printf("Soucin: %i * 0 = %i\n",n1,c); //print multiply
			printf("Nedefinovany vysledek!\n"); //print divide by zero
			printf("Prumer: %.1f\n", e); //print avg
			return 0;
		}
		else {
			int d = n1/n2; //Divide
			printf("Desitkova soustava: %i %i\n", n1,n2); //print decimal
			printf("Sestnactkova soustava: %x %x\n", n1,n2); //print hexadecimal
			printf("Soucet: %i + %i = %i\n", n1,n2,a); //print add
			printf("Rozdil: %i - %i = %i\n", n1,n2,b); //print substract
			printf("Soucin: %i * %i = %i\n", n1,n2,c); //print multiply
			printf("Podil: %i / %i = %i\n", n1,n2,d); //print divide
			printf("Prumer: %.1f\n", (float)e); //print avg
			return 0;
		}
		return 0;
	}
	return 0;
}
