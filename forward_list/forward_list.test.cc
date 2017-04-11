#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "forward_list.h"

SCENARIO("forward_list") {
  GIVEN("An empty forward list") {
    carl::ForwardList<int> forward_list;

    REQUIRE(forward_list.empty());

    WHEN("pushing to the forward list increases it's size") {
      forward_list.push_front(5);

      REQUIRE_FALSE(forward_list.empty());
      REQUIRE_EQ(forward_list.front(), 5);

      forward_list.push_front(3);

      REQUIRE_FALSE(forward_list.empty());
      REQUIRE_EQ(forward_list.front(), 3);
    }

    WHEN("popping from the forward list decreases it's size") {
      forward_list.push_front(5);
      forward_list.push_front(3);
      forward_list.pop_front();

      REQUIRE_FALSE(forward_list.empty());
      REQUIRE_EQ(forward_list.front(), 5);
    }

    WHEN("popping the last element makes the forward list empty") {
      forward_list.push_front(5);
      forward_list.pop_front();

      REQUIRE(forward_list.empty());
    }
  }
}
