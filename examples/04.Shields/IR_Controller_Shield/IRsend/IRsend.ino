/* IRremoteESP8266: IRsendDemo - demonstrates sending IR codes with IRsend.
 *
 * Version 1.0 April, 2017
 * Based on Ken Shirriff's IrsendDemo Version 0.1 July, 2009,
 * Copyright 2009 Ken Shirriff, http://arcfn.com
 *
 * An IR LED circuit *MUST* be connected to the ESP8266 on a pin
 * as specified by IR_LED below.
 *
 * TL;DR: The IR LED needs to be driven by a transistor for a good result.
 *
 * Suggested circuit:
 *     https://github.com/markszabo/IRremoteESP8266/wiki#ir-sending
 *
 * Common mistakes & tips:
 *   * Don't just connect the IR LED directly to the pin, it won't
 *     have enough current to drive the IR LED effectively.
 *   * Make sure you have the IR LED polarity correct.
 *     See: https://learn.sparkfun.com/tutorials/polarity/diode-and-led-polarity
 *   * Typical digital camera/phones can be used to see if the IR LED is flashed.
 *     Replace the IR LED with a normal LED if you don't have a digital camera
 *     when debugging.
 *   * Avoid using the following pins unless you really know what you are doing:
 *     * Pin 0/D3: Can interfere with the boot/program mode & support circuits.
 *     * Pin 1/TX/TXD0: Any serial transmissions from the ESP8266 will interfere.
 *     * Pin 3/RX/RXD0: Any serial transmissions to the ESP8266 will interfere.
 *   * ESP-01 modules are tricky. We suggest you use a module with more GPIOs
 *     for your first time. e.g. ESP-12 etc.
 */

#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>

#define IR_LED 0  

IRsend irsend(IR_LED);  // Set the GPIO to be used to sending the message.

// Example of data captured by IRrecvDumpV2.ino
uint16_t rawData[67] = {9038, 4434,  604, 516,  604, 514,  602, 1636,  602, 516,  
                        602, 516,  604, 514,  604, 516,  604, 514,  604, 1632,  
                        606, 1634,  604, 516,  604, 1634,  604, 1634,  604, 1634,  
                        604, 1634,   602, 1634,  606, 516,  602, 516,  602, 518,  
                        628, 1608,  604, 518,  602, 514,  604, 516,  604, 514,  
                        604, 1632,  606, 1632,  604, 1634,  604, 516,  604, 
                        1632,  604, 1634,  604, 1634,  606, 1632,  606};  // NEC  20DF10EF
void setup() {
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
}

void loop() {
//#if SEND_NEC
  Serial.println("NEC");
  irsend.sendNEC(0x0020DF10EF, 32);
//#endif  // SEND_NEC
  delay(1000);
//#if SEND_SONY
//  Serial.println("Sony");
//  irsend.sendSony(0xa90, 12, 2);
//#endif  // SEND_SONY
//  delay(2000);
//#if SEND_RAW
//  Serial.println("a rawData capture from IRrecvDumpV2");
//  irsend.sendRaw(rawData, 67, 38);  // Send a raw data capture at 38kHz.
//#endif  // SEND_RAW
//  delay(2000);
}
