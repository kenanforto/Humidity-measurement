Arduino kod:
//definisanje pinova na arduinu
int senzor=A0;
int led=13;
float granicninapon=3.5;
void setup() {
 Serial.begin(9600);
//konfigurisanje izlaza/ulaza arduina
 pinMode(senzor, INPUT);
 pinMode(led, OUTPUT);
}
void loop() {
 int ocitanje=analogRead(senzor); //ocitavanje stanja senzora 
 float napon=ocitanje*5/1024; //skaliranje ocitane velicine na opseg od 0 do 5V
 Serial.println(ocitanje); //ispisivanje ocitane velicine na displayu sa prelaskom u novi red
 Serial.println(napon); //ispisivanje napona na displayu sa prelaskom u novi red
 if(napon<granicninapon) // provjera nivoa vlaznosti
 {
 Serial.println("Zabrinjavajuci nivo vlaznosti!");
 digitalWrite(led, 1);
 }
 else
 {
 digitalWrite(led, 0);
 }
 delay(1000); //ponavljanje postupka svakih 1000ms
}
