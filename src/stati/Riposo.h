/***** Se solo l'ora coincide con gli orari di irrigazione (orarioStart) allora irriga.   */
/***** Se oltre all'ora coincidono giorno e mese nvram allora concima                     */                                                           

if (first_pass) {
    Serial.println("Fase: RIPOSO");
    Serial.print("Prossima concimazione  Giorno/Mese:");
    Serial.print(" ");
    Serial.print( giornoNVRAM, DEC );
    Serial.print(" ");
    Serial.print("/");
    Serial.print(" ");
    Serial.print( meseNVRAM, DEC );
    Serial.println();
    Serial.print("Prossima irrigazione   Giorno/Ora :");
    Serial.print(" ");
    if ( ePausa == ATTIVO )
    {
        Serial.print( giornoNVRAM, DEC );
    }
    else
    {
        Serial.print( adessoGiorno, DEC );
    }
    Serial.print(" ");
    Serial.print(" ");
    Serial.print("/");
    Serial.print(" ");
    Serial.print( orarioStart, DEC );
    Serial.print("(");
    Serial.print("min");
    Serial.print(")");
    Serial.println();
    
}

if ((adessoOra == orarioStart)            // se l'ora attuale è uguale a orarioStart
    && (adessoGiorno != giornoNVRAM)      // se il giono nvram è diverso da quello attuale
    && (adessoMese != meseNVRAM))         // se il mese nvram è diverso da quello attuale
    {
    fase = IRRIGAZIONE;                   // irrigazione quotidiana
    }
else if ((adessoOra == orarioStart)       // se l'ora attuale è uguale a orarioStart
         && (adessoGiorno == giornoNVRAM) // se il giono nvram è uguale a quello attuale
         && (adessoMese == meseNVRAM))    // se il mese nvram è uguale a quello attuale
    {
    fase = CONCIMAZIONE;                  // concimazione
    }
