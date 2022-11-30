main : main.cpp Aquarium.o Bestiole.o  BestiolePeureuse.o BestioleGregaire.o BestiolePrevoyante.o Milieu.o BestioleFactory.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o BestiolePeureuse.o BestioleGregaire.o BestiolePrevoyante.o Milieu.o BestioleFactory.o -I . -lX11 -lpthread

test : testBench.o Aquarium.o Bestiole.o BestiolePeureuse.o BestioleGregaire.o BestiolePrevoyante.o Milieu.o BestioleFactory.o
	g++ -Wall -std=c++11 -o test testBench.o Aquarium.o Bestiole.o BestiolePeureuse.o BestioleGregaire.o BestiolePrevoyante.o Milieu.o BestioleFactory.o -I . -lX11 -lpthread

testBench.o : BestioleFactory.h testBench.cpp
	g++ -Wall -std=c++11  -c testBench.cpp -I .

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

BestiolePeureuse.o : BestiolePeureuse.h BestiolePeureuse.cpp
	g++ -Wall -std=c++11  -c BestiolePeureuse.cpp -I .

BestioleGregaire.o : BestioleGregaire.h BestioleGregaire.cpp
	g++ -Wall -std=c++11  -c BestioleGregaire.cpp -I .

BestiolePrevoyante.o : BestiolePrevoyante.h BestiolePrevoyante.cpp
	g++ -Wall -std=c++11  -c BestiolePrevoyante.cpp -I .

BestioleFactory.o : BestioleFactory.h Bestiole.h BestiolePrevoyante.h BestioleGregaire.h BestiolePeureuse.h BestioleFactory.cpp 
	g++ -Wall -std=c++11  -c BestioleFactory.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

clean:
	rm -rf *.o main test

