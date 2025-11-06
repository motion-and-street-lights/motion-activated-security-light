# Motion Detection System Using Arduino and PIR Sensor

A simple and effective motion detection system built with Arduino Uno and a PIR (Passive Infrared) sensor. The system detects movement in its surroundings and activates an LED as a visual indicator, making it ideal for security, automation, and smart lighting applications.

## Abstract

This project demonstrates a basic motion detection system using an Arduino Uno and a Passive Infrared (PIR) sensor. The system detects motion in its surroundings and activates an LED when movement is detected. Such systems are commonly used in security, automation, and energy-efficient lighting applications.

## Introduction

In today's world, automation and security are of great importance. Motion detection systems play a vital role in these fields. The Arduino-based motion detection system utilizes a PIR sensor to detect infrared radiation emitted by moving bodies. When motion is detected, the Arduino turns on an LED as a visual indicator. This project serves as a foundation for more complex security and automation systems.

## Features

- Real-time motion detection using PIR sensor
- Visual indication through LED
- Serial monitor output for debugging
- Simple and cost-effective design
- Easy to expand and customize
- Low power consumption
- Suitable for educational and practical applications

## Components Required

- Arduino Uno Board (1x)
- PIR (Passive Infrared) Sensor (1x)
- LED (1x)
- 220Ω Resistor (1x)
- Jumper Wires
- Breadboard (1x)
- USB Cable for Programming (1x)

## Circuit Diagram

The circuit connections are straightforward:

*PIR Sensor Connections:*
- *VCC* → 5V on Arduino
- *GND* → GND on Arduino
- *OUT* → Digital Pin 3 on Arduino

*LED Connections:*
- *Anode (+)* → Digital Pin 13 on Arduino (through 220Ω resistor)
- *Cathode (-)* → GND on Arduino

## How It Works

The PIR sensor detects infrared radiation emitted by objects in motion. When a moving object such as a human passes in front of the sensor, the infrared radiation pattern changes, triggering the sensor's output. This signal is then read by the Arduino, which turns ON the LED to indicate motion.

*Operating Principle:*

1. The PIR sensor continuously monitors the infrared radiation in its detection range
2. When motion is detected, the sensor output goes HIGH
3. Arduino reads this HIGH signal and turns ON the LED
4. A message "Motion detected!" is printed to the Serial Monitor
5. When no motion is present, the sensor output goes LOW
6. Arduino turns OFF the LED and prints "No motion" to the Serial Monitor

## Installation

### Hardware Setup

1. Place the Arduino Uno and PIR sensor on the breadboard
2. Connect the PIR sensor to Arduino following the circuit diagram
3. Connect the LED with 220Ω resistor to pin 13
4. Verify all connections are secure
5. Connect Arduino to your computer via USB cable

### Software Setup

1. Install Arduino IDE from https://www.arduino.cc/en/software

2. Clone or download this repository

3. Open motion_detection.ino in Arduino IDE

4. Select your board: *Tools → Board → Arduino Uno*

5. Select your port: *Tools → Port → [Your Arduino Port]*

6. Click the Upload button

## Usage

1. After uploading the code, open Serial Monitor (Tools → Serial Monitor) at 9600 baud rate

2. The Serial Monitor will display real-time status:
   
   Motion detected!
   Motion detected!
   No motion
   No motion
   

3. Test the system:
   - Wave your hand in front of the PIR sensor
   - Observe the LED turning ON when motion is detected
   - Watch the LED turn OFF when motion stops

4. Allow 30-60 seconds for the PIR sensor to calibrate after powering on

## Code

```cpp
int pirPin = 3;   // PIR sensor output pin
int ledPin = 13;  // LED pin

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);
  
  if (motion == HIGH) {  // If motion detected
    digitalWrite(ledPin, HIGH);  // Turn LED ON
    Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW);   // Turn LED OFF
    Serial.println("No motion");
  }
  delay(500);
}
```

### Code Explanation

- *pirPin*: Digital pin 3 is used to read the PIR sensor output
- *ledPin*: Digital pin 13 is used to control the LED
- *setup()*: Configures pin modes and initializes serial communication at 9600 baud
- *loop()*: Continuously reads the PIR sensor state
  - If HIGH (motion detected): LED turns ON and prints "Motion detected!"
  - If LOW (no motion): LED turns OFF and prints "No motion"
- *delay(500)*: 500ms delay between readings to prevent excessive serial output

## Customization

### Change PIR Sensor Pin

```cpp
int pirPin = 2;  // Use digital pin 2 instead of pin 3
```

### Change LED Pin

```cpp
int ledPin = 8;  // Use digital pin 8 instead of pin 13
```

### Adjust Detection Delay

```cpp
delay(1000);  // Update every 1 second instead of 500ms
```

### Add Buzzer for Audio Alert

```cpp
int buzzerPin = 7;
pinMode(buzzerPin, OUTPUT);

if (motion == HIGH) {
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH);  // Turn buzzer ON
}
```

### Add Motion Counter

```cpp
int motionCount = 0;

if (motion == HIGH) {
  motionCount++;
  Serial.print("Motion detected! Count: ");
  Serial.println(motionCount);
}
```

## Applications

This motion detection system can be used for various applications:

- Home and office security systems
- Automatic lighting systems
- Motion-activated alarms
- Smart automation projects
- Presence detection for energy saving
- Visitor counters
- Wildlife monitoring
- Smart door bells

### Scaling for Real-World Use

For practical deployment, consider:

- Replace LED with a relay module to control AC bulbs or appliances
- Add a buzzer or alarm for audio alerts
- Integrate with wireless modules (Bluetooth/WiFi) for remote monitoring
- Add multiple PIR sensors for wider coverage
- Implement data logging to track motion events
- Connect to home automation systems

## Troubleshooting

*LED doesn't turn on when motion is detected*
- Check all wire connections, especially the PIR sensor output pin
- Verify the PIR sensor is powered (VCC to 5V, GND to GND)
- Allow 30-60 seconds for PIR sensor calibration
- Test the LED separately to ensure it's working

*LED stays on constantly*
- PIR sensor may need calibration time after power-on
- Adjust the sensitivity potentiometer on the PIR sensor (if available)
- Check for environmental factors causing false triggers (heat sources, moving objects)
- Verify the PIR sensor is not facing direct sunlight

*No Serial Monitor output*
- Verify baud rate is set to 9600
- Check USB connection
- Ensure the correct COM port is selected
- Try uploading the code again

*Inconsistent detection*
- PIR sensor detection range is typically 3-7 meters
- Ensure the sensor is positioned correctly
- Avoid placing the sensor near heat sources or air vents
- Check if the Fresnel lens on the PIR sensor is clean

*LED flickers*
- Add longer delay in the code (e.g., delay(1000))
- Check for loose connections
- Verify power supply is stable

## Contributing

Contributions are welcome. To contribute:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request with a clear description of improvements

### Ideas for Enhancement

- Add adjustable sensitivity controls
- Implement timer-based LED control
- Create a web interface for monitoring
- Add support for multiple sensors
- Integrate with notification systems

## License

This project is open source and available under the MIT License.
