
EXES = unit_test
CXXFLAGS = --std=c++11

%: %.cpp
	g++ $(CXXFLAGS) $^ -o  $@

all: $(EXES)


test:
	./$(EXES)

clean:
	rm -fv $(EXES)
