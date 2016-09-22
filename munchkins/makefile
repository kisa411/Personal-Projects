all: munchkin

munchkin: main.o munchkin.o player.o
	g++ main.o munchkin.o player.o -o munchkin

main.o: main.cpp
	g++ -c main.cpp

munchkin.o: munchkin.cpp
	g++ -c munchkin.cpp

player.o: player.cpp
	g++ -c player.cpp

clean:
	rm *o munchkin