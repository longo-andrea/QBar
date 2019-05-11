#include "Cola.h"

double Cola::tassa = 0.50;

Cola::Cola(std::string nomeProdotto, double carboidratiBevanda, double proteineBevanda, double grassiBevanda, double prezzoNettoCola, std::string barCodeCola, Tipo tipoCola, Contenitore contenitoreCola, double litriCola, bool isAlcoholicBevanda, int scadenzaProdotto, int etaMinimaProdotto)
	: Bevanda(nomeProdotto, carboidratiBevanda, proteineBevanda, grassiBevanda, isAlcoholicBevanda, scadenzaProdotto, etaMinimaProdotto), prezzoNetto(prezzoNettoCola >= 0 ? prezzoNettoCola : 0), barCode(barCodeCola), tipo(tipoCola), contenitore(contenitoreCola), litri(litriCola >=0 ? litriCola : 0) {}

Cola::Cola(const Cola& cola) : Bevanda(cola), prezzoNetto(cola.prezzoNetto), barCode(cola.barCode), tipo(cola.tipo), contenitore(cola.contenitore), litri(cola.litri) {}

Cola* Cola::clone() const {
	return new Cola(*this);
}

double Cola::getPrezzoNetto() const {
	return prezzoNetto;
}

double Cola::getPrezzo() const {
	return prezzoNetto + tassa;
}

std::string Cola::getBarCode() const {
	return barCode;
}

Cola::Tipo Cola::getTipo() const {
	return tipo;
}

std::string Cola::tipoToString() const {
	switch (tipo) {
		case Cola::Classica:
			return "Classica";
			break;
		case Cola::Zero:
			return "Zero";
			break;
		case Cola::Light:
			return "Light";
			break;
		case Cola::Diet:
			return "Diet";
			break;
		case Cola::Stevia:
			return "Stevia";
			break;
		default:
			break;
	}
}

Cola::Contenitore Cola::getContenitore() const {
	return contenitore;
}

std::string Cola::contenitoreToString() const {
	switch (contenitore) {
		case Cola::Lattina:
			return "Lattina";
			break;
		case Cola::Bottiglia:
			return "Bottiglia";
			break;
		case Cola::Spina:
			return "Spina";
			break;
		default:
			break;
	}
}

double Cola::getLitri() const {
	return litri;
}

void Cola::setTassa(const double& tassaCola) {
	if (tassaCola >= 0)
		tassa = tassaCola;
}

void Cola::setPrezzoNetto(const double& prezzoNettoCola) {
	if (prezzoNettoCola >= 0)
		prezzoNetto = prezzoNettoCola;
}

void Cola::setBarCode(const std::string& barCodeCola) {
	if (barCodeCola != "")
		barCode = barCodeCola;
}

void Cola::setTipo(const Tipo& tipoCola) {
	tipo = tipoCola;
}

void Cola::setContenitore(const Contenitore& contenitoreCola) {
	contenitore = contenitoreCola;
}

void Cola::setLitri(const double& litriCola) {
	if (litriCola >= 0)
		litri = litriCola;
}

bool Cola::operator==(const Cola& prod) const {
	return Bevanda::operator==(prod)
		&& prod.prezzoNetto == prezzoNetto
		&& prod.barCode == barCode
		&& prod.tipo == tipo
		&& prod.contenitore == contenitore
		&& prod.litri == litri;
}

bool Cola::operator!=(const Cola& prod) const {
	return !(*this == prod);
}