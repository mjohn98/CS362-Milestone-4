// PSEUDOCODE for next steps:
// Determine how far away a train the user is tracking is, and update timeAway to play the correct buzzer sound
int timeAway = 5;

void setup() {
  if (timeAway == 15){
    tone(buzzerPin, 1500, 100);
  } 
  if (timeAway == 10){
    tone(buzzerPin, 1500, 100);
  } 
  if (timeAway == 5){
    tone(buzzerPin, 2500, 100);
  }
}

void loop() {
}
