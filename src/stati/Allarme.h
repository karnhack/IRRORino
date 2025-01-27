if (first_pass) {
    Serial.println("Fase: ALLARME");
}

if (trascorso >= 3600) {              // dopo un ora (per mancanza acqua)
    fase = RIEMPIMENTO_RABOCCO;       // riprova fase RIEMPIMENTO_RABOCCO
}
