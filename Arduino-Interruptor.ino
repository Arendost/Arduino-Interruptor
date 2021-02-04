const int buttonPin = 2;    
const int ledPin = 13;      

int ledState = LOW;        
int buttonState;             
int lastButtonState = LOW;   

unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;   

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        ledState = !ledState;
        
        //digitalWrite(ledPin, ledState);
        
        if(ledState==HIGH)  
        {
         digitalWrite(ledPin, HIGH);          //en todo este bloque se usa ledState como un interruptor
        }
        else
        {
        digitalWrite(ledPin, LOW);  
        }
        
      }
    }
  }
  
  lastButtonState = reading;
}
