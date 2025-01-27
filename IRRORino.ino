/*---------------------------------------------------------------------------
  
                                   * IRRORino *
                                 * versione 0.8 *
  
Irrigatore/Concimatore automatico per piante e giardini
  
di KARNHACK  - info@karnhack.com - http://karnhack.com
  
Si ringraziano Claudio_FF, Maurotec e gli altri utenti del forum italiano
arduino.cc (https://forum.arduino.cc/index.php?topic=617496.0)
che hanno contrubuito in modo sostanziale a questo mio primo progetto.

---------------------------------------------------------------------------*/

#include "IRRORino.h"

void setup() {
#include "src/Setup.h"
}

void loop() {
  
  #include "src/Funzioni_Variabili_Globali.h"

  switch (fase) {
    
    case INTERAZIONE_UTENTE:
      #include "src/stati/Interazione_Utente.h"
    break;

    case PAUSA_24H:
      #include "src/stati/Pausa_24h.h"
    break;

    case RIEMPIMENTO_RABOCCO:
      #include "src/stati/Riempimento_Rabocco.h"
    break;                                                            

    case RIPOSO:
      #include "src/stati/Riposo.h"
    break;

    case CONCIMAZIONE:
      #include "src/stati/Concimazione.h"
    break;

    case IRRIGAZIONE:
      #include "src/stati/Irrigazione.h"
    break;

    case ALLARME:
      #include "src/stati/Allarme.h" 
    break;

    default:
    break;

  }  // fine switch
}    // fine void loop
