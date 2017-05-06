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

void roundRight (int vel) {
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

void roundLeft (int vel) {
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

void setup() {
  pinMode(IN1A, PWM);
  pinMode(IN1B, PWM);
  pinMode(IN2A, PWM);
  pinMode(IN2B, PWM);
  pinMode(IN3A, PWM);
  pinMode(IN3B, PWM);
  pinMode(IN4A, PWM);
  pinMode(IN4B, PWM);

}

void loop() {
  // put your main code here, to run repeatedly:
  forward(50);
  delay(2000);
  backward(50);
  delay(2000);
  left(50);
  delay(2000);
  right(50);
  delay(2000);
  roundRight(50);
  delay(2000);
  roundLeft(50);
  delay(2000);
  diagonalLeft(-50);
  delay(2000);
  diagonalLeft(50);
  delay(2000);
  diagonalRight(-50);
  delay(2000);
  diagonalRight(50);
  delay(2000);
  stopm();

  while (1);
}
