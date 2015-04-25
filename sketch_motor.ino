// Pin definitions for H bridge in arduino
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
//#define speedMotorA 10
//#define speedMotorB 11

// Pin definitions for HC-SR04
#define echoPin 8              // the SRF05's echo pin
#define initPin 9              // the SRF05's init pin

// Define states
#define RIGHT 0
#define FORWARD 1
#define LEFT 2
#define BACKWARD 3

const int LoopPeriod = 20; // 20 ms interval for each loop
unsigned long TimeLoopDelay = 0; // Long because grows quickly

int PulseTime;
int Distance;

int state = FORWARD;

void setup()
{
 // Configure motor pins
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 //pinMode(speedMotorA, OUTPUT);
 //pinMode(speedMotorB, OUTPUT);
 
 // Configure ultrasound pins
 pinMode(initPin, OUTPUT);
 pinMode(echoPin, INPUT);
}
  
void loop()
{
 
 // Here is where the code that needs to be running all the time comes
 //analogWrite(speedMotorA, 255);
 //analogWrite(speedMotorB, 255);
 
  if(millis() - TimeLoopDelay >= LoopPeriod){
    readUltrasonic(); // read and store the measured distances
    stateMachine();  
    TimeLoopDelay = millis();
  }
}

void stateMachine()
{
  if(state == FORWARD){ // no obstacles detected
    // if there's nothing in front of us
    if(Distance > 6 || Distance < 0){
            moveForward();
    }
    // there's an object in front of it
    else{
      stopMotor ();
      state = LEFT;
    }
  }
  else if(state == LEFT){ // obstacle detected -- turn left
    turnLeft();
    delay(1700); // aproximatelly 900 ms gives 90 degrees (keep checking)
    stopMotor ();
        
    state = FORWARD;
  }
}

void readUltrasonic()
{
  digitalWrite(initPin, HIGH);
  delayMicroseconds(10); // must keep the trig pin high for at least 10us
  digitalWrite(initPin, LOW);
    
  PulseTime = pulseIn(echoPin, HIGH);
  Distance = PulseTime/58.2; // PaceOfSound = 1/SpeedOfSound = 29.1 us/cm
}

void turnRight()
{
  //Gira o Motor A no sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Gira o Motor B no sentido anti-horario
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft()
{
  //Gira o Motor A no sentido anti-horario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //Gira o Motor B no sentido horario
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveForward()
{
  //Gira o Motor A no sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Gira o Motor B no sentido horario
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackwards(){
  //Gira o Motor A no sentido anti-horario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //Gira o Motor B no sentido anti-horario
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotor(){
  //Para o motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  //Para o motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}


