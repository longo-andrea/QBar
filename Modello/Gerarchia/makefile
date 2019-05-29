# FIRST LEVEL CLASS
cocktail: cocktail.o
	g++ -g main.cpp prodotto.o bevanda.o cocktail.o 
	
cocktail.o: cocktail.cpp bevanda.o prodotto.o
	g++ -c cocktail.cpp

cola: cola.o
	g++ -g main.cpp prodotto.o bevanda.o cola.o 
	
cola.o: cola.cpp bevanda.o prodotto.o
	g++ -c cola.cpp

vino: vino.o
	g++ -g main.cpp prodotto.o bevanda.o vino.o 
	
vino.o: vino.cpp bevanda.o prodotto.o
	g++ -c Vino.cpp


panino: panino.o
	g++ -g main.cpp prodotto.o Cibo.o panino.o

panino.o: panino.cpp Cibo.o prodotto.o
	g++ -c panino.cpp

piadina: piadina.o
	g++ -g main.cpp prodotto.o Cibo.o piadina.o

piadina.o: piadina.cpp Cibo.o prodotto.o
	g++ -c piadina.cpp

briosche: briosche.o
	g++ -g main.cpp prodotto.o Cibo.o briosche.o

briosche.o: briosche.cpp Cibo.o prodotto.o
	g++ -c briosche.cpp

# SECOND LEVEL CLASS
bevanda.o: bevanda.cpp prodotto.o
	g++ -c bevanda.cpp
	
cibo.o: cibo.cpp prodotto.o
	g++ -c cibo.cpp

# BASE CLASS
prodotto.o: prodotto.cpp
	g++ -c prodotto.cpp

