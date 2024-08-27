// #include <gtest/gtest.h>
// #include "typewise-alert.h"

// TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {


// }
// #include <gtest/gtest.h>
// #include "typewise-alert.h"

// TEST(TypeWiseAlertTestSuite, InfersBreachAccordingToLimits) {
//     // Test cases for inferBreach
//     EXPECT_EQ(inferBreach(25, 20, 30), NORMAL);
//     EXPECT_EQ(inferBreach(15, 20, 30), TOO_LOW);
//     EXPECT_EQ(inferBreach(35, 20, 30), TOO_HIGH);
// }

// TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreach) {
//     // Test cases for classifyTemperatureBreach
//     EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 10), NORMAL);
//     EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 36), TOO_HIGH);
//     EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50), TOO_HIGH);
//     EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 39), TOO_HIGH);
//     EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 25), NORMAL);
// }

// TEST(TypeWiseAlertTestSuite, CheckAndAlert) {
//     // Test cases for checkAndAlert
//     testing::internal::CaptureStdout();
//     BatteryCharacter battery = {PASSIVE_COOLING, "BrandX"};
//     checkAndAlert(TO_CONTROLLER, battery, 30);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_NE(output.find("feed"), std::string::npos);  // Check if header is printed

//     testing::internal::CaptureStdout();
//     checkAndAlert(TO_EMAIL, battery, 36);
//     output = testing::internal::GetCapturedStdout();
//     EXPECT_NE(output.find("Hi, the temperature is too high"), std::string::npos);  // Check alert message
// }
// #include <gtest/gtest.h>
// #include "typewise-alert.h"

// // Test inferBreach function
// TEST(TypeWiseAlertTestSuite, InfersBreachTooLow) {
//     EXPECT_EQ(inferBreach(-1, 0, 35), TOO_LOW);
// }

// TEST(TypeWiseAlertTestSuite, InfersBreachNormal) {
//     EXPECT_EQ(inferBreach(20, 0, 35), NORMAL);
// }

// TEST(TypeWiseAlertTestSuite, InfersBreachTooHigh) {
//     EXPECT_EQ(inferBreach(36, 0, 35), TOO_HIGH);
// }

// // Test classifyTemperatureBreach function
// TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreachPassiveCoolingTooLow) {
//     EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, -1), TOO_LOW);
// }

// TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreachPassiveCoolingNormal) {
//     EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 20), NORMAL);
// }

// TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreachPassiveCoolingTooHigh) {
//     EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 36), TOO_HIGH);
// }

// TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreachHiActiveCoolingTooLow) {
//     EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, -1), TOO_LOW);
// }

// TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreachHiActiveCoolingNormal) {
//     EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 40), NORMAL);
// }

// TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreachHiActiveCoolingTooHigh) {
//     EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 46), TOO_HIGH);
// }

// TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreachMedActiveCoolingTooLow) {
//     EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, -1), TOO_LOW);
// }

// TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreachMedActiveCoolingNormal) {
//     EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 39), NORMAL);
// }

// TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreachMedActiveCoolingTooHigh) {
//     EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 41), TOO_HIGH);
// }

// // Test sendToEmail function
// TEST(TypeWiseAlertTestSuite, SendsTooLowEmail) {
//     testing::internal::CaptureStdout();
//     sendToEmail(TOO_LOW);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "To: a.b@c.com\nHi, the temperature is too low\n");
// }

// TEST(TypeWiseAlertTestSuite, SendsTooHighEmail) {
//     testing::internal::CaptureStdout();
//     sendToEmail(TOO_HIGH);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "To: a.b@c.com\nHi, the temperature is too high\n");
// }

// TEST(TypeWiseAlertTestSuite, NoEmailForNormalBreachType) {
//     testing::internal::CaptureStdout();
//     sendToEmail(NORMAL);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "");
// }

// // Test sendToController function
// TEST(TypeWiseAlertTestSuite, SendsToControllerTooLow) {
//     testing::internal::CaptureStdout();
//     sendToController(TOO_LOW);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "feed : 1\n");  // 1 corresponds to TOO_LOW
// }

// TEST(TypeWiseAlertTestSuite, SendsToControllerTooHigh) {
//     testing::internal::CaptureStdout();
//     sendToController(TOO_HIGH);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "feed : 2\n");  // 2 corresponds to TOO_HIGH
// }

// TEST(TypeWiseAlertTestSuite, SendsToControllerNormal) {
//     testing::internal::CaptureStdout();
//     sendToController(NORMAL);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "feed : 0\n");  // 0 corresponds to NORMAL
// }

