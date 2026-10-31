
# 🏭 Industrial Environmental Monitoring

### Real-Time Environmental Sensing · RTC · Threshold Alert · UART Telemetry

**An ARM7-based embedded monitoring system built around the NXP
LPC2148**



![Platform](https://img.shields.io/badge/MCU-NXP%20LPC2148-087E8B?style=for-the-badge)
![Core](https://img.shields.io/badge/Core-ARM7TDMI--S-244A7C?style=for-the-badge)
![Language](https://img.shields.io/badge/Language-Embedded%20C-00599C?style=for-the-badge)
![Interface](https://img.shields.io/badge/Display-16%C3%972%20LCD-5B8C3A?style=for-the-badge)
:::

------------------------------------------------------------------------

## 🧭 Project at a Glance

This project combines **ambient temperature measurement**, **real-time
clock information**, **local LCD presentation**, **threshold-based
alerting**, and **serial data transmission** in one embedded
application.

The firmware is written in Embedded C for the **LPC2148 ARM7 development
board**. The LM35 temperature sensor provides an analog signal to the
MCU's 10-bit ADC. The RTC supplies time and calendar fields. A 16×2 LCD
presents the live readings, while a keypad-based menu allows the user to
edit clock information and the temperature threshold. UART0 sends
monitoring information to a serial terminal.



## ✨ What the System Does

  -----------------------------------------------------------------------
  Function                            Implementation in the supplied
                                      firmware
  ----------------------------------- -----------------------------------
  🕒 Real-time clock                  Reads hour, minute and second from
                                      the LPC2148 RTC registers

  📅 Calendar display                 Reads date, month, year and
                                      day-of-week fields

  🌡️ Temperature monitoring           Reads the LM35 through ADC channel
                                      1 and converts the ADC voltage to
                                      °C

  🖥️ Local display                    Shows time, temperature, date and
                                      weekday on a 16×2 character LCD

  🚨 High-temperature alert           Compares the measured temperature
                                      with a configurable threshold and
                                      activates the buzzer alert path

  ⌨️ User configuration               Uses a 4×4 matrix keypad to enter
                                      the menu and edit RTC fields /
                                      temperature threshold

  🔌 Serial telemetry                 Sends RTC and temperature
                                      information through UART0 at the
                                      configured baud rate
  -----------------------------------------------------------------------

### Typical operating sequence

``` text
Power ON
   │
   ▼
Initialize GPIO, RTC, LCD, UART, ADC and keypad
   │
   ▼
Read LM35 temperature ───── Read RTC fields
   │                              │
   └──────────────┬───────────────┘
                  ▼
          Compare temperature
          with configured limit
             /          \
        Above limit    Normal range
            │               │
            ▼               ▼
      Alert display     Update LCD
      + buzzer path     with live data
            │               │
            └───────┬───────┘
                    ▼
          Send serial information
                    │
                    ▼
             Repeat continuously

User switch → configuration menu → keypad → edit RTC / threshold
```

------------------------------------------------------------------------

## 📸 Physical Hardware Setup

<img width="1448" height="1086" alt="board" src="https://github.com/user-attachments/assets/b4c8c49d-1c8a-4d13-b988-03c358f60a03" />

```
## 📸 Physical Hardware Setup

*Physical ARM7 development board with LCD, LM35, keypad and indicated wiring.*
```
Physical ARM7 development board labelled LPC2148. The
coloured lines in the supplied photograph illustrate the project's
intended peripheral connections; confirm each jumper against the board
header labels before powering the circuit.

----------------------------------------------------------------------
## 🧩 Hardware Platform & Components

The physical board in the photograph is labelled **LPC2148** and is an
ARM7 development board. The component list below distinguishes the
MCU/peripheral functions used by the firmware from external components
connected to the board.

  -----------------------------------------------------------------------
  Component / Module      Part / Interface        Role in this project
  ----------------------- ----------------------- -----------------------
  Microcontroller         NXP LPC2148, ARM7TDMI-S Main controller; GPIO,
                                                  ADC, RTC and UART
                                                  peripherals

  Development board       Vector India ARM7       Power, MCU headers and
                          board, Series 1.1 (as   onboard interfacing
                          labelled)               facilities

  LCD                     16×2 character LCD,     Displays time, date,
                          HD44780-compatible      weekday and temperature

  Temperature sensor      LM35                    Analog temperature
                                                  output, nominally 10
                                                  mV/°C

  Keypad                  4×4 matrix keypad       Menu navigation and
                                                  numeric entry

  Buzzer                  Board buzzer / external Audible
                          buzzer interface        high-temperature alert

  UART interface          UART0, TXD0/RXD0        Serial output to a PC
                                                  terminal

  Main clock              12 MHz crystal          Source used for the PLL
                          configured in project   clock calculation
                          macros                  

  RTC clock source        LPC2148 RTC clock       RTC timekeeping source;
                          circuitry               verify fitted crystal
                                                  and board routing

  LCD contrast            On-board potentiometer  Adjusts LCD contrast

  Power                   Board power input and   Supplies the
                          regulated rails         development board and
                                                  peripherals
  -----------------------------------------------------------------------

*The source files identify the LM35, LCD, keypad, buzzer, UART0 and RTC
interfaces. Exact external component ratings, resistor values and
regulator part numbers are not fully established by the supplied
firmware; they are therefore not guessed in this table.*

------------------------------------------------------------------------
### Circuit Block Diagram

<img width="1536" height="1024" alt="Industrial Environmental Monitoring System" src="https://github.com/user-attachments/assets/87cb4f7f-9a37-4b6e-a18d-6bf330ebb9e1" />

## 🔗 Firmware Pin Map

The following assignments are taken from the supplied project macros and
peripheral-driver code. Port numbers are MCU GPIO names, not physical
header pin numbers.

### 1. LCD --- 8-bit parallel interface

The LCD driver writes an 8-bit data byte to **P0.5--P0.12**. Control
signals are defined separately.

  LCD signal     LPC2148 GPIO Firmware definition / use
  ------------ -------------- -----------------------------------------------
  D0                     P0.5 Data bit 0
  D1                     P0.6 Data bit 1
  D2                     P0.7 Data bit 2
  D3                     P0.8 Data bit 3
  D4                     P0.9 Data bit 4
  D5                    P0.10 Data bit 5
  D6                    P0.11 Data bit 6
  D7                    P0.12 Data bit 7
  RS                    P0.13 Register select
  EN                    P0.14 Enable
  RW                    P0.15 Read/write; firmware drives it LOW for writes

**LCD power pins:** connect VSS to GND, VDD to the LCD supply, and V0 to
the contrast-potentiometer wiper. Backlight connections depend on the
LCD module fitted to the board.

### 2. 4×4 Matrix Keypad --- Port 1

  Keypad line     LPC2148 GPIO Firmware direction
  ------------- -------------- --------------------
  ROW0                   P1.16 Output
  ROW1                   P1.17 Output
  ROW2                   P1.18 Output
  ROW3                   P1.19 Output
  COL0                   P1.20 Input
  COL1                   P1.21 Input
  COL2                   P1.22 Input
  COL3                   P1.23 Input

The driver selects one row at a time and checks the column inputs. The
supplied keypad lookup table maps the keys as `1 2 3 A`, `4 5 6 B`,
`7 8 9 C`, and `* 0 # D`.

### 3. LM35 --- ADC input

  Sensor signal   LPC2148 pin / channel                     Firmware setting
  --------------- ----------------------------------------- -------------------
  VCC             Board supply appropriate for the sensor   Sensor power
  VOUT            P0.28 / AD0.1                             ADC channel `CH1`
  GND             GND                                       Common ground

The ADC driver configures P0.28 as AD0.1 and converts the 10-bit result
to a voltage using a 3.3 V reference assumption. The LM35 routine then
multiplies the voltage by 100 to obtain the temperature in °C.

### 4. UART0 --- Serial communication

  UART signal     LPC2148 pin Purpose
  ------------- ------------- --------------------------------------------
  TXD0                   P0.0 MCU transmit → USB-to-serial / terminal RX
  RXD0                   P0.1 MCU receive ← USB-to-serial / terminal TX
  GND                     GND Common reference

  UART setting                                  Configured value
  -------------- -----------------------------------------------
  Baud rate                                             9600 bps
  Data bits                                                    8
  Stop bits                                                    1
  Parity           Not enabled in the supplied LCR configuration

### 5. Buzzer and configuration switch

  ------------------------------------------------------------------------
  Function                               LPC2148 pin Firmware evidence
  --------------------- ---------------------------- ---------------------
  Buzzer control                               P0.18 `BUZZER` macro in
                                                     `defines1.h`

  Configuration switch                  P0.3 / EINT1 `EINT1_Init()`
  interrupt                                          selects EINT1 using
                                                     PINSEL0 bits 6--7
  ------------------------------------------------------------------------

The buzzer's active polarity depends on the actual board driver circuit.
Confirm the board's buzzer interface before assuming that a HIGH or LOW
level means ON.

------------------------------------------------------------------------

## 🧠 Firmware Architecture

The application is divided into peripheral drivers, configuration
headers and application-level logic. The design uses direct LPC21xx
register access rather than an operating system.

  -----------------------------------------------------------------------
  Layer                   Module(s)               Responsibility
  ----------------------- ----------------------- -----------------------
  Application             `main.c`,               Startup, main loop,
                          `main_definition1.c`,   menus, threshold
                          `main1.h`               handling and alert flow

  LCD driver              `lcd1.c`, `lcd1.h`,     LCD initialization,
                          `lcd_defines1.h`        commands, characters,
                                                  strings and numeric
                                                  display

  Keypad driver           `KeyPd.c`, `KeyPd.h`,   Matrix scanning and key
                          `KeyPd_Defines.h`       lookup

  ADC driver              `adc1.c`, `adc1.h`,     ADC channel
                          `adc_defines1.h`        configuration and
                                                  conversion

  Sensor interface        `lm35_1.c`, `lm35_1.h`  Converts ADC voltage to
                                                  temperature

  RTC driver              `rtc1.c`, `rtc1.h`,     Reads, sets and
                          `rtc_defines1.h`        displays RTC
                                                  time/date/day

  UART driver             `uart1.c`, `uart1.h`,   UART0 initialization
                          `uart_defines1.h`       and serial transmission

  GPIO / pin utility      `Pin_connect.c`,        Pin-function helper and
                          `Pin_connect.h`,        bit manipulation macros
                          `defines1.h`            

  Timing / types          `delay1.c`, `delay1.h`, Software delays and
                          `types1.h`              project-wide type
                                                  aliases
  -----------------------------------------------------------------------

### Module interaction

``` text
                    ┌─────────────────────┐
                    │      main.c         │
                    │  Application loop   │
                    └──────────┬──────────┘
                               │
          ┌────────────────────┼─────────────────────┐
          │                    │                     │
          ▼                    ▼                     ▼
    ┌───────────┐        ┌───────────┐         ┌───────────┐
    │   RTC     │        │   ADC +   │         │   Keypad  │
    │  Driver   │        │   LM35    │         │  Driver   │
    └─────┬─────┘        └─────┬─────┘         └─────┬─────┘
          │                    │                     │
          └────────────────────┼─────────────────────┘
                               │
                    ┌──────────┴──────────┐
                    ▼                     ▼
              ┌───────────┐         ┌───────────┐
              │    LCD    │         │   UART0   │
              │  Display  │         │ Telemetry │
              └───────────┘         └───────────┘
                               │
                               ▼
                         ┌───────────┐
                         │  Buzzer   │
                         │  Alert    │
                         └───────────┘
```

------------------------------------------------------------------------

## 🖥️ LCD Presentation

The normal monitoring screen is arranged to show the main measurements
together:

  LCD row   Display content
  --------- ---------------------------------------
  Row 1     `HH:MM:SS` and temperature in °C
  Row 2     `DD/MM/YYYY` and weekday abbreviation

The firmware also contains separate LCD messages for the main
configuration menu, RTC editing and high-temperature alert.

------------------------------------------------------------------------

## ⌨️ User Configuration

The supplied application provides a switch-triggered configuration path
and keypad-based editing.

  Menu selection   Action
  ---------------- -------------------------------
  `1`              Enter RTC information editing
  `2`              Edit temperature threshold
  `3`              Exit the main menu

The RTC edit menu supports hour, minute, second, date, month, year and
weekday selection. Numeric entry uses the keypad's `#` key to confirm
and `*` to clear/backspace.

------------------------------------------------------------------------

## 📡 Serial Output

UART0 is configured for **9600 baud, 8 data bits, 1 stop bit**. The
firmware includes routines to transmit RTC date/time fields, temperature
values and an over-temperature alert message.

The normal UART reporting routine is conditioned on the RTC seconds
field reaching `59`, with a delay before transmission. This is a serial
reporting mechanism; the supplied source set does **not** show an
SD-card, EEPROM or filesystem-based persistent log store.

------------------------------------------------------------------------

## 🛠️ Development Environment

  Item                      Project information
  ------------------------- -------------------------------------------
  MCU family                NXP LPC2148 / LPC21xx register model
  Programming language      Embedded C
  IDE / project format      Keil µVision project (`.uvproj`)
  Target device             NXP LPC2148 (ARM7TDMI)
  Latest linked image       `Industrial_Environmental_Monitoring.axf`
  Peripheral access         Direct register-level programming
  Display                   HD44780-compatible 16×2 LCD
  Temperature acquisition   On-chip 10-bit ADC + LM35
  Serial terminal           UART0, 9600 baud

### Latest Keil build configuration

  -------------------------------------------------------------------------------
  Setting                             Latest verified information
  ----------------------------------- -------------------------------------------
  Target device                       **NXP LPC2148**

  CPU architecture                    ARM7TDMI

  Crystal frequency entered in        12 MHz
  µVision                             

  Output filename                     `Industrial_Environmental_Monitoring.axf`

  Linker memory region                IROM1: `0x00000000`, size `0x00080000` (512
                                      KB)

  Linker RAM region                   IRAM1: `0x40000000`, size `0x00008000` (32
                                      KB)

  Code + read-only data               Approximately 10.70 KB

  Read/write + zero-initialized data  Approximately 1.35 KB
  -------------------------------------------------------------------------------

> **File naming note:** `.axf` is the ARM executable image produced by
> the Keil ARM toolchain. It is not a Windows `.exe` program. The
> `.map`, `.htm`, `.sct` and `.lnp` files are build/linker reports and
> configuration inputs; they are useful for debugging but are not
> normally required as source files in the GitHub repository.



### Output Results 
Disclaimer: The LCD screens and UART records below are illustrative mockups based on the uploaded firmware's LCD strings and UART output format. They are not actual photographs or measurements from the LPC2148 board.

## LCD output states

<img width="1200" height="2080" alt="LCD_Output_Mockups_Overview (1)" src="https://github.com/user-attachments/assets/8f944c76-c622-4398-85f0-1f59fb99e995" />

The mockups cover the normal monitoring display, main menu, RTC menu, time/date entry prompts, weekday selection, invalid input feedback, day/time save messages, threshold configuration and over-temperature alert.

## UART0 serial output

Normal monitoring records
(Info_On_UART() sends when SEC == 59; values below are illustrative):
07/05/2026    03:21:59     32.45°C
07/05/2026    03:22:59     32.60°C
07/05/2026    03:23:59     34.10°C

Over-temperature records
(ALERT_Info_On_UART() is called when tt > TT; values are illustrative):
Temp: 36.20°C @07/05/2026    03:24:05 -OVER TEMP!
Temp: 37.05°C @07/05/2026    03:24:06 -OVER TEMP!
Temp: 36.70°C @07/05/2026    03:24:07 -OVER TEMP!

Configuration events (message text from the firmware):
 ***Main Menu Mode Activated***
 ***Time Editing Mode Activated***
 ***Exit From Time Editing Mode***
 ***Threshold Temp Editing Mode Activated***
 ***Exit From Threshold Temp Editing Mode***
 ***Exit From Editing Mode***

 <img width="1536" height="1024" alt="ChatGPT Image Oct 31, 2026, 08_57_49 AM" src="https://github.com/user-attachments/assets/a5638d27-aa6d-40a9-af28-82a1de46fbf7" />


### Build and hardware bring-up checklist

1.  Open the Keil project in µVision.
2.  Select the exact MCU fitted to the physical board and verify the
    matching device header.
3.  Confirm the startup assembly, linker memory map, compiler settings
    and all source-file paths.
4.  Build the project and resolve compiler/linker errors.
5.  Program the LPC2148 using the board's supported ISP/debug method.
6.  Verify the LCD first, then keypad scanning, ADC/LM35 readings, RTC
    progression, UART output and buzzer alert individually.
7.  Test the threshold alert with a safe, controlled temperature input
    and confirm the buzzer driver polarity.

------------------------------------------------------------------------

## ⚠️ Source Review & Verification Notes

These notes are included to make the README technically honest and to
identify items that should be checked before treating the project as
production-ready.

-   **Physical MCU identification:** the supplied board photograph is
    visibly labelled `LPC2148`; this README therefore describes the
    physical hardware as an LPC2148 ARM7 board.
-   **Keil target mismatch:** the supplied `.uvproj` file currently
    names `LPC2138` as its target device. Change and verify the target
    to match the actual LPC2148 hardware before relying on the project
    configuration.
-   **RTC prescaler:** `PREINT` and `PREFRAC` assignments are commented
    out in the supplied `RTC_Init()` implementation, although the
    corresponding macros are defined. Verify RTC clock-source and
    prescaler configuration on the actual board.
-   **RTC startup values:** the application writes initial time/date
    values during startup. As currently structured, this can reset the
    clock/calendar on every power-up; set the desired initialisation
    policy for the final application.
-   **ADC reference:** the LM35 conversion uses a 3.3 V ADC reference
    calculation. Confirm the actual ADC reference voltage and sensor
    supply on the board.
-   **Temperature threshold:** the threshold is stored in a global
    variable and edited through the keypad. Confirm the default value
    and permitted range in the exact source version being built.
-   **Serial logging:** the current implementation transmits data over
    UART. It does not, by itself, demonstrate persistent storage or a
    complete industrial CAN data logger.
-   **Hardware wiring:** the pin map above is derived from the source
    macros and drivers. The photograph is a connection illustration;
    verify each board header pin and electrical level before applying
    power.

------------------------------------------------------------------------

## 📁 Repository Layout

The source files are grouped by role so that implementation files,
interfaces and configuration definitions are easy to locate.

``` text
Industrial-Environmental-Monitoring/
│
├── README.md
├── ANNOTATION_NOTES.md
│
├── src/
│   ├── application/
│   │   ├── main.c
│   │   ├── main_definition1.c
│   │   └── main1.h
│   │
│   ├── drivers/
│   │   ├── adc1.c
│   │   ├── lcd1.c
│   │   ├── KeyPd.c
│   │   ├── rtc1.c
│   │   ├── uart1.c
│   │   ├── lm35_1.c
│   │   ├── Pin_connect.c
│   │   └── delay1.c
│   │
│   ├── headers/
│   │   ├── adc1.h
│   │   ├── lcd1.h
│   │   ├── KeyPd.h
│   │   ├── rtc1.h
│   │   ├── uart1.h
│   │   ├── lm35_1.h
│   │   ├── Pin_connect.h
│   │   └── delay1.h
│   │
│   ├── defines/
│   │   ├── adc_defines1.h
│   │   ├── lcd_defines1.h
│   │   ├── KeyPd_Defines.h
│   │   ├── rtc_defines1.h
│   │   ├── uart_defines1.h
│   │   └── defines1.h
│   │
│   └── common/
│       └── types1.h
│
├── hardware/
│   └── board-connection-diagram/
│       └── lpc2148_hardware_board.jpg
│
├── docs/
│   └── project-description.pdf
│
└── Industrial_Environmental_Monitoring.uvproj
```

*This is the recommended logical layout for the repository. Update the
Keil project file's source/include paths if you physically move the
files into these folders.*

------------------------------------------------------------------------

## 🎓 Engineering Concepts Demonstrated

-   ARM7 LPC2148 peripheral interfacing
-   GPIO direction and pin-function configuration
-   8-bit LCD interfacing
-   Matrix keypad scanning
-   ADC conversion and analog sensor interfacing
-   RTC register access and calendar handling
-   UART serial communication
-   External interrupt handling
-   Embedded C modular driver design
-   Threshold-based monitoring and alert generation
-   Hardware bring-up and peripheral-level debugging

------------------------------------------------------------------------

## 🚀 Project Status

The supplied firmware contains the core monitoring, display, keypad
configuration, RTC, UART and threshold-alert modules. The latest
uploaded build artifacts include
`Industrial_Environmental_Monitoring.axf`, its linker map (`.map`), call
graph (`.htm`), scatter-loading file (`.sct`) and linker command file
(`.lnp`). Their presence confirms that Keil produced and linked the ARM7
image. The linker map reports approximately 10.70 KB of code/read-only
data and 1.35 KB of read/write plus zero-initialized data. This confirms
the build output, but does not by itself prove that every peripheral has
been validated on the physical board.

------------------------------------------------------------------------


**Built as an Embedded Systems / ARM7 hardware--software integration
project.**

`LPC2148` · `Embedded C` · `LM35` · `RTC` · `ADC` · `LCD` · `UART0`
:::
