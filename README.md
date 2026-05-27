# UoSM Robotics Club Quadruped Robot

This repository contains the code and CAD assets for a workshop quadruped robot.  
It includes:

- an Arduino sketch for servo control and movement commands
- the servo calibration values used by the sketch
- CAD / manufacturing files for the robot parts
- the workshop participant guide PDF

## Setup

### Hardware

- Arduino-compatible board
- PCA9685 / Adafruit PWM servo driver board
- 8 servos wired to channels 0–7
- HC-06 Bluetooth serial module
- Power supply suitable for the servos

### Software

1. Open `Quadruped_Workshop_code/Quadruped_Workshop_code.ino` in the Arduino IDE.
2. Install the `Adafruit PWM Servo Driver` library.
3. Make sure the robot is wired to match the channel names used in the sketch:
   - Front left: `FL1`, `FL2`
   - Front right: `FR1`, `FR2`
   - Back left: `BL1`, `BL2`
   - Back right: `BR1`, `BR2`
4. Upload the sketch to the board.
5. If needed, change the Bluetooth name and PIN in the sketch:
   - name: `QuadrupedPrototype`
   - PIN: `1111`

## Operating the robot

The robot listens for numeric commands over serial/Bluetooth. Send each command followed by a newline:

- `0` — rest position
- `1` — move forward
- `2` — move backward
- `3` — turn left
- `4` — turn right

The sketch sends `ok` after a command is processed. Start by sending `0` to bring the robot to its resting pose, then use the movement commands as needed.

## Notes

- Servo calibration values are stored in `Quadruped_Workshop_code/Quadruped_parameters.h`.
- The CAD files in `Parts CAD/` are included for building or modifying the robot body.
