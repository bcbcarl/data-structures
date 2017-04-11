RM := rm -rf
CXXFLAGS += -std=c++11

TEST = $(CURDIR)/test

.PHONY: all
all: test

.PHONY: test
test: list.cc list.test.cc
	@$(CXX) $(CXXFLAGS) -o $(TEST) $^
	@$(TEST)

.PHONY: clean
clean:
	@$(RM) $(TEST)
