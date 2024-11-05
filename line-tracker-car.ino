#define rightSensor 8
#define leftSensor 12
#define middleSensor 10
#define md1d 9
#define md1g 6
#define md2d 5
#define md2g 3


void setup() {
  // put your setup code here, to run once:
  
  pinMode(md1d, OUTPUT);
  pinMode(md1g, OUTPUT);
  pinMode(md2d, OUTPUT);
  pinMode(md2g, OUTPUT);
  pinMode(leftSensor, INPUT);  
  pinMode(rightSensor, INPUT);
  pinMode(middleSensor,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int inLeft , inRight ,inMiddle;
  
  inMiddle = digitalRead(middleSensor);  // Read the state of the IR sensor
  inRight = digitalRead(rightSensor);
  inLeft = digitalRead(leftSensor);
  
  if (inMiddle == 1 && inRight == 0 && inLeft == 0){
    move_forward();
}
  else if(inMiddle == 0 && inRight == 1 && inLeft == 0){
    stop();
    turn_right();
}
  else if(inMiddle == 0 && inRight == 0 && inLeft == 1){
    stop();
    turn_left();
}
  else if(inMiddle == 1 && inRight == 1 && inLeft == 1 ){
    move_forward();
}
  else if(inMiddle == 1 && inRight == 1 && inLeft == 0 ){
    move_forward();
}
  else if(inMiddle == 1 && inRight == 0 && inLeft == 1 ){
    move_forward();
}


}
void move_forward() {
  digitalWrite(md1d, LOW);
  digitalWrite(md1g,HIGH );
  digitalWrite(md2d,HIGH );
  digitalWrite(md2g, LOW);
}
void turn_right() {
  digitalWrite(md1d, LOW);
  digitalWrite(md1g, HIGH);
  digitalWrite(md2d, LOW);
  digitalWrite(md2g, HIGH);
}
void turn_left() {
  digitalWrite(md1d, HIGH);
  digitalWrite(md1g, LOW);
  digitalWrite(md2d, HIGH);
  digitalWrite(md2g, LOW);
}
void reculler() {
  digitalWrite(md1d, HIGH);
  digitalWrite(md1g,LOW );
  digitalWrite(md2d,LOW );
  digitalWrite(md2g, HIGH);
}
void stop() {
  digitalWrite(md1d, LOW);
  digitalWrite(md1g, LOW);
  digitalWrite(md2d, LOW);
  digitalWrite(md2g, LOW);
}
void checkLine(int middle,int right,int left){
    if(middle == HIGH && right == LOW && left == LOW){
      move_forward();
      Serial.println("moving forward");
    }
    else if((middle == HIGH && right == HIGH && left == LOW)||(middle == HIGH && right == LOW && left == HIGH)){
      move_forward();
      Serial.println("moving forward but with pranks");
      Serial.println();
    }
    else if(middle == LOW && right == HIGH && left == LOW){
      turn_left();
      Serial.println("turning left");
    }
        else if(middle == LOW && right == LOW && left == HIGH){
      turn_right();
      Serial.println("turning right");
    }
}
