#define MOTOR_SPEED 180
//ideja sa dva senzora, jedan desno i jedan naprijed

//Right motor
int enableRightMotor = 5;  //a
int rightMotorPin1 = 9;
int rightMotorPin2 = 10;

//Left motor
int enableLeftMotor = 6;  //b
int leftMotorPin1 = 7;
int leftMotorPin2 = 8;

//sensor front
int trigFront = 1;
int echoFront = 2;

//sensor right
int trigRight = 3;
int echoRight = 4;


void moveForward();
void moveBackwards();
void reverseRight();
void moveRight();
void stop();
void park();
int distance(int trig, int echo);

void setup() {

  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(trigRight, OUTPUT);  
  pinMode(echoRight, INPUT);   
  pinMode(trigFront, OUTPUT);  
  pinMode(echoFront, INPUT);
  stop();
}

void loop() {

  if (distance(trigRight, echoRight) > 30 && distance(trigFront, echoFront) > 20) {
    moveForward();
    delay(1500);
    stop();
    delay(1000);
    park();
    stop();
    delay(1000);
  } else {
    
    stop();
    
  }
}


void park() {
  moveBackwards();
  delay(600);
  stop();
  delay(1000);
  reverseRight();
  delay(1000);
  stop();
  delay(1000);
  moveBackwards();
  delay(1500);
  stop();
  delay(1000);
  moveRight();
  delay(800);
}

int distance(int trig, int echo) {

  int distance = 0;
  long duration = 0;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}

void moveForward() {

  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  analogWrite(enableRightMotor, MOTOR_SPEED);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);

  analogWrite(enableLeftMotor, MOTOR_SPEED);
}

void moveRight() {

  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
  analogWrite(enableRightMotor, MOTOR_SPEED / 2);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);

  analogWrite(enableLeftMotor, MOTOR_SPEED);
}

void reverseRight() {

  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
  analogWrite(enableRightMotor, MOTOR_SPEED / 3);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);

  analogWrite(enableLeftMotor, MOTOR_SPEED);
}

void moveBackwards() {
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
  analogWrite(enableRightMotor, MOTOR_SPEED);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);

  analogWrite(enableLeftMotor, MOTOR_SPEED);
}

void stop() {

  analogWrite(enableRightMotor, 0);
  analogWrite(enableLeftMotor, 0);
}