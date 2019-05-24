void setup() {

pinMode(5, INPUT); // intrare impulsuri de la canalul 1 (steer)
pinMode(6, INPUT); // intrare impulsuri de la canalul 2 (throttle)

pinMode(9, OUTPUT); // comanda pentru ESC motor stanga
pinMode(10, OUTPUT); // comanda pentru ESC motor dreapta

}

void loop() {
  
int ch1, ch2, EscLeft, EscRight, Steer;

ch1 = pulseIn(5, HIGH, 25000); // citeste durata impulsurilor de pe canalul 1 (in microsecunde)
ch2 = pulseIn(6, HIGH, 25000); // citeste durata impulsurilor de pe canalul 2 (in microsecunde)

Steer = ch1-1570; // 1570 este durata impulsurilor cand volanul nu este actionat. Steer va avea valoarea 0
EscLeft = ch2-400; // pozitia mediana a tragaciului throttle ch2=1570 va corespunde comenzii catre ESC-ul motorului stanga pentru viteza 0
EscRight = ch2-400; // pozitia mediana a tragaciului throttle ch2=1570 va corespunde comenzii catre ESC-ul motorului dreapta pentru viteza 0

if (Steer>0)             // Daca am actionat volanul catre stanga ch1 creste incepand de la 1570
  EscLeft=EscLeft-Steer; // ESC-ul motorului din stanga va fi comandat cu impulsuri mai scurte cu Steer microsecunde decat ESC-ul din dreapta 
else                       // Daca am actionat volanul catre stanga ch1 scade incepand de la 1570
  EscRight=EscRight+Steer; // ESC-ul motorului din dreapta va fi comandat cu impulsuri mai scurte cu Steer microsecunde decat ESC-ul din stanga

digitalWrite(9, HIGH);                  // inceputul impulsurilor de comanda : stanga
digitalWrite(10, HIGH);                 //                                     dreapta
if (EscLeft<EscRight){
  delayMicroseconds(EscLeft);
  digitalWrite(9, LOW);                 // sfarsitul impulsului mai scurt (stanga)
  delayMicroseconds(EscRight-EscLeft);  
  digitalWrite(10, LOW);                // sfarsitul impulsului mai lung (dreapta)
  delayMicroseconds(20000-EscRight);    // perioada de repetitie a impulsurilor este de 20000 microsecunde
  }
else {
  delayMicroseconds(EscRight);
  digitalWrite(10, LOW);                // sfarsitul impulsului mai scurt (dreapta)
  delayMicroseconds(EscLeft-EscRight);
  digitalWrite(9, LOW);                 // sfarsitul impulsului mai lung (stanga)
  delayMicroseconds(20000-EscLeft);     // perioada de repetitie a impulsurilor este de 20000 microsecunde
  }

}
