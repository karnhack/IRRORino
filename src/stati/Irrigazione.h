if (first_pass) {
    Serial.println("Fase: IRRIGAZIONE");
    digitalWrite(pinPompa, ACCESO);      // accendi pompa
}

if (trascorso >= durataIrrigazione) {    // durataIrrigazione è il timeout in secondi impostabile in Setup_Orari.h
    digitalWrite(pinPompa, SPENTO);      // se è trascorso durataIrrigazione pompa irrigazione spenta
    fase = RIEMPIMENTO_RABOCCO;
}
