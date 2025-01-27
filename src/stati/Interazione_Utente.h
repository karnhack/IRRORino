/***** Primo avvio (I fase). Viene chiesto di resettare, se risposta Si imposta  */
/***** ePausa come true. Trascorsi 10 sec imposta ePausa come false.             */
/***** In ogni caso si passa alla fase RIEMPIMENTO_RABOCCO.                      */

if (first_pass) {
    Serial.println("Fase: INTERAZIONE UTENTE ");                        // stampo la fase su seriale
    Serial.println("Se è il Primo Avvio o vuoi Resettare premi [s]");   // stampo la domanda su seriale
}

if (trascorso >= 10) {                                                  // evento: timeout 10 secondi
    ePausa = NONATTIVO;                                                 // imposta ePausa come false NON ATTIVO
    fase = RIEMPIMENTO_RABOCCO;                                         // vai a fase RIEMPIMENTO_RABOCCO
}
else if (Serial.available()  &&  tolower(Serial.read()) == 's') {       // evento ricevuto s
    ePausa = ATTIVO;                                                    // ePausa true ATTIVO. L unico modo per mettere ePausa in true è premere S
    Serial.print("Selezionato Primo Avvio/Reset");
    Serial.println();
    mem.write(12, giornoFuturo40gg);                             // Primo avvio o reset, scrivo il giorno della prima concimazione su nvram
    mem.write(13, meseFuturo40gg);                                // scrivo il mese della prossima irrigazione su nvram
    fase = RIEMPIMENTO_RABOCCO;                                         // vai a fase RIEMPIMENTO_RABOCCO
}
