#include "Piadina.h"

double Piadina::tassa = 0.30;

Piadina::Piadina(std::string nomeProdotto, double carboidratiCibo, double proteineCibo, double grassiCibo, double prezzoPreparazionePiadina, bool isVeganCibo, std::string barCodePiadina, Impasto impastoPiadina, int scadenzaProdotto, int etaMinimaProdotto) 
	: Cibo(nomeProdotto, carboidratiCibo, proteineCibo, grassiCibo, isVeganCibo, scadenzaProdotto, etaMinimaProdotto), prezzoPreparazione(prezzoPreparazionePiadina >= 0 ? prezzoPreparazionePiadina : 0), barCode(barCodePiadina), impasto(impastoPiadina) {}
	
Piadina::Piadina(const Piadina& piadina) : Cibo(piadina), prezzoPreparazione(piadina.prezzoPreparazione), barCode(piadina.barCode), impasto(piadina.impasto) {}

Piadina* Piadina::clone() const {
	return new Piadina(*this);
}

double Piadina::getPrezzoPreparazione() const {
	return prezzoPreparazione;
}

std::string Piadina::getBarCode() const {
	return barCode;
}
double Piadina::getPrezzo() const {
	return prezzoPreparazione + tassa;
}

Piadina::Impasto Piadina::getImpasto() const {
	return impasto;
}

std::string Piadina::impastoToString() const {
	switch (impasto) {
		case Piadina::Classico:
			return "Classico";
			break;
		case Piadina::Cereali:
			return "Cereali";
			break;
		case Piadina::Integrale:
			return "Integrale";
			break;
		case Piadina::Kamut:
			return "Kamut";
			break;
		default:
			break;
	}
}

void Piadina::setPrezzoPreparazione(const double& prezzoPreparazionePiadina) {
	if (prezzoPreparazionePiadina >= 0)
		prezzoPreparazione = prezzoPreparazionePiadina;
}
void Piadina::setBarCode(const std::string& barCodePiadina) {
	if (barCodePiadina != "")
		barCode = barCodePiadina;
}

void Piadina::setImpasto(Piadina::Impasto impastoPiadina) {
	impasto = impastoPiadina;
}

bool Piadina::operator==(const Piadina& prod) const {
	return Cibo::operator==(prod)
		&& prod.prezzoPreparazione == prezzoPreparazione
		&& prod.barCode == barCode
		&& prod.impasto == impasto;
}

bool Piadina::operator!=(const Piadina& prod) const {
	return !(*this == prod);
}