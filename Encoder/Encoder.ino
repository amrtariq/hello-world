const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
volatile int counter=0;
// variables will change:
volatile int buttonState = 0;         // variable for reading the pushbutton status
volatile int e=0;
int t=0;
int old=0;
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // Attach an interrupt to the ISR vector
  attachInterrupt(0, pin_ISR, RISING);
  Serial.begin(115200);
}

void loop() {
  e=0;
  // Nothing here!
  //Serial.println(digitalRead(2));
}

void pin_ISR() {
  
  if(e==0){
    e=1;
  
t=millis()-old;
if(t>20){
  buttonState=!buttonState;
  digitalWrite(ledPin,buttonState );
  counter +=1;
  Serial.println(counter);
  old = millis();
}
  }
}
