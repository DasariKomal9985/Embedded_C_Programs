Polling vs Interrupts with USART Output: (🤖📘 STM32 Blackpill )

demonstrates the difference between polling and interrupt mechanisms on an STM32 microcontroller
The behavior of LEDs and messages on the serial monitor changes based on the state of a switch (connected to PB7).

📌 Hardware Overview
🟢 PB7 – Switch input
🔴 PB8 – Red LED (Polling mode indicator)
🟢 PB9 – Green LED (Interrupt mode indicator)
🖥️ USART1 – For displaying messages in Tera Term

⚙️ Working Principle:

🔁 Polling Mode (Switch OFF)

MCU continuously checks the switch state inside the while(1) loop.
If switch is OFF, it enters polling mode:
🔴 Red LED (PB8) turns ON
🟢 Green LED (PB9) turns OFF
It manually checks switch status.
Updates Tera Term: "Polling Mode Activated" 💬

⚡ Interrupt Mode (Switch ON)

If the switch is pressed, an interrupt is triggered (FALLING edge on PB7).
Now the system enters interrupt mode:
🟢 Green LED (PB9) turns ON
🔴 Red LED (PB8) turns OFF
CPU stops checking switch repeatedly, and instead reacts only when switch changes.
Updates Tera Term: "Interrupt Mode Activated" 💬

🧩 How Interrupt Works :
(🔍 Detailed Internal Working of Interrupt 🧠)

📦 1.) GPIO Configuration
✅ This configures:
GPIOB pin 7 as input with interrupt on falling edge
Uses internal pull-up so it's normally HIGH
Connected internally to EXTI Line 7

⚡ 2.) Signal Change on PB7 (Switch Press)
🖲️ When the switch is pressed:
Signal drops HIGH → LOW
⚠️ Triggers EXTI7 (falling edge)

🧩 3.) EXTI (External Interrupt/Event Controller)
🧩 What does EXTI do?
Every GPIO pin maps to an EXTI line (PB7 → EXTI7)
EXTI checks:
✅ Is this line enabled?
✅ Is the edge type (falling) correct?
If valid:
Sets pending bit
Sends a request ➡️ NVIC

🧠 4.) NVIC (Nested Vectored Interrupt Controller)
📨 NVIC receives the EXTI7 request:
Looks up EXTI9_5_IRQn (covers EXTI5–9)
Checks priority
⏫ If highest pending interrupt:
🧠 Saves current CPU state (context)
📍 Jumps to IRQ Handler

📈 5.) What Happens in ISR
Inside HAL_GPIO_EXTI_Callback:
✅ Check if GPIO_Pin == GPIO_PIN_7
🧹 Debounce logic (optional delay)
🔄 Update interrupt_mode variable
💡 Turn ON/OFF LEDs accordingly
🖥️ Send message over USART
🔚 After ISR:
NVIC restores CPU context
MCU resumes where it left off (loop continues)

📊 6.) Priority in NVIC Explained
HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
🧠 This sets:
Preemption Priority = 0 (highest)
Subpriority = 0
📝 If you set priority to (1, 0):
A higher-priority interrupt (like 0, 0) can preempt it

🖥️ 7.) USART1 – Why Use It?
🖥️ Tera Term displays real-time messages like:
"🔴 Polling Mode Activated"
"🟢 Interrupt Mode Activated"
✅ This gives live feedback without needing LEDs alone
📤 USART1 works via:
TX (Transmit) pin → PA9
RX (optional, here unused) → PA10

✅ GPIO configurations
✅ Interrupt vector tables
✅ Priority and preemption
✅ HAL architecture
✅ Context switching
✅ Event-driven vs time-driven design
✅ USART serial communication