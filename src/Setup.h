pinMode(pinPompa, OUTPUT);                // imposta il pin della pompa come output
pinMode(pinElettrovalvola, OUTPUT);       // imposta il pin dell'elettrovalvola come output
pinMode(pinTroppopieno, INPUT);           // imposta il pin del sensore di livello acqua come input
    
digitalWrite(pinPompa, SPENTO);           // al setup spegne la pompa
digitalWrite(pinElettrovalvola, SPENTO);  // al setup spegne l'elettrovalvola
    
Serial.begin(57600);                       // inizializza seriale sulla porta xxx
Wire.begin();                             // inizializza I2C
RTC.begin();                              // inizializza RTC

/************* decommentare per regolare ora e data (yyyy,mm,dd,hh,mm,ss) *************/
//  RTC.adjust(DateTime(2019, 07, 25, 11, 04, 00));

if (! RTC.begin()) {
    Serial.println("RTC non è attivo!");
    RTC.adjust(DateTime(__DATE__, __TIME__));
}
