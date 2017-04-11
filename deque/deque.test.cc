#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "deque.h"

SCENARIO("deque") {
  GIVEN("An empty deque") {
    carl::Deque<int> deque;

    REQUIRE(deque.empty());
    REQUIRE_EQ(deque.size(), 0);

    WHEN("pushing to the deque increases it's size") {
      deque.push_back(5);

      REQUIRE_FALSE(deque.empty());
      REQUIRE_EQ(deque.size(), 1);
      REQUIRE_EQ(deque.front(), 5);
      REQUIRE_EQ(deque.back(), 5);

      deque.push_back(3);

      REQUIRE_FALSE(deque.empty());
      REQUIRE_EQ(deque.size(), 2);
      REQUIRE_EQ(deque.front(), 5);
      REQUIRE_EQ(deque.back(), 3);

      deque.push_front(7);

      REQUIRE_FALSE(deque.empty());
      REQUIRE_EQ(deque.size(), 3);
      REQUIRE_EQ(deque.front(), 7);
      REQUIRE_EQ(deque.back(), 3);
    }

    WHEN("popping from the deque decreases it's size") {
      deque.push_back(5);
      deque.push_front(3);
      deque.push_back(7);

      REQUIRE_FALSE(deque.empty());
      REQUIRE_EQ(deque.size(), 3);
      REQUIRE_EQ(deque.front(), 3);
      REQUIRE_EQ(deque.back(), 7);

      deque.pop_front();

      REQUIRE_FALSE(deque.empty());
      REQUIRE_EQ(deque.size(), 2);
      REQUIRE_EQ(deque.front(), 5);
      REQUIRE_EQ(deque.back(), 7);

      deque.pop_back();

      REQUIRE_FALSE(deque.empty());
      REQUIRE_EQ(deque.size(), 1);
      REQUIRE_EQ(deque.front(), 5);
      REQUIRE_EQ(deque.back(), 5);
    }

    WHEN("popping the last element makes the deque empty") {
      deque.push_back(5);
      deque.pop_front();

      REQUIRE(deque.empty());
      REQUIRE_EQ(deque.size(), 0);

      deque.push_front(3);
      deque.pop_front();

      REQUIRE(deque.empty());
      REQUIRE_EQ(deque.size(), 0);
    }
  }
}
