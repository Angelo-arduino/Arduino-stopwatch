#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C LCD (0x27, 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Buttons
#define START_BTN 2
#define STOP_BTN 3
#define RESET_BTN 4

// LEDs
#define yellow_LED 5
#define RED_LED 6
#define blue_LED 8
#define BUZZER 7

bool running = false;
unsigned long startTime = 0;
unsigned long elapsedTime = 0;
unsigned long lastBeep = 0;

void beep() {
  digitalWrite(BUZZER, HIGH);
  delay(50);
  digitalWrite(BUZZER, LOW);
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("STOPWATCH READY");

  pinMode(START_BTN, INPUT_PULLUP);
  pinMode(STOP_BTN, INPUT_PULLUP);
  pinMode(RESET_BTN, INPUT_PULLUP);

  pinMode(yellow_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(blue_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(RED_LED, HIGH); // initially stopped
}

void loop() {

  // START button
  if (digitalRead(START_BTN) == LOW && !running) {
    delay(200); // debounce
    running = true;
    startTime = millis() - elapsedTime;
    lastBeep = millis();
    digitalWrite(yellow_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(blue_LED, LOW);
    beep();
  }

  // STOP button
  if (digitalRead(STOP_BTN) == LOW && running) {
    delay(200);
    running = false;
    elapsedTime = millis() - startTime;
    digitalWrite(yellow_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(blue_LED, LOW);
    beep();
  }

  // RESET button
  if (digitalRead(RESET_BTN) == LOW) {
    delay(200);
    running = false;
    elapsedTime = 0;
    digitalWrite(yellow_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(blue_LED, HIGH);
    lcd.clear();
    lcd.print("RESET");
    beep();
    delay(500);
  }

  // Calculate time
  unsigned long displayTime = running ? millis() - startTime : elapsedTime;
  unsigned int totalSeconds = displayTime / 1000;
  unsigned int minutes = totalSeconds / 60;
  unsigned int seconds = totalSeconds % 60;
  unsigned int milliseconds = (displayTime % 1000) / 10; // 2-digit ms

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Time:           ");

  lcd.setCursor(0, 1);
  if(minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if(seconds < 10) lcd.print("0");
  lcd.print(seconds);
  lcd.print(":");
  if(milliseconds < 10) lcd.print("0");
  lcd.print(milliseconds);
  lcd.print("   ");

  // BEEP every second while running
  if (running && millis() - lastBeep >= 1000) {
    beep();
    lastBeep = millis();
  }
}