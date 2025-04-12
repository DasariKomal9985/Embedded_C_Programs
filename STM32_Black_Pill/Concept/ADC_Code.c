⚙️ ADC1 Configuration Changes:

Here I have Only One ADC, so I am using Multiple Channels Like:
📌 IN0 and IN1

🔄 ADC_Common_Settings:
🔹 Mode Independent : mode Default 🛠️ : for single ADC



🔧 ADC_Settings:
🔹 Clock Prescaler ⏳: PCLK2 divided by 2
🔹 Resolution 🎯 : 12 bits
🔹 Data Alignment ➡️ : Right alignment
🔹 Standard Scan Conversion Mode 🔄: Enabled
🔹 Continuous Conversion Mode 🔄: Enabled
🔹 Discontinuous Conversion Mode ❌: Disabled
🔹 DMA Continuous Requests 🚫: Disabled
🔹 End Of Conversion Selection ✅: End of single conversion, Clear status



📊 ADC_Regular_Conversionmode:
🔹 Number of Conversions 🔢 : Set to 2 (Cause I am using 2 channels)
🔹 External Trigger Conversion 🔄 = Software Start
🔹 External Trigger Conversion Edge 🔀 = None
📌 Rank 1 Settings:
🔹 Channel: 0
🔹 Sampling Time: ⏳ 480 (for better accuracy)
📌 Rank 2 Settings:
🔹 Channel: 1
🔹 Sampling Time: ⏳ 480 (for better accuracy)




🚫 ADC Injected Conversion Mode: Disabled
❓ Why? : Injected conversions are for high-priority interrupts (like emergency readings) 🚨
🚨 Analog Watchdog Settings: Disabled
❓ Why? : Watchdog is for monitoring if values go above/below set limits 📏



🎛️ For GPIO PB1 : Button State
🔹 Go to GPIO settings
🔹 Use Pull-up or Pull-down ⬆️⬇️ based on your application