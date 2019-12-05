#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/*
 * Funkce pro razeni pole retezcu
 *
 */
void sort (char ** a, int delka)
{
	for (int j = 0; j < delka; j++)
	{
		for (int i = 0; i < delka - 1; i++)
		{
			int x = (strcmp(a[i], a[i+1]) < 0); 
 
			if (x)
			{
				char t[30];
				strcpy(t, a[i]);
				strcpy(a[i], a[i+1]);
				strcpy(a[i+1], t);
			}
		}
	} 
}
 
char alpha (char a)
{
	if (a < 'A' || a > 'z' || (a > 'Z' && a < 'a'))
		return 0;	
	return a;
}
 
char beta (char a)
{
	if (a >= 'A' && a <= 'Z')
		a ^= (1 << 5);	// zmena velikosti pismene
	return a; 
}
 
int in (char ** a, char * b, int velikost)
{
	for (int i = 0; i < velikost; i++)
	{
		if (!strcmp(a[i], b))
			return i;
	}
	return -1;
}
 
void akce (char * slovo, int pozice, char (*f)(char))
{
	slovo[pozice] = f(slovo[pozice]);
}
 
int main(int argc, char ** argv)
{
	char slovo[30];
	int pozice = 0;
	char **slovnik = malloc(sizeof(char *));
	int *cetnost = malloc(sizeof(int));
 
	while (scanf("%s", slovo) > 0)
	{
		// slovo[strlen(slovo)-1] = alpha(slovo[strlen(slovo)-1]);
		// slovo[0] = beta(slovo[0]);
		akce(slovo, strlen(slovo)-1, alpha);
		akce(slovo, 0, beta);
		int x = in (slovnik, slovo, pozice);
		if (x < 0)
		{
			// slovo ve slovniku jeste neni, tak ho tam vlozim
			slovnik[pozice] = malloc(30);
			strcpy(slovnik[pozice], slovo);
			cetnost[pozice] = 1;
			pozice++;
			slovnik = realloc(slovnik, (pozice+1)*sizeof(char *));
			cetnost = realloc(cetnost, (pozice+1)*sizeof(int));
		}
		else
		{
			cetnost[x]++;
		}
	}
 
	sort (slovnik, pozice);
 
	for (int i = 0; i < pozice; i++)
	{
		printf("%2ix %s\n", cetnost[i], slovnik[i]);
	}
 
	for (int i = 0; i < pozice; i++)
	{
		free(slovnik[i]);
	}
	free(slovnik);
	free(cetnost);
 
	return 0;
}
