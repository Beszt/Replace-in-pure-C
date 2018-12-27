#include <stdio.h>
#include "replace.c"

#define ROZMIARBUFORA 4096


int main()
{
	char bufor[ROZMIARBUFORA] = "";
	char a[] = "kota"; // Stara fraza
	char b[] = "psa"; // Nowa fraza
	char tekst[] = "Ala ma kota, bo tylko kota moze miec. Fajnie jest miec kota."; //Tekst
	printf("%s%s", tekst, "\n");
	printf("%d%s",replace(&a[0], &b[0], &tekst[0], &bufor[0], ROZMIARBUFORA),"\n"); //Wywo³anie funkcji
	printf("%s", bufor);
	getchar();
	return 0;
}
