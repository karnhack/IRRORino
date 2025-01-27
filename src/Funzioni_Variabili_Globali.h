
// EEPROM object
    AT24CX mem(7, 32);
// Ottengo ora mese e giorno per le variabili globali
    DateTime now = RTC.now();
    DateTime futuro40gg (now + TimeSpan(40,0,0,0)); // aggiunge 40gg al settore giorni (gg, hh, mm, ss)
    DateTime futuro24h (now + TimeSpan(0,24,0,0));  // aggiunge 24 al settore ore (gg, hh, mm, ss)
    adessoOra = now.hour() * 60 + now.minute();     // tempi da 0 a 1439 minuti
    adessoMese = now.month();
    adessoGiorno = now.day();
    giornoFuturo40gg = futuro40gg.day();        // ricavo la variabile
    meseFuturo40gg = futuro40gg.month();        // ricavo la variabile
    giornoFuturo24h = futuro24h.day();            // ricavo la variabile
    meseFuturo24h = futuro24h.month();            // ricavo la variabile
//    giornoNVRAM = mem.read(12);        // ricava il giorno da nvram
//    meseNVRAM = mem.read(13);          // ricava il mese da nvram
    giornoNVRAM = mem.read(12);        // ricava il giorno da nvram
    meseNVRAM = mem.read(13);          // ricava il mese da nvram

// interroga la variabile globale bool per stabilire le due fasce di orario
if (eInverno(adessoMese) == true) {
    orarioStart = inizioInvernale;
}
else
{
    orarioStart = inizioEstivo;
}

// operazione eseguite una sola volta, dopo 10 sec, o sempre
first_pass = false;
if (fase != old_fase) { first_pass = true;  inizio_fase = millis(); }
old_fase = fase;
trascorso = (millis() - inizio_fase) / 1000;
