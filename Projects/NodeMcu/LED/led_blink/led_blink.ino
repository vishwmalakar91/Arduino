const int LED_RED = D1;
const int LED_GREEN = D2;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, HIGH);
  delay(1000);                      // Wait for a second
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);  // Turn the LED off by making the voltage HIGH
  delay(1000);
}
