if (first_pass) {
    Serial.println("Fase: PAUSA_24H");
    Serial.print("Prossima irrigazione giorno/ora:");
    Serial.print(" ");
    if (ePausa == ATTIVO)
    {
        Serial.print( giornoFuturo24h, DEC );
    }
    else
    {
        Serial.print( adessoGiorno, DEC );
    }
    Serial.print("/");
    Serial.print( orarioStart, DEC );
    Serial.print("(");
    Serial.print("min");
    Serial.print(")");
    Serial.println();
}

if (trascorso >= 86400) {  // evento: trascorso un giorno (86400 sec)
    ePausa = NONATTIVO;
    fase = RIPOSO;
}

if (adessoOra == 1439) { // quando l'ora attuale arriva alle 23 59
    ePausa = NONATTIVO;     // metti ePausa come non attivo false
    fase = RIPOSO;          // passa a fase riposo
}
