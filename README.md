# Arduino-stopwatch
Embedded systems stopwatch prototype built with Arduino, integrating user input, real-time timing, and visual/audio feedback.
# Arduino Stopwatch with LCD, LEDs, and Buzzer

## 📌 Overview
This project is a microcontroller-based stopwatch built using Arduino.  
It features a 16×2 I2C LCD for time display, three push buttons for control,
LED indicators for system states, and a buzzer for audio feedback.

## ⚙️ Features
- Start, Stop, and Reset functionality
- Real-time time tracking
- Visual status indication using LEDs
- Audio feedback using a buzzer
- I2C communication for efficient pin usage
- Prototype enclosure for physical interaction

## 🧩 Components Used
- Arduino Uno
- 16×2 I2C LCD
- 3 Push Buttons
- 3 LEDs (Red, Yellow, Blue)
- Buzzer
- Breadboard & Jumper Wires
- Resistors
## code used
[code](https://github.com/Angelo-arduino/Arduino-stopwatch/blob/main/STOPWATCH.ino)

## system circuit
[logic circuit](https://wokwi.com/projects/452666281192415233)

## 🔌 System Logic
The stopwatch operates as a finite state machine:
- **Idle** – waiting for start
- **Running** – time counting
- **Paused** – time halted
- **Reset** – time cleared

## 🛠️ How It Works
The system uses non-blocking timing (millis-based) to accurately track time.
Button inputs control state transitions, while LEDs and the buzzer provide
real-time feedback to the user.

## 🎥 Demo Video
👉 [Watch the demo here](https://youtube.com/shorts/KoMVbbF8hj8?si=M4SuPaJqtg2puyBv)

## 📸 Prototype
[Stopwatch Prototype](https://github.com/Angelo-arduino/Arduino-stopwatch/blob/main/IMG_3549%5B1%5D.jpeg)

## 🚀 Future Improvements
- Lap time functionality
- Improved enclosure design
- Power optimization
- Button debounce optimization

## 📚 What I Learned
- Embedded system design
- Event-driven programming
- Hardware–software integration
- User interface design for microcontrollers
