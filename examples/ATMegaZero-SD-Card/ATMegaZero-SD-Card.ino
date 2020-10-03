/*
 * ATMegaZero SD card read/write
 *
 * This example shows how to read and write data to and from an SD card file
 * inserted into the ATMegaZero.
 *
 * For full documentation please visit https://atmegazero.com
*/

#include <SPI.h>
#include <SD.h>

#define SPI_CS1 11 //The SD Card SPI-CS pin is internally wired to pin D11 (SPI-CS0) on the ATMegaZero

File myFile;

void writeToSDCard() {
  Serial.print("Initializing SD card...");

  if (!SD.begin(SPI_CS1)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("This text was written from the ATMegaZero board!");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void readFromSDCard() {
  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Write some text to the SD Card
  writeToSDCard();

  // Read the text we wrote from the SD Card
  readFromSDCard();
}

void loop() {

}
