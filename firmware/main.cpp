#include "Particle.h"
#include "MCP3008.h"


#define CS_PIN GPIO8
#define CLOCK_PIN GPIO11
#define MOSI_PIN GPIO10
#define MISO_PIN GPIO9

int led = D0;
int power = A5;
int analogvalue = 0;

// put pins inside MCP3008 constructor
MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN);


int ledToggle(String command) {

    if (command=="on") {
        digitalWrite(led,HIGH);
        return 1;
    }
    else if (command=="off") {
        digitalWrite(led,LOW);
        return 0;
    }
    else {
        return -1;
    }

}

void setup()
{
  pinMode(led,OUTPUT);
  pinMode(power,OUTPUT);

  digitalWrite(power, HIGH);

  Particle.variable("analogvalue", analogvalue);

  Particle.function("led",ledToggle);
}

void loop()
{
   analogvalue = adc.readADC(0); // Read from CH0, and update Particle variable
   delay(100);
}
