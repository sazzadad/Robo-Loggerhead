#NRF24L01 Module
The NFR24L01 is a transceiver module which means that it can both send and receive the data.

These modules are very cheap, smaller in size and has a lot of specifications. Some of the specifications of these modules are as follows

##Specifications of NRF24L01 Module
·         Power consumption is around 12mA during transmission which is even lesser than the led.
·         It can operate with baud rates from 250Kbps up to 2 Mbps.
·         Its range can reach up to 100 meters if used in open space and with antenna.
·         It can both send and receive the data simultaneously.
·         Each module can communicate with up to 6 other modules.
·         It uses the 2.4 GHz band.
·         It can send 1 to 25 bytes of raw data at the transmission rate of 1 MB.
·         It has 125 different channels.
#Pin out
The NRF24L01 module works with the Arduino through the SPI communication. The pinout of the module is as follows

NRF24L01 Pinout

The operating voltage of this module is from 1.9 to 3.6V but the other pins are 5V tolerant which means that the other pins can be directly connected to the Arduino.

The MOSI, MISO and the SCK are the SPI pins and these needs to be connected to the SPI pins of Arduino. Different Arduino’s have different SPI pins.

The CSN and CE are for setting the module in active mode and for switching between command and transmit mode. These can be connected to any digital pins of Arduino.

The IRQ pin is the interrupt pin and you don’t have to connect it.

Example 1 for Nrf24l01 Arduino Interfacing
In the first example for nrf24l01 arduino interfacing, we are going to simply send the data from one Arduino to other Arduino. When we will press the button connected to the first Arduino, LED connected to the second Arduino will light up.

The circuit diagram for the first example is shown below and the connections are shown below that.

nrf24l01 arduino

##For Transmitter
NRF24L01
Arduino UNO/Nano
Arduino Mega 2560
VCC	3.3V	3.3V
GND	GND	GND
CSN	Pin 10	Pin 10
CE	Pin 9	Pin 9
SCK	Pin 13	Pin 52
MOSI	Pin 11	Pin 51
MISO	Pin 12	Pin 50
Make the connections for the Button as shown in the Circuit Diagram
##For Receiver
NRF24L01
Arduino UNO/Nano
Arduino Mega 2560
VCC	3.3V	3.3V
GND	GND	GND
CSN	Pin 10	Pin 10
CE	Pin 9	Pin 9
SCK	Pin 13	Pin 52
MOSI	Pin 11	Pin 51
MISO	Pin 12	Pin 50
LED Positive	Pin 3	Pin 3
LED Negative	GND through 220 ohm resistor	GND through 220 ohm resistor
