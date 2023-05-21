# the compiler: gcc for C program, define as g++ for C++
	CC = g++
 
	# compiler flags:
	#  -g     - this flag adds debugging information to the executable file
	#  -Wall  - this flag is used to turn on most compiler warnings
	CFLAGS  = -g -Wall
 
	# The build target 
	TARGET = crawler  

	# The function containers
	OBJECTS = Player.cpp Monster.cpp Archer.cpp Barbarian.cpp Wizard.cpp Boss.cpp Goblin.cpp Skeleton.cpp Slime.cpp Wyvern.cpp
	
compile:
	$(CC) $(CFLAGS) -o $(TARGET)  $(OBJECTS) crawler.cpp 
 
clean:
	$(RM) $(TARGET)