// // Test checkAndAlert function
// TEST(TypeWiseAlertTestSuite, CheckAndAlertToControllerTooLow) {
//     BatteryCharacter batteryChar = {PASSIVE_COOLING, "BrandX"};
//     testing::internal::CaptureStdout();
//     checkAndAlert(TO_CONTROLLER, batteryChar, -1);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "feed : 1\n");
// }

// TEST(TypeWiseAlertTestSuite, CheckAndAlertToControllerTooHigh) {
//     BatteryCharacter batteryChar = {HI_ACTIVE_COOLING, "BrandX"};
//     testing::internal::CaptureStdout();
//     checkAndAlert(TO_CONTROLLER, batteryChar, 50);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "feed : 2\n");
// }

// TEST(TypeWiseAlertTestSuite, CheckAndAlertToControllerNormal) {
//     BatteryCharacter batteryChar = {MED_ACTIVE_COOLING, "BrandX"};
//     testing::internal::CaptureStdout();
//     checkAndAlert(TO_CONTROLLER, batteryChar, 20);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "feed : 0\n");
// }

// TEST(TypeWiseAlertTestSuite, CheckAndAlertToEmailTooLow) {
//     BatteryCharacter batteryChar = {PASSIVE_COOLING, "BrandX"};
//     testing::internal::CaptureStdout();
//     checkAndAlert(TO_EMAIL, batteryChar, -1);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "To: a.b@c.com\nHi, the temperature is too low\n");
// }

// TEST(TypeWiseAlertTestSuite, CheckAndAlertToEmailTooHigh) {
//     BatteryCharacter batteryChar = {HI_ACTIVE_COOLING, "BrandX"};
//     testing::internal::CaptureStdout();
//     checkAndAlert(TO_EMAIL, batteryChar, 50);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "To: a.b@c.com\nHi, the temperature is too high\n");
// }

// TEST(TypeWiseAlertTestSuite, CheckAndAlertToEmailNormal) {
//     BatteryCharacter batteryChar = {MED_ACTIVE_COOLING, "BrandX"};
//     testing::internal::CaptureStdout();
//     checkAndAlert(TO_EMAIL, batteryChar, 20);
//     std::string output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "");
// }
#include <gtest/gtest.h>
#include "typewise-alert.h"

// Test case: Breach detection when temperature is below the lower limit
TEST(TypeWiseAlertTestSuite, DetectsBreachWhenTemperatureBelowLowerLimit) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_CONTROLLER, batteryChar, -5.0); // Temperature below 0°C
}

// Test case: Breach detection when temperature is above the upper limit
TEST(TypeWiseAlertTestSuite, DetectsBreachWhenTemperatureAboveUpperLimit) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_CONTROLLER, batteryChar, 40.0); // Temperature above 35°C
}

// Test case: No breach when temperature is exactly at the lower limit
TEST(TypeWiseAlertTestSuite, NoBreachWhenTemperatureAtLowerLimit) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_CONTROLLER, batteryChar, 0.0); // Temperature exactly at 0°C
}

// Test case: No breach when temperature is exactly at the upper limit
TEST(TypeWiseAlertTestSuite, NoBreachWhenTemperatureAtUpperLimit) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_CONTROLLER, batteryChar, 35.0); // Temperature exactly at 35°C
}

// Test case: No breach when temperature is within normal limits
TEST(TypeWiseAlertTestSuite, NoBreachWhenTemperatureWithinLimits) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_CONTROLLER, batteryChar, 25.0); // Temperature within 0°C to 35°C
}

// Test case: Breach detection when temperature is too low and sending an email
TEST(TypeWiseAlertTestSuite, DetectsTooLowTemperatureAndSendsEmail) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_EMAIL, batteryChar, -10.0); // Temperature below 0°C
}

// Test case: Breach detection when temperature is too high and sending an email
TEST(TypeWiseAlertTestSuite, DetectsTooHighTemperatureAndSendsEmail) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert(TO_EMAIL, batteryChar, 50.0); // Temperature above 35°C
}

// Test case: Handles invalid cooling type
TEST(TypeWiseAlertTestSuite, HandlesInvalidCoolingType) {
    BatteryCharacter batteryChar = { (CoolingType)100, "TestBrand" }; // Invalid CoolingType
    checkAndAlert(TO_CONTROLLER, batteryChar, 30.0); // Test with a temperature within valid range
}

// Test case: Handles invalid alert target
TEST(TypeWiseAlertTestSuite, HandlesInvalidAlertTarget) {
    BatteryCharacter batteryChar = { PASSIVE_COOLING, "TestBrand" };
    checkAndAlert((AlertTarget)100, batteryChar, 30.0); // Test with a temperature within valid range
}


