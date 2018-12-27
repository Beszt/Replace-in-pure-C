unsigned short replace(char *oldChain, char *newChain, char *text, char *buffer, unsigned short bufferSize)
{
	
	unsigned short oldChainSize = 0, newChainSize = 0; //D�ugo�ci ci�g�w
	unsigned short oldChainIndex = 0; //Index starego ci�gu
	unsigned short iLetter = 0; // Licznik pomocniczy
	
	//Kopiowanie oryginalnego tekstu do bufora
	while (text[iLetter] != 0) {
		buffer[iLetter] = text[iLetter];
		iLetter++;
	}
	iLetter = 0;
	
	//Zliaczanie rozmiar�w podanych ci�g�w
	while (oldChain[iLetter] != 0) {
		iLetter++;
	}
	oldChainSize = iLetter + 1;
	iLetter = 0;
		
	while (newChain[iLetter] != 0) {
		iLetter++;
	}
	newChainSize = iLetter + 1;
	iLetter = 0;
		
	//Sprawdzanie czy ci�gi nie s� identyczne
	if (oldChainSize == newChainSize) {
		int i = 0;
	    for (i; i < oldChainSize; i++) {
	    	if (oldChain[i] != newChain[i]) {
	    		break;  
	    	}
	    }
		if (i == oldChainSize) {
			return 1;           
		}
	}
	  	
	//Sprawdzanie czy stary ci�g nie jest jednoliterowym powieleniem nowego. Je�li jest, funkcja zostaje przerwana.
	if (oldChain[0] == newChain[0]) {
	  	int i = 0;
	    for (i; i < newChainSize - 1; i++) {
	        if (oldChain[0] != newChain[i]) {
	  	  	  	break;
	  	  	}
	  	}
		if (i == newChainSize - 1) {
	  	  	return 2;	
		}
	}
	
	while (1) {
		//Szukanie indeksu starego ci�gu - aby by�o wiadomo w kt�rym miejscu w tablicy nale�y podstawi� tekst.
		while (iLetter < bufferSize - oldChainSize + 1){
			if (buffer[iLetter] == oldChain[0]) {
			int iOldChain = 0;
			unsigned int iSum = 0;
				for (unsigned short i = iLetter; iOldChain < oldChainSize; i++,iOldChain++) {
					if (buffer[i] == oldChain[iOldChain]) {
						iSum++;
					}
				}
				//Wi�ksze lub r�wne, dlatego dla obs�ugi przypadku zamieniana jest ostatnia litera z ci�gu.
	    		if (iSum >= oldChainSize - 1) {
	    			oldChainIndex = iLetter;
	    		break;
	    		}
	 		}
		iLetter++;
		}
		
		if (iLetter == bufferSize - oldChainSize + 1) {
			return 0;
		}
		
		//Obcinanie lub dodawanie znak�w w ci�gu w miejsce zamienianego wyrazu - je�li ci�gi maj� t� sam� d�ugo��, mo�e pozosta� bez zmian
		if (oldChainSize > newChainSize) {
			for (int i = oldChainIndex + oldChainSize - 1; i <= bufferSize; i++) {
				buffer[i - (oldChainSize - newChainSize)] = buffer[i];
			}
		buffer[bufferSize - (oldChainSize - newChainSize)] = 0;
	    }
	    else if (oldChainSize < newChainSize) {
			for (int i = bufferSize - 1; i >= oldChainIndex + oldChainSize - 1; i--) {
				buffer[i + (newChainSize - oldChainSize)] = buffer[i];
			}
		buffer[bufferSize + (newChainSize - oldChainSize)] = 0;
		}
	    
	    //W�a�ciwa zamiana
		for (int i = oldChainIndex, i2 = 0; i < oldChainIndex + newChainSize - 1; i++,i2++) {
			if (i + newChainSize < bufferSize) {
				buffer[i] = newChain[i2];
			}
			else {
				return 3;
			}
		}
	}
}
