# Replace

replace - funkcja zamiany ci�g�w w wi�kszym ci�gu. Innymi s�owy: w tek�cie (tablicy znak�w char) podmienia podan� fraz� na inn�. Funkcja napisana w czystym j�zyku C - do dzia�ania nie potrzebuje �adnych innych bibliotek. 
  
## Argumenty:

* char *oldChain - wska�nik do fragmentu tekstu kt�ry chcemy zamieni�
* char *newChain - wska�nik do nowego tekstu kt�ry ma zosta� wstawiony
* char *text - wska�nik do tekstu w kt�rym ma nastapi� zamiana.
* char *buffer - wska�nik do zarezerwowanego przez u�ytkownika bufora pami�ci. Do tej pami�ci zostanie zapisany wynikowy tekst. unsigned short bufferSize - rozmiar bufora pami�ci (w bajtach) zarezerwowanego na wynikowy tekst.

## Warto�ci zwracane:

0 - Zamiana zosta�a wykonane poprawnie - funkcja podmieni�a wszystkie 
stare ci�gi na nowe.

1 - Nowy ci�g jest r�wny staremu - funkcja nie wykonuje �adnych zmian.

2 - Nowy ci�g jest powieleniem starego (np. zamiana "a" na "aa") - funkcja nie wykonuje �adnych zmian.

3 - B��d zamiany - za ma�y bufor aby dokona� pe�nej zamiany.

## Przyk�ad wywo�ania

```
replace(&a[0], &b[0], &tekst[0], &bufor[0], ROZMIARBUFORA);
```

Przyk�ad wywo�ania znajduje si� w funkcji main().