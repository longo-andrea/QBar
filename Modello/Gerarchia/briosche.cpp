#include "briosche.h"

double Briosche::tassa = 0.10;

Briosche::Briosche(std::string nomeProdotto, double carboidratiCibo, double proteineCibo, double grassiCibo, double prezzoPreparazioneBriosche, bool isVeganCibo, std::string barCodeBriosche, Impasto impastoBriosche, Tipo tipoBriosche, Ripieno ripienoBriosche, int scadenzaProdotto, int etaMinimaProdotto) 
	: Cibo(nomeProdotto, carboidratiCibo, proteineCibo, grassiCibo, isVeganCibo, scadenzaProdotto, etaMinimaProdotto), prezzoPreparazione(prezzoPreparazioneBriosche >= 0 ? prezzoPreparazioneBriosche : 0), barCode(barCodeBriosche), impasto(impastoBriosche), tipo(tipoBriosche), ripieno(ripienoBriosche) {}

Briosche::Briosche(const Briosche& briosche) : Cibo(briosche), prezzoPreparazione(briosche.prezzoPreparazione), barCode(briosche.barCode), impasto(briosche.impasto), tipo(briosche.tipo), ripieno(briosche.ripieno) {}

Briosche* Briosche::clone() const {
	return new Briosche(*this);
}

double Briosche::getPrezzoPreparazione() const {
	return prezzoPreparazione;
}

std::string Briosche::getBarCode() const {
	return barCode;
}

double Briosche::getPrezzo() const {
	return prezzoPreparazione + tassa;
}

Briosche::Impasto Briosche::getImpasto() const {
	return impasto;
}

Briosche::Tipo Briosche::getTipo() const {
	return tipo;
}

Briosche::Ripieno Briosche::getRipieno() const {
	return ripieno;
}

std::string Briosche::impastoToString() const {
	switch (impasto) {
		case Briosche::Classico:
			return "Classico";
			break;
		case Briosche::Integrale:
			return "Integrale";
			break;
		case Briosche::SenzaGlutine:
			return "Senza Glutine";
			break;
		default:
			break;
	}
}

std::string Briosche::tipoToString() const {
	switch (tipo) {
		case Briosche::Cornetto:
			return "Cornetto";
			break;
		case Briosche::Girella:
			return "Girella";
			break;
		case Briosche::Ciambella:
			return "Ciambella";
			break;
		default:
			break;
	}
}

std::string Briosche::ripienoToString() const {
	switch (ripieno) {
		case Briosche::Vuota:
			return "Vuota";
			break;
		case Briosche::Cioccolato:
			return "Cioccolato";
			break;
		case Briosche::Marmellata:
			return "Marmellata";
			break;
		case Briosche::Crema:
			return "Crema";
			break;
		default:
			break;
	}
}

void Briosche::setPrezzoPreparazione(const double& prezzoPreparazioneBriosche) {
	if (prezzoPreparazioneBriosche >= 0)
		prezzoPreparazione = prezzoPreparazioneBriosche;
}	

void Briosche::setBarCode(const std::string& barCodeBriosche) {
	if (barCodeBriosche != "")
		barCode = barCodeBriosche;
}

void Briosche::setImpasto(const Briosche::Impasto& impastoBriosche) {
		impasto = impastoBriosche;
}

void Briosche::setTipo(const Tipo& tipoBriosche) {
		tipo = tipoBriosche;
}

void Briosche::setRipieno(const Ripieno& ripienoBriosche) {
	ripieno = ripienoBriosche;
}

bool Briosche::operator==(const Briosche& prod) const {
	return Cibo::operator==(prod)
		&& prod.prezzoPreparazione == prezzoPreparazione
		&& prod.barCode == barCode
		&& prod.impasto == impasto
		&& prod.tipo == tipo
		&& prod.ripieno== ripieno;
}

bool Briosche::operator!=(const Briosche& prod) const {
	return !(*this == prod);
}
