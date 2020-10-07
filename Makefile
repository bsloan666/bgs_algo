
EXES = bgs_heaptest

%: %.cpp
	g++ $^ -o  $@

all: $(EXES)


test:
	./$(EXES)

clean:
	rm -fv $(EXES)
