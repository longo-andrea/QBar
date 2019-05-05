#include <iostream>
#include <string>

#include "Briosche.h"

using namespace std;

int main() {


	Briosche crema("Crema", 14, 15, 26, -4.75, true, "A665s", Briosche::Impasto::Integrale, Briosche::Tipo::Cornetto, Briosche::Ripieno::Crema, 2026, 14);

	// Stampa di tutti i valori appartenenti ad un briosche
	/*
	cout << "-----------" << endl;
	cout << "PRODOTTO" << endl;
	cout << "Nome: " << crema.getNome() << endl;
	cout << "Scadenza: " << crema.getScadenza() << endl;
	cout << "Eta minima: " << crema.getEtaMinima() << endl;

	cout << "CIBO" << endl;
	cout << "Carboidrati: " << crema.getCarboidrati() << endl;
	cout <<	"Proteine: " << crema.getProteine() << endl;
	cout <<	"Grassi: " << crema.getGrassi() << endl;
	cout << "Vegano: " << crema.isVegan() << endl;

	cout << "Prezzo preparazione: " << crema.getPrezzoPreparazione() << endl;
	cout << "BarCode: " << crema.getBarCode() << endl;
	cout << "Prezzo: " << crema.getPrezzo() << endl;
	cout << "Impasto: " << crema.impastoToString() << endl;
	cout << "Tipo: " << crema.tipoToString() << endl;
	cout << "Ripieno: " << crema.ripienoToString() << endl;
	*/

	// Test dei setter (valori accettabili)
	/*
	crema.setNome("Pistacchio");
	crema.setScadenza(2040);
	crema.setEtaMinima(20);
	crema.setCarboidrati(77);
	crema.setProteine(96);
	crema.setGrassi(45);
	crema.setIsVegan(false);
	crema.setPrezzoPreparazione(50);
	crema.setBarCode("A655A");
	crema.setImpasto(Briosche::Impasto::Classico);
	crema.setTipo(Briosche::Tipo::Girella);
	crema.setRipieno(Briosche::Ripieno::Cioccolato);
	*/

	// Test dei setter (valori errati)
	/*
	crema.setNome("");
	crema.setScadenza(2016);
	crema.setEtaMinima(-5);
	crema.setCarboidrati(-77);
	crema.setProteine(-96);
	crema.setGrassi(-45);
	crema.setIsVegan(false);
	crema.setPrezzoPreparazione(-44);
	crema.setBarCode("");
	crema.setImpasto(Briosche::Impasto::Classico);
	crema.setTipo(Briosche::Tipo::Girella);
	crema.setRipieno(Briosche::Ripieno::Cioccolato);
	*/

	// Costruzione con valori errati
	//Briosche crema("Crema", -14, -15, -26, -4.75, "A665s", Briosche::Impasto::Integrale, Briosche::Tipo::Cornetto, Briosche::Ripieno::Crema, 2010, 11);


	cout << "-----------" << endl;
	cout << "PRODOTTO" << endl;
	cout << "Nome: " << crema.getNome() << endl;
	cout << "Scadenza: " << crema.getScadenza() << endl;
	cout << "Eta minima: " << crema.getEtaMinima() << endl;

	cout << "CIBO" << endl;
	cout << "Carboidrati: " << crema.getCarboidrati() << endl;
	cout << "Proteine: " << crema.getProteine() << endl;
	cout << "Grassi: " << crema.getGrassi() << endl;
	cout << "Vegano: " << crema.isVegan() << endl;
	cout << "Calorie: " << crema.calcolaCalorie() << endl;

	cout << "BRIOSCHE" << endl;
	cout << "Prezzo preparazione: " << crema.getPrezzoPreparazione() << endl;
	cout << "BarCode: " << crema.getBarCode() << endl;
	cout << "Prezzo: " << crema.getPrezzo() << endl;
	cout << "Impasto: " << crema.impastoToString() << endl;
	cout << "Tipo: " << crema.tipoToString() << endl;
	cout << "Ripieno: " << crema.ripienoToString() << endl;
}
