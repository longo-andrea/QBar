#include <iostream>
#include <string>
#include "Panino.h"
#include "Briosche.h"

using namespace std;

int main() {

	Briosche pistacchia("Pistacchia", 15, 26, 14, 14.50, "AS5515", Briosche::Impasto::Integrale, Briosche::Tipo::Cornetto, Briosche::Ripieno::Marmellata, 2019, 14);
	cout << pistacchia.getNome() << endl;
	cout << pistacchia.impastoToString() << endl;

}
