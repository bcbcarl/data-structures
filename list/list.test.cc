#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "list.h"

SCENARIO("list") {
  GIVEN("An empty list") {
    carl::List<int> list;

    REQUIRE(list.empty());
    REQUIRE_EQ(list.size(), 0);

    WHEN("pushing to the list increases it's size") {
      list.push_back(5);

      REQUIRE_FALSE(list.empty());
      REQUIRE_EQ(list.size(), 1);
      REQUIRE_EQ(list.front(), 5);
      REQUIRE_EQ(list.back(), 5);

      list.push_back(3);

      REQUIRE_FALSE(list.empty());
      REQUIRE_EQ(list.size(), 2);
      REQUIRE_EQ(list.front(), 5);
      REQUIRE_EQ(list.back(), 3);

      list.push_front(7);

      REQUIRE_FALSE(list.empty());
      REQUIRE_EQ(list.size(), 3);
      REQUIRE_EQ(list.front(), 7);
      REQUIRE_EQ(list.back(), 3);
    }

    WHEN("popping from the list decreases it's size") {
      list.push_back(5);
      list.push_front(3);
      list.push_back(7);

      REQUIRE_FALSE(list.empty());
      REQUIRE_EQ(list.size(), 3);
      REQUIRE_EQ(list.front(), 3);
      REQUIRE_EQ(list.back(), 7);

      list.pop_front();

      REQUIRE_FALSE(list.empty());
      REQUIRE_EQ(list.size(), 2);
      REQUIRE_EQ(list.front(), 5);
      REQUIRE_EQ(list.back(), 7);

      list.pop_back();

      REQUIRE_FALSE(list.empty());
      REQUIRE_EQ(list.size(), 1);
      REQUIRE_EQ(list.front(), 5);
      REQUIRE_EQ(list.back(), 5);
    }

    WHEN("popping the last element makes the list empty") {
      list.push_back(5);
      list.pop_front();

      REQUIRE(list.empty());
      REQUIRE_EQ(list.size(), 0);

      list.push_front(3);
      list.pop_back();

      REQUIRE(list.empty());
      REQUIRE_EQ(list.size(), 0);
    }
  }
}
