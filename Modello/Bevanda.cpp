#include "Bevanda.h"

double Bevanda::valoreEnergeticoCarboidrati = 4;
double Bevanda::valoreEnergeticoProteine = 4;
double Bevanda::valoreEnergeticoGrassi = 9;

Bevanda::Bevanda(std::string nomeProdotto, double carboidratiBevanda, double proteineBevanda, double grassiBevanda, bool alcoholicBevanda, int scadenzaProdotto, int etaMinimaProdotto)
	: Prodotto(nomeProdotto, scadenzaProdotto, etaMinimaProdotto), carboidrati(carboidratiBevanda >= 0 ? carboidratiBevanda : 0), proteine(proteineBevanda >= 0 ? proteineBevanda : 0), grassi(grassiBevanda >= 0 ? grassiBevanda : 0), alcoholic(alcoholicBevanda) {}

Bevanda::Bevanda(const Bevanda& bevanda) : Prodotto(bevanda), carboidrati(bevanda.getCarboidrati()), proteine(bevanda.getProteine()), grassi(bevanda.getGrassi()), alcoholic(bevanda.isAlcoholic()) {}

double Bevanda::getCarboidrati() const {
	return carboidrati;
}

double Bevanda::getProteine() const {
	return proteine;
}

double Bevanda::getGrassi() const {
	return grassi;
}

bool Bevanda::isAlcoholic() const {
	return alcoholic;
}

void Bevanda::setCarboidrati(const double& carboidratiBevanda) {
	if (carboidratiBevanda >= 0)
		carboidrati = carboidratiBevanda;
}

void Bevanda::setProteine(const double& proteineBevanda) {
	if (proteineBevanda >= 0)
		proteine = proteineBevanda;
}

void Bevanda::setGrassi(const double& grassiBevanda) {
	if (grassiBevanda >= 0)
		grassi = grassiBevanda;
}

void Bevanda::setAlcoholic(const bool& alcoholicBevanda) {
	alcoholic = alcoholicBevanda;
}

double Bevanda::calcolaCalorie() const {
	return carboidrati * valoreEnergeticoCarboidrati +
		proteine * valoreEnergeticoProteine +
		grassi * valoreEnergeticoGrassi;
}

bool Bevanda::operator==(const Bevanda& prod) const {
	return Prodotto::operator==(prod)
		&& prod.carboidrati == carboidrati
		&& prod.proteine == proteine
		&& prod.grassi == grassi
		&& prod.alcoholic == alcoholic;
}

bool Bevanda::operator!=(const Bevanda& prod) const {
	return !(*this == prod);
}
