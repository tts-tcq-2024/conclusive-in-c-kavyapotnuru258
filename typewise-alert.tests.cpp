// #include <gtest/gtest.h>
// #include "typewise-alert.h"

// TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {


// }
#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite, InfersBreachAccordingToLimits) {
    // Test cases for inferBreach
    EXPECT_EQ(inferBreach(25, 20, 30), NORMAL);
    EXPECT_EQ(inferBreach(15, 20, 30), TOO_LOW);
    EXPECT_EQ(inferBreach(35, 20, 30), TOO_HIGH);
}

TEST(TypeWiseAlertTestSuite, ClassifiesTemperatureBreach) {
    // Test cases for classifyTemperatureBreach
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 10), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 36), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 39), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 25), NORMAL);
}

TEST(TypeWiseAlertTestSuite, CheckAndAlert) {
    // Test cases for checkAndAlert
    testing::internal::CaptureStdout();
    BatteryCharacter battery = {PASSIVE_COOLING, "BrandX"};
    checkAndAlert(TO_CONTROLLER, battery, 30);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("feed"), std::string::npos);  // Check if header is printed

    testing::internal::CaptureStdout();
    checkAndAlert(TO_EMAIL, battery, 36);
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Hi, the temperature is too high"), std::string::npos);  // Check alert message
}
