if (first_pass) {
    Serial.println("Fase: CONCIMAZIONE");
}

// avvia peristaltica e agitatore e ad operazioni concluse

mem.write(12, giornoFuturo40gg);   // scrivo il giorno della prossima concimazione su nvram
mem.write(13, meseFuturo40gg);     // scrivo il mese della prossima concimazione su nvram */
fase = IRRIGAZIONE;
