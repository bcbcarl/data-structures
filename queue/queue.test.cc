#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "queue.h"

SCENARIO("queue") {
  GIVEN("An empty queue") {
    carl::Queue<int> queue;

    REQUIRE(queue.empty());
    REQUIRE_EQ(queue.size(), 0);

    WHEN("pushing to the queue increases it's size") {
      queue.push(5);

      REQUIRE_FALSE(queue.empty());
      REQUIRE_EQ(queue.size(), 1);
      REQUIRE_EQ(queue.front(), 5);

      queue.push(3);

      REQUIRE_FALSE(queue.empty());
      REQUIRE_EQ(queue.size(), 2);
      REQUIRE_EQ(queue.front(), 5);
    }

    WHEN("popping from the queue decreases it's size") {
      queue.push(5);
      queue.push(3);
      queue.pop();

      REQUIRE_FALSE(queue.empty());
      REQUIRE_EQ(queue.size(), 1);
      REQUIRE_EQ(queue.front(), 3);
    }

    WHEN("popping the last element makes the queue empty") {
      queue.push(5);
      queue.pop();

      REQUIRE(queue.empty());
      REQUIRE_EQ(queue.size(), 0);
    }
  }
}
