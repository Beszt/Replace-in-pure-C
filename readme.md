# Replace

replace - funkcja zamiany ci±gów w wiêkszym ci±gu. Innymi s³owy: w tek¶cie (tablicy znaków char) podmienia podan± frazê na inn±. Funkcja napisana w czystym jêzyku C - do dzia³ania nie potrzebuje ¿adnych innych bibliotek. 
  
## Argumenty:

* char *oldChain - wska¼nik do fragmentu tekstu który chcemy zamieniæ
* char *newChain - wska¼nik do nowego tekstu który ma zostaæ wstawiony
* char *text - wska¼nik do tekstu w którym ma nastapiæ zamiana.
* char *buffer - wska¼nik do zarezerwowanego przez u¿ytkownika bufora pamiêci. Do tej pamiêci zostanie zapisany wynikowy tekst. unsigned short bufferSize - rozmiar bufora pamiêci (w bajtach) zarezerwowanego na wynikowy tekst.

## Warto¶ci zwracane:

0 - Zamiana zosta³a wykonane poprawnie - funkcja podmieni³a wszystkie 
stare ci±gi na nowe.

1 - Nowy ci±g jest równy staremu - funkcja nie wykonuje ¿adnych zmian.

2 - Nowy ci±g jest powieleniem starego (np. zamiana "a" na "aa") - funkcja nie wykonuje ¿adnych zmian.

3 - B³±d zamiany - za ma³y bufor aby dokonaæ pe³nej zamiany.

## Przyk³ad wywo³ania

```
replace(&a[0], &b[0], &tekst[0], &bufor[0], ROZMIARBUFORA);
```

Przyk³ad wywo³ania znajduje siê w funkcji main().