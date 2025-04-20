Working on STM32 Black pill::

Configuring ADC for Joystick (X & Y Axis) and Push Button in STM32 Black Pill (STM32F401CCU6) using STM32CubeIDE:::::


1️⃣ Open STM32CubeIDE and Create a New Project 🖥️
Open STM32CubeIDE 📂
Click on File 📝 → New → STM32 Project
Select your microcontroller: STM32F401CCU6 (Black Pill) ⚡
Click Next ➡️ and give your project a name 🏷️
Click Finish ✅


2️⃣ Configure the GPIO Pins for the Joystick and Button 🎛️
🟢 Set PA0 (X-axis) & PA1 (Y-axis) as Analog Inputs
Open the Pinout & Configuration tab 📌
Click on PA0 🔘 and select ADC1_IN0 🎚️ (This is for the X-axis)
Click on PA1 🔘 and select ADC1_IN1 🎛️ (This is for the Y-axis)
These two pins will now act as Analog Inputs to read joystick movements! 🎮

📌 Why Not Use a Digital Pin?
A digital pin can only read 0V (LOW) or 3.3V (HIGH), meaning it can't capture the smooth position changes of the joystick. If we use an analog pin, the ADC can provide a range of values (0-4095) instead of just 0 or 1, giving us much more precise joystick movement detection.


🔴 Enable ADC1 (Analog to Digital Converter)
In the Peripherals section, find ADC1 🧩
Click on ADC1 and enable it ✅
Under the Parameter Settings tab:
Set Scan Conversion Mode: Enabled 🔄 (Since we are reading multiple channels - X & Y)
Set Continuous Conversion Mode: Enabled 🔁 (So that ADC keeps running without restarting)
Keep Resolution: 12-bit 🏆 (0-4095 values, best precision)
Select Data Alignment: Right 📊


🔢 Why Should I Choose 12-bit Resolution for ADC?
STM32's ADC can have different resolutions:
6-bit: 0 - 63 (very low precision)
8-bit: 0 - 255 (like an old game console 🎮)
10-bit: 0 - 1023 (okay for many applications)
12-bit: 0 - 4095 (most accurate and commonly used)
A 12-bit ADC provides 4096 discrete levels, meaning:
Higher resolution = More precise joystick readings ✅
You get values from 0 (0V) to 4095 (3.3V) instead of just 0 and 1 (digital).
This is useful for smooth joystick control, like controlling a robotic arm 🤖 or a drone 🚁.


🔄 Why Enable Continuous Conversion Mode?
🔁 Understanding ADC Modes
Single Conversion Mode
The ADC reads one value and stops.
You need to manually trigger another reading every time.
❌ Not ideal for continuous joystick tracking.
Continuous Conversion Mode (Recommended)
The ADC keeps sampling the joystick's voltage continuously.
The latest values are always available, so we don't need to keep triggering the ADC manually.
✅ Best for real-time applications (like gaming or motor control).


🔢 Why Enable Scan Conversion Mode?
Scan Mode is required when reading multiple ADC channels (X & Y axes) at once. Without scan mode:
You'd have to manually switch between PA0 (X-axis) and PA1 (Y-axis) every time, which is inefficient.
With Scan Mode Enabled, STM32 automatically reads both values one after another without stopping.


🟡 Configure PB5 as a Digital Input for the Joystick Button
Click on PB5 🔘

The push button is active LOW:
Pressed = 0
Not Pressed = 1