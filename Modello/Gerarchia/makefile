# FIRST LEVEL CLASS
Cocktail: Cocktail.o
	g++ -g main.cpp Prodotto.o Bevanda.o Cocktail.o 
	
Cocktail.o: Cocktail.cpp Bevanda.o Prodotto.o
	g++ -c Cocktail.cpp

Cola: Cola.o
	g++ -g main.cpp Prodotto.o Bevanda.o Cola.o 
	
Cola.o: Cola.cpp Bevanda.o Prodotto.o
	g++ -c Cola.cpp

Vino: Vino.o
	g++ -g main.cpp Prodotto.o Bevanda.o Vino.o 
	
Vino.o: Vino.cpp Bevanda.o Prodotto.o
	g++ -c Vino.cpp


Panino: Panino.o
	g++ -g main.cpp Prodotto.o Cibo.o Panino.o

Panino.o: Panino.cpp Cibo.o Prodotto.o
	g++ -c Panino.cpp

Piadina: Piadina.o
	g++ -g main.cpp Prodotto.o Cibo.o Piadina.o

Piadina.o: Piadina.cpp Cibo.o Prodotto.o
	g++ -c Piadina.cpp

Briosche: Briosche.o
	g++ -g main.cpp Prodotto.o Cibo.o Briosche.o

Briosche.o: Briosche.cpp Cibo.o Prodotto.o
	g++ -c Briosche.cpp

# SECOND LEVEL CLASS
Bevanda.o: Bevanda.cpp Prodotto.o
	g++ -c Bevanda.cpp
	
Cibo.o: Cibo.cpp Prodotto.o
	g++ -c Cibo.cpp

# BASE CLASS
Prodotto.o: Prodotto.cpp
	g++ -c Prodotto.cpp

