CXX         = clang++ -std=c++17
WARN        = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings -Wno-parentheses -Wfloat-equal -pedantic
FLAGS       = -DDEBUG -g -O0
########
# DeSiGNAR path.
# Replace the value with your own.
DSG         =  /home/gerardorosetti/semestre_b2024/DeSiGNAR
########

# Demo
DEMO        = shortest_paths
INCLUDEPATH = -I$(DSG)/include
LIBLINK     = -L$(DSG)/lib -lDesignar -lpthread

all: $(DEMO)

$(DEMO): $(DEMO).cpp
	$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

# Ejecutar el programa
run: $(DEMO)
	./$(DEMO)

.PHONY: clean
clean:
	$(RM) $(DEMO) *.dot