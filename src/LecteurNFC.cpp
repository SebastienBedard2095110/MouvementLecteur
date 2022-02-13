
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include "LecteurNFC.h"




LecteurNFC::LecteurNFC(AbstractChaine* prochain)
	: AbstractChaine(prochain),
		nfc(PN532_SCK, PN532_MISO, PN532_MOSI, PN532_SS)
{
	nfc.begin();
	
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Impossible de trouver la carte PN532");
    while (1);
  }

	 nfc.setPassiveActivationRetries(0xFF);
  
  nfc.SAMConfig();
}




void LecteurNFC::traiter(Requete requete)  {
	bool reussi;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength = 0;
  
  reussi = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
  
  if ( ! reussi)
		return;

	char* ptr = requete.clef;
	for (uint8_t i=0; i < uidLength; i++) {
		int len = sprintf(ptr, "%x", uid[i]);
		ptr += len;
	}

	faireSuivre(requete);

	delay(1000);
}
