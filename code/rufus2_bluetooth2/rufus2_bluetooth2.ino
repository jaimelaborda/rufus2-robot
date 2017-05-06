//MOTORES
#define IN1A PA0
#define IN1B PA9
#define IN2A PA10
#define IN2B PB0
#define IN3A PA7
#define IN3B PA6
#define IN4A PA3
#define IN4B PA2

void forward (int vel) {
  int pwm_duty = map(vel, 0, 100, 0, 65535);

  pwmWrite(IN1A, pwm_duty);
  pwmWrite(IN1B, 0);
  pwmWrite(IN2A, pwm_duty);
  pwmWrite(IN2B, 0);

  pwmWrite(IN3A, pwm_duty);
  pwmWrite(IN3B, 0);
  pwmWrite(IN4A, pwm_duty);
  pwmWrite(IN4B, 0);
}

void backward (int vel) {
  int pwm_duty = map(vel, 0, 100, 0, 65535);

  pwmWrite(IN1A, 0);
  pwmWrite(IN1B, pwm_duty);
  pwmWrite(IN2A, 0);
  pwmWrite(IN2B, pwm_duty);

  pwmWrite(IN3A, 0);
  pwmWrite(IN3B, pwm_duty);
  pwmWrite(IN4A, 0);
  pwmWrite(IN4B, pwm_duty);
}

void right (int vel) {
  int pwm_duty = map(vel, 0, 100, 0, 65535);

  pwmWrite(IN1A, pwm_duty);
  pwmWrite(IN1B, 0);
  pwmWrite(IN2A, 0);
  pwmWrite(IN2B, pwm_duty);

  pwmWrite(IN3A, 0);
  pwmWrite(IN3B, pwm_duty);
  pwmWrite(IN4A, pwm_duty);
  pwmWrite(IN4B, 0);
}

void left (int vel) {
  int pwm_duty = map(vel, 0, 100, 0, 65535);

  pwmWrite(IN1A, 0);
  pwmWrite(IN1B, pwm_duty);
  pwmWrite(IN2A, pwm_duty);
  pwmWrite(IN2B, 0);

  pwmWrite(IN3A, pwm_duty);
  pwmWrite(IN3B, 0);
  pwmWrite(IN4A, 0);
  pwmWrite(IN4B, pwm_duty);
}

void roundLeft (int vel) {
  int pwm_duty = map(vel, 0, 100, 0, 65535);

  pwmWrite(IN1A, pwm_duty);
  pwmWrite(IN1B, 0);
  pwmWrite(IN2A, 0);
  pwmWrite(IN2B, pwm_duty);

  pwmWrite(IN3A, pwm_duty);
  pwmWrite(IN3B, 0);
  pwmWrite(IN4A, 0);
  pwmWrite(IN4B, pwm_duty);
}

void roundRight (int vel) {
  int pwm_duty = map(vel, 0, 100, 0, 65535);

  pwmWrite(IN1A, 0);
  pwmWrite(IN1B, pwm_duty);
  pwmWrite(IN2A, pwm_duty);
  pwmWrite(IN2B, 0);

  pwmWrite(IN3A, 0);
  pwmWrite(IN3B, pwm_duty);
  pwmWrite(IN4A, pwm_duty);
  pwmWrite(IN4B, 0);
}

void diagonalLeft (int vel) {

  if (vel < 0) {
    int pwm_duty = map(vel, -100, 0, 65535, 0);

    pwmWrite(IN1A, 0);
    pwmWrite(IN1B, 0);
    pwmWrite(IN2A, 0);
    pwmWrite(IN2B, pwm_duty);

    pwmWrite(IN3A, 0);
    pwmWrite(IN3B, pwm_duty);
    pwmWrite(IN4A, 0);
    pwmWrite(IN4B, 0);
  } else {
    int pwm_duty = map(vel, 0, 100, 0, 65535);

    pwmWrite(IN1A, 0);
    pwmWrite(IN1B, 0);
    pwmWrite(IN2A, pwm_duty);
    pwmWrite(IN2B, 0);

    pwmWrite(IN3A, pwm_duty);
    pwmWrite(IN3B, 0);
    pwmWrite(IN4A, 0);
    pwmWrite(IN4B, 0);
  }
}

void diagonalRight (int vel) {

  if (vel < 0) {
    int pwm_duty = map(vel, -100, 0, 65535, 0);

    pwmWrite(IN1A, 0);
    pwmWrite(IN1B, pwm_duty);
    pwmWrite(IN2A, 0);
    pwmWrite(IN2B, 0);

    pwmWrite(IN3A, 0);
    pwmWrite(IN3B, 0);
    pwmWrite(IN4A, 0);
    pwmWrite(IN4B, pwm_duty);
  } else {
    int pwm_duty = map(vel, 0, 100, 0, 65535);

    pwmWrite(IN1A, pwm_duty);
    pwmWrite(IN1B, 0);
    pwmWrite(IN2A, 0);
    pwmWrite(IN2B, 0);

    pwmWrite(IN3A, 0);
    pwmWrite(IN3B, 0);
    pwmWrite(IN4A, pwm_duty);
    pwmWrite(IN4B, 0);
  }
}

void stopm (void) {
  pwmWrite(IN1A, 0);
  pwmWrite(IN1B, 0);
  pwmWrite(IN2A, 0);
  pwmWrite(IN2B, 0);

  pwmWrite(IN3A, 0);
  pwmWrite(IN3B, 0);
  pwmWrite(IN4A, 0);
  pwmWrite(IN4B, 0);
}

//VARIABLES GLOBALES
int speedR = 50;

void setup() {
  pinMode(IN1A, PWM);
  pinMode(IN1B, PWM);
  pinMode(IN2A, PWM);
  pinMode(IN2B, PWM);
  pinMode(IN3A, PWM);
  pinMode(IN3B, PWM);
  pinMode(IN4A, PWM);
  pinMode(IN4B, PWM);

  Serial.begin(115200);
  Serial3.begin(9600);

  stopm();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial3.available() > 0){
    char command = Serial3.read();
    Serial.println("Comando BT recibido: "+String(command));

    switch (command) {
      case 'a':
        diagonalLeft(speedR);
        break;
      case 'b':
        forward(speedR);
        break;
      case 'c':
        diagonalRight(speedR);
        break;
      case 'd':
        left(speedR);
      case 'e':
        break;
      case 'f':
        right(speedR);
        break;
      case 'g':
        diagonalRight(-speedR);
        break;
      case 'h':
        backward(speedR);
        break;
      case 'i':
        diagonalLeft(-speedR);
        break;
      case 'j':
        roundRight(speedR);
        break;
      case 'k':
        roundLeft(speedR);
        break;
      case 's':
        stopm();
        break;
      case 'l':
        speedR = 25;
        break;
      case 'm':
        speedR = 50;
        break;
      case 'n':
        speedR = 75;
        break;
      case 'o':
        speedR = 100;
        break;
      default:
        break;
    }
  }
}
