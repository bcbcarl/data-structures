#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "stack.h"

SCENARIO("stack") {
  GIVEN("An empty stack") {
    carl::Stack<int> stack;

    REQUIRE(stack.empty());
    REQUIRE_EQ(stack.size(), 0);

    WHEN("pushing to the stack increases it's size") {
      stack.push(5);

      REQUIRE_FALSE(stack.empty());
      REQUIRE_EQ(stack.size(), 1);
      REQUIRE_EQ(stack.top(), 5);

      stack.push(3);

      REQUIRE_FALSE(stack.empty());
      REQUIRE_EQ(stack.size(), 2);
      REQUIRE_EQ(stack.top(), 3);
    }

    WHEN("popping from the stack decreases it's size") {
      stack.push(5);
      stack.push(3);
      stack.pop();

      REQUIRE_FALSE(stack.empty());
      REQUIRE_EQ(stack.size(), 1);
      REQUIRE_EQ(stack.top(), 5);
    }

    WHEN("popping the last element makes the stack empty") {
      stack.push(5);
      stack.pop();

      REQUIRE(stack.empty());
      REQUIRE_EQ(stack.size(), 0);
    }
  }
}
