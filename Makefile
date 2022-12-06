CXX = g++
CXXFLAGS = -std=c++14 -Werror=vla
EXEC = biquadris
OBJECTS = main.o abstractboard.o decorator.o heavy.o blind.o board.o abstractblock.o tblock.o lblock.o jblock.o sblock.o zblock.o iblock.o oblock.o blockpart.o square.o abstractlevel.o levelzero.o levelone.o leveltwo.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean