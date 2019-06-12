CXX = g++ #main compiler
CXXFLAGS = -std=c++0x -g #other compiler flags

OBJS =  inputValidation.o  displayMenu.o main.o Game.o MapObjects.o Space.o Player.o NPC.o Camp.o solidObjects.o Items.o Cabin.o Forest.o

SRCS =  inputValidation.cpp  displayMenu.cpp main.cpp Game.cpp MapObjects.cpp Space.cpp Player.cpp NPC.cpp Camp.cpp solidObjects.cpp Items.cpp Cabin.cpp Forest.cpp

HEADERS =  inputValidation.hpp displayMenu.hpp Game.hpp MapObjects.hpp Space.hpp Player.hpp NPC.hpp Camp.hpp solidObjects.hpp Items.hpp Cabin.hpp Forest.hpp

finalProject: ${OBJS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o finalProject

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c ${SRCS}
	#$(@: .o=.cpp)

clean: 
	rm *.o finalProject