#include <stdio.h>

int main() {

	int i = 0;
	int numcyc = 0;
	int posnum = 0;
	int negnum = 0;
	int oddnum = 0;
	int evennum = 0;
	float perpos = 0.00f;
	float perneg = 0.00f;
	float perodd = 0.00f;
	float pereven = 0.00f;
	float avg = 0.00f;
	int sum = 0;
	int min;
	int max;
	while (scanf("%d", &i) == 1)
	{	
		if(i<= 10000 && i>= -10000)
		{
			numcyc++;
			if(numcyc == 1)			
			{
				printf("%d",i);
				min = i;
				max = i;
			}
			else
				printf(", %d",i);
			if(i>0)
				posnum++;
			if(i<0)
				negnum++;
			if(i%2 == 0)
				evennum++;
			else
				oddnum++;
			sum   += i;
			avg = (float)sum / numcyc;
			perpos = ((float)posnum / numcyc)*100;
			perneg = ((float)negnum / numcyc)*100;
			perodd = ((float)oddnum / numcyc)*100;
			pereven = ((float)evennum / numcyc)*100;
			if(i < min)
				min = i;
			if(i > max)
				max = i;
		}
		
		else
		{
			printf("\nError: Vstup je mimo interval!\n");
			return 100;
			break;
		}
	}

	printf("\n");
	printf("Pocet cisel: %d\n", numcyc);
	printf("Pocet kladnych: %i\n", posnum);
	printf("Pocet zapornych: %i\n", negnum);
	printf("Procento kladnych: %.2f\n", perpos);
	printf("Procento zapornych: %.2f\n", perneg);
	printf("Pocet sudych: %i\n", evennum);
	printf("Pocet lichych: %i\n", oddnum);
	printf("Procento sudych: %.2f\n", pereven);
	printf("Procento lichych: %.2f\n", perodd);
	printf("Prumer: %.2f\n", (float)avg);
	printf("Maximum: %i\n", max);
	printf("Minimum: %i\n", min);
	return 0;
}
