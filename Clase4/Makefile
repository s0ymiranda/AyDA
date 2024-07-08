CXX         = clang++ -std=c++17
WARN        = -Wall -Wextra -Wcast-align -Wno-sign-compare -Wno-write-strings -Wno-parentheses -Wfloat-equal -pedantic
FLAGS       = -DDEBUG -g -O0
########
# DeSiGNAR path.
# Replace the value with your own.
DSG         =  /home/miranda/AyDA-B2023/DeSiGNAR
########

# Demo
DEMO        = graphs
INCLUDEPATH = -I$(DSG)/include
LIBLINK     = -L$(DSG)/lib -lDesignar -lpthread

$(DEMO): $(DEMO).cpp
	$(CXX) $(FLAGS) $(INCLUDEPATH) $< -o $@ $(LIBLINK)

.PHONY: clean
clean:
	$(RM) $(DEMO)