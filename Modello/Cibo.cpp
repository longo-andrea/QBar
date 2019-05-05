#include "Cibo.h"

double Cibo::valoreEnergeticoCarboidrati = 4;
double Cibo::valoreEnergeticoProteine = 4;
double Cibo::valoreEnergeticoGrassi = 9;

Cibo::Cibo(std::string nomeProdotto, double carboidratiCibo, double proteineCibo, double grassiCibo, bool ProdottoVegano, int scadenzaProdotto, int etaMinimaProdotto)
	: Prodotto(nomeProdotto, scadenzaProdotto, etaMinimaProdotto), carboidrati(carboidratiCibo >= 0 ? carboidratiCibo : 0), proteine(proteineCibo >= 0 ? proteineCibo : 0), grassi(grassiCibo >= 0 ? grassiCibo : 0), vegan(ProdottoVegano) {}

Cibo::Cibo(const Cibo& cibo) : Prodotto(cibo), carboidrati(cibo.carboidrati), proteine(cibo.proteine), grassi(cibo.grassi), vegan(cibo.vegan) {}

double Cibo::getCarboidrati() const {
	return carboidrati;
}

double Cibo::getProteine() const {
	return proteine;
}

double Cibo::getGrassi() const {
	return grassi;
}

bool Cibo::isVegan() const {
	return vegan;
}

void Cibo::setCarboidrati(const double& carboidratiCibo) {
	if (carboidratiCibo >= 0)
		carboidrati = carboidratiCibo;
}

void Cibo::setProteine(const double& proteineCibo) {
	if (proteineCibo >= 0)
		proteine = proteineCibo;
}

void Cibo::setGrassi(const double& grassiCibo) {
	if (grassiCibo >= 0)
		grassi = grassiCibo;
}

void Cibo::setIsVegan(const bool& isVeganCibo) {
	vegan = isVeganCibo;
}

double Cibo::calcolaCalorie() const {
	return carboidrati * valoreEnergeticoCarboidrati +
		proteine * valoreEnergeticoProteine +
		grassi * valoreEnergeticoGrassi;
}

bool Cibo::operator==(const Cibo& prod) const {
	return Prodotto::operator==(prod)
		&& prod.carboidrati == carboidrati
		&& prod.proteine == proteine
		&& prod.grassi == grassi;
}

bool Cibo::operator!=(const Cibo& prod) const {
	return !(*this == prod);
}
