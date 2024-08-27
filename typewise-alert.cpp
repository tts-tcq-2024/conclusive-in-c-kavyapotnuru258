#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if (value < lowerLimit) {
    return TOO_LOW;
  }
  if (value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  // Simplify with arrays for limits
  const double lowerLimits[] = {0, 0, 0};
  const double upperLimits[] = {35, 45, 40};
  
  return inferBreach(temperatureInC, lowerLimits[coolingType], upperLimits[coolingType]);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {
  
  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch (alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendTooLowEmail(const char* recipient) {
    printf("To: %s\n", recipient);
    printf("Hi, the temperature is too low\n");
}

void sendTooHighEmail(const char* recipient) {
    printf("To: %s\n", recipient);
    printf("Hi, the temperature is too high\n");
}

void sendToEmail(BreachType breachType) {
    const char* recipient = "a.b@c.com";
    
    // Array of function pointers
    void (*emailFunctions[])(const char*) = {nullptr, sendTooLowEmail, sendTooHighEmail};

    // Execute the corresponding function if it exists
    if (emailFunctions[breachType]) {
        emailFunctions[breachType](recipient);
    }
}





