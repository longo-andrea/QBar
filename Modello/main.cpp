#include <iostream>
#include <fstream>
#include <string>

#include "Cocktail.h"
#include "Panino.h"
#include "SmartPtr.h"
#include "Qontainer.h"

using namespace std;

int main() {



	
	SmartPtr<Prodotto> malibu(new Cocktail("Malibu", 15, 16, 22, 12, "V55AE", Cocktail::Quantita::Medium, Cocktail::Classificazione::Coffe, 12, true, 2100, 18));
	SmartPtr<Prodotto> menta(new Cocktail("Menta", 15, 16, 22, 12, "V55AE", Cocktail::Quantita::Medium, Cocktail::Classificazione::Coffe, 12, true, 2100, 18));
	
	Qontainer<SmartPtr<Prodotto>*> qp(20);

	qp.push_back(&malibu);
	qp.push_back(&menta);

	auto it = qp.begin();
	qp.erase(it);

	it = qp.search(&menta);

	cout << (**it)->getNome() << endl;




}