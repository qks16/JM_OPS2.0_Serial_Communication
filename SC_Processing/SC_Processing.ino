char message = ' ';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  while(!Serial.available()) {}

    message = Serial.read();
    delay(1000);
    // Serial.print("message: ");
    // Serial.println(message);
    Serial.write(message);
    delay(1000);
    //Serial.write(message);f



  // Serial.print("points: ");
  // Serial.print(points);

  // Serial.print(" signal: ");
  // //Serial.println(stoplightSignal);
  // Serial.println(message);

  // i++
}