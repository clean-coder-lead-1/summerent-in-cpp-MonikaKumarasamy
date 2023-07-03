#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}
TEST_CASE("infers the breach according to limits1") {
  REQUIRE(inferBreach(32, 20, 30) == TOO_HIGH);
}
TEST_CASE("infers the breach according to limits2") {
  REQUIRE(inferBreach(25, 20, 30) == NORMAL);
}
TEST_CASE("Return value depends on type of cooling") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 12) == inferBreach(12,0,35));
}
TEST_CASE("Return value depends on type of cooling1") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 12) == inferBreach(12,0,45));
}
TEST_CASE("Return value depends on type of cooling2") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 12) == inferBreach(12,0,40));
}
TEST_CASE("Prints message 1") {
  sendToController(TOO_LOW);
}
TEST_CASE("Print message 2") {
  sendToController(TOO_HIGH); 
}
TEST_CASE("Prints message 3") {
  sendToEmail(TOO_LOW);
}
TEST_CASE("Print message 4") {
  sendToEmail(TOO_HIGH);
}

TEST_CASE("Print message 5") {
  BatteryCharacter batterychr;
  checkAndAlert(TO_CONTROLLER,batterychr,12);
}
TEST_CASE("Print message 6") {
  BatteryCharacter batterychr;
  checkAndAlert(TO_EMAIL,batterychr,45);
}
