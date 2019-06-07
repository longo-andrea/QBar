# FIRST LEVEL CLASS
cocktail: cocktail.o
	g++ -g main.cpp prodotto.o bevanda.o cocktail.o 
	
cocktail.o: cocktail.cpp bevanda.o prodotto.o
	g++ -c cocktail.cpp

analcolico: analcolico.o
	g++ -g main.cpp prodotto.o bevanda.o analcolico.o 
	
analcolico.o: analcolico.cpp bevanda.o prodotto.o
	g++ -c analcolico.cpp

vino: vino.o
	g++ -g main.cpp prodotto.o bevanda.o vino.o 
	
vino.o: vino.cpp bevanda.o prodotto.o
	g++ -c Vino.cpp


panino: panino.o
	g++ -g main.cpp prodotto.o cibo.o panino.o

panino.o: panino.cpp cibo.o prodotto.o
	g++ -c panino.cpp

piadina: piadina.o
	g++ -g main.cpp prodotto.o cibo.o piadina.o

piadina.o: piadina.cpp cibo.o prodotto.o
	g++ -c piadina.cpp

brioche: brioche.o
	g++ -g main.cpp prodotto.o cibo.o brioche.o ../json/jsoncpp.o ../model.o

brioche.o: brioche.cpp cibo.o prodotto.o
	g++ -c brioche.cpp

# SECOND LEVEL CLASS
bevanda.o: bevanda.cpp prodotto.o
	g++ -c bevanda.cpp
	
cibo.o: cibo.cpp prodotto.o
	g++ -c cibo.cpp

# BASE CLASS
prodotto.o: prodotto.cpp
	g++ -c prodotto.cpp

