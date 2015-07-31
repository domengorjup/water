int PUMP_OUT = 4;
int HYGRO_IN = 12;
int HYGRO_ANALOG = A0;
int LED = 13;
int hygroValue;
int hygroTrigger = 0; 

int pumpaj = 0;
int sekund = 3;
int pavza_sekund = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(PUMP_OUT, OUTPUT);
  pinMode(HYGRO_IN, INPUT);
  pinMode(HYGRO_ANALOG, INPUT);
  digitalWrite(PUMP_OUT, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  hygroValue = analogRead(HYGRO_ANALOG);
  hygroTrigger = digitalRead(HYGRO_IN);
  Serial.println(hygroValue);

  if (hygroTrigger) {
    digitalWrite(LED, HIGH);
    Serial.println("  -- Zalivam  --  ");
    if (pumpaj){
      zalivaj();
    }
    else {
      delay(2000);
      }
    digitalWrite(LED, LOW);
    }
   delay(300);
}

void zalivaj(){
  digitalWrite(PUMP_OUT, HIGH);
  delay(sekund*1000);
  digitalWrite(PUMP_OUT, LOW);
  delay(pavza_sekund*1000);
}
