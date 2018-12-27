unsigned short replace(char *oldChain, char *newChain, char *text, char *buffer, unsigned short bufferSize)
{
	
	unsigned short oldChainSize = 0, newChainSize = 0; //D³ugoœci ci¹gów
	unsigned short oldChainIndex = 0; //Index starego ci¹gu
	unsigned short iLetter = 0; // Licznik pomocniczy
	
	//Kopiowanie oryginalnego tekstu do bufora
	while (text[iLetter] != 0) {
		buffer[iLetter] = text[iLetter];
		iLetter++;
	}
	iLetter = 0;
	
	//Zliaczanie rozmiarów podanych ci¹gów
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
		
	//Sprawdzanie czy ci¹gi nie s¹ identyczne
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
	  	
	//Sprawdzanie czy stary ci¹g nie jest jednoliterowym powieleniem nowego. Jeœli jest, funkcja zostaje przerwana.
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
		//Szukanie indeksu starego ci¹gu - aby by³o wiadomo w którym miejscu w tablicy nale¿y podstawiæ tekst.
		while (iLetter < bufferSize - oldChainSize + 1){
			if (buffer[iLetter] == oldChain[0]) {
			int iOldChain = 0;
			unsigned int iSum = 0;
				for (unsigned short i = iLetter; iOldChain < oldChainSize; i++,iOldChain++) {
					if (buffer[i] == oldChain[iOldChain]) {
						iSum++;
					}
				}
				//Wiêksze lub równe, dlatego dla obs³ugi przypadku zamieniana jest ostatnia litera z ci¹gu.
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
		
		//Obcinanie lub dodawanie znaków w ci¹gu w miejsce zamienianego wyrazu - jeœli ci¹gi maj¹ t¹ sam¹ d³ugoœæ, mo¿e pozostaæ bez zmian
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
	    
	    //W³aœciwa zamiana
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
