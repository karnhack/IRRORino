/***** Finche' l'inturruttore (livello acqua) e' aperto, elettrovalvola aperta e viceversa */
/***** Finito il riempimento se (ePausa true, primo riemimento) fa una pausa di 24h circa */
/***** altrimenti passa alla fase RIPOSO. Se dal riempimento passano tre minuti ALLARME.  */

if (first_pass) {
    Serial.println("Fase: RIEMPIMENTO / RABOCCO");
    digitalWrite(pinElettrovalvola, ACCESO);        // valvola aperta
}

if (digitalRead(pinTroppopieno) == CHIUSO) {        // se bidone pieno
    digitalWrite(pinElettrovalvola, SPENTO);        // chiudi valvola
    if (ePausa == ATTIVO) { fase = PAUSA_24H; }     // Se ePausa e true vai a PAUSA 24
    else                  { fase = RIPOSO;    }     // altrimenti vai a RIPOSO
}
else if (trascorso >= 180) {                        // e se timeout riempimento supera i 3 minuti
    digitalWrite(pinElettrovalvola, SPENTO);        // chiudi valvola
    fase = ALLARME;                                 // vai ad allarme contatto guasto o manca acqua
}


/*    do { digitalWrite(pinElettrovalvola, ACCESO); }
    while (digitalRead(pinTroppopieno) == CHIUSO);
if (digitalRead(pinTroppopieno) == CHIUSO) {        // se bidone pieno
    digitalWrite(pinElettrovalvola, SPENTO);        // chiudi valvola

}
*/
