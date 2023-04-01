// References: https://www.youtube.com/watch?v=AgQW81zzR18&t=1216s 
// https://www.youtube.com/watch?v=aMato4olzi8
// https://www.circuito.io/app?components=512,11021 

int LEDPin = 6;
int LEDPinTwo = 7;

int buttonPin = 2;
int buttonPinTwo = 3;
int buttonNew; // reads in current value
int buttonNewTwo; 

int buttonOld=1; // is 1 before you press button

int buttonOldTwo=1; // is 1 before you press butto
int dt=100;
bool lineSelected = false;
bool stopSelected = false;

int userLine;
int userStop; 

void setup() {
  Serial.begin(9600);
  // light output
  pinMode(LEDPin, OUTPUT);
  pinMode(LEDPinTwo, OUTPUT);

  // button input
  pinMode(buttonPin, INPUT);
  pinMode(buttonPinTwo, INPUT);


}
int index = 1;
int stopIndex = 1;
void loop() {
    buttonNew = digitalRead(buttonPin);
    buttonNewTwo = digitalRead(buttonPinTwo);
    if(buttonOld==0 && buttonNew==1){
        // swap the line selection
        if(index == 1){
          index = 2;
        }
        else{
          index = 1;
        }
        Serial.print("Current Index: ");
        Serial.println(index);
        userLine = index;
    }
    buttonOld=buttonNew;

    // confirm input selected
    if(buttonOldTwo==0 && buttonNewTwo==1){
        Serial.print("Selected Index: ");
        Serial.print(index);
        digitalWrite(LEDPin, HIGH);
        // if line is already selected, this means the input to confirm is the stop
        if(lineSelected){
          stopSelected = true;
          digitalWrite(LEDPinTwo, HIGH);
        }
        lineSelected = true;
    }
    buttonOldTwo=buttonNewTwo;
    // deal with the stop index
    delay(dt);
}  
