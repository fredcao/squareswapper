CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = squareswapper
OBJECTS = main.o board.o boardinterpreter.o boardl0.o boardl1.o boardl2.o square.o basicsquare.o lateralsquare.o uprightsquare.o unstablesquare.o psychedelicsquare.o textdisplay.o window.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
