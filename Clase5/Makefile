CXX         = clang++ -std=c++17
WARN        = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings -Wno-parentheses -Wfloat-equal -pedantic
FLAGS       = -DDEBUG -g -O0
########
# DeSiGNAR path.
# Replace the value with your own.
DSG         =  /home/miranda/AyDA-B2023/DeSiGNAR
########

# Demo
DEMO        = question1
DEMO2       = question2
DEMO3       = question3
INCLUDEPATH = -I$(DSG)/include
LIBLINK     = -L$(DSG)/lib -lDesignar -lpthread

all: $(DEMO) $(DEMO2) $(DEMO3)

$(DEMO): $(DEMO).cpp
	$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

$(DEMO2): $(DEMO2).cpp
	$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

$(DEMO3): $(DEMO3).cpp
	$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

# Ejecutar el programa
run1: $(DEMO)
	./$(DEMO)

run2: $(DEMO2)
	./$(DEMO2)

run3: $(DEMO3)
	./$(DEMO3)

.PHONY: clean
clean:
	$(RM) $(DEMO) $(DEMO2) $(DEMO3) *.dot