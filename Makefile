main : main.cpp Aquarium.o Bestiole.o  BestiolePeureuse.o BestioleGregaire.o BestioleFactory.o Milieu.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o BestiolePeureuse.o BestioleGregaire.o BestioleFactory.o Milieu.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

BestiolePeureuse.o : BestiolePeureuse.h BestiolePeureuse.cpp
	g++ -Wall -std=c++11  -c BestiolePeureuse.cpp -I .

BestioleGregaire.o : BestioleGregaire.h BestioleGregaire.cpp
	g++ -Wall -std=c++11  -c BestioleGregaire.cpp -I .

BestioleFactory.o : BestioleFactory.h BestiolePeureuse.h BestioleFactory.cpp
	g++ -Wall -std=c++11  -c BestioleFactory.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

clean:
	rm -rf *.o main test

