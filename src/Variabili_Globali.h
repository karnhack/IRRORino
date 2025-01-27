// DS3231 RTC;
RTC_DS3231 RTC;
int adessoOra;          // ora RTC, tempi da 0 a 1439 minuti
byte adessoMese;        // RTC mese
byte adessoGiorno;      // RTC giorno
byte giornoNVRAM; // giorno su nvram (x concimazione)
byte meseNVRAM;   // mese su nvram   (x concimazione)
int orarioStart;        // ora di inizio in base alla stagione
int orarioStop;         // ora di fine in base alla stagione

// legge gli orari di inizio/fine estivi/invernali, tempi da 0 a 1439 minuti
int inizioEstivo = OraIrrigazione[0] * 60 + OraIrrigazione[1];
int inizioInvernale = OraIrrigazione[2] * 60 + OraIrrigazione[3];

// restituisce true quando è inverno, false diversamente.
// GEN 1,FEB 2,MAR 3,APR 4,MAG 5,GIU 6,LUG 7,AGO 8,SET 9,OTT 10,NOV 11,DIC 12
bool eInverno(uint8_t mese) {
    if ( (mese >= 11) || (mese <= 2) ) return true;
    else return false; }

byte     fase = INTERAZIONE_UTENTE;  // fase iniziale
byte     old_fase = ~fase;
bool     first_pass;                 // vera un ciclo quando una fase diventa attiva
uint32_t inizio_fase;                // tempo di inizio fase
uint32_t trascorso;                  // secondi trascorsi da attivazione fase

bool     ePausa;                     // è Pausa 24h? vera se si resetta altrimenti falsa

byte giornoFuturo40gg;                // giorno attuale + 40gg
byte meseFuturo40gg;                  // mese attuale   + 40gg
byte giornoFuturo24h;                 // giorno attuale + 24h
byte meseFuturo24h;                   // mese attuale   + 24h
