#include "brioche.h"

double Brioche::tassa = 0.10;

Brioche::Brioche(std::string nomeProdotto, double carboidratiCibo, double proteineCibo, double grassiCibo, double prezzoPreparazioneBrioche, bool isVeganCibo, std::string barCodeBrioche, Impasto impastoBrioche, Forma formaBrioche, Ripieno ripienoBrioche, int scadenzaProdotto, int etaMinimaProdotto) 
	: Cibo(nomeProdotto, carboidratiCibo, proteineCibo, grassiCibo, isVeganCibo, scadenzaProdotto, etaMinimaProdotto), prezzoPreparazione(prezzoPreparazioneBrioche >= 0 ? prezzoPreparazioneBrioche : 0), barCode(barCodeBrioche), impasto(impastoBrioche), forma(formaBrioche), ripieno(ripienoBrioche) {}

Brioche::Brioche(const Brioche& brioche) : Cibo(brioche), prezzoPreparazione(brioche.prezzoPreparazione), barCode(brioche.barCode), impasto(brioche.impasto), forma(brioche.forma), ripieno(brioche.ripieno) {}

Brioche* Brioche::clone() const {
	return new Brioche(*this);
}

double Brioche::getPrezzoPreparazione() const {
	return prezzoPreparazione;
}

std::string Brioche::getBarCode() const {
	return barCode;
}

double Brioche::getPrezzo() const {
	return prezzoPreparazione + tassa;
}

std::string Brioche::getTipo() const {
	return "Brioche";
}

Brioche::Impasto Brioche::getImpasto() const {
	return impasto;
}

Brioche::Forma Brioche::getForma() const {
	return forma;
}

Brioche::Ripieno Brioche::getRipieno() const {
	return ripieno;
}

std::string Brioche::impastoToString() const {
	switch (impasto) {
		case Brioche::Classico:
			return "Classico";
			break;
		case Brioche::Integrale:
			return "Integrale";
			break;
		case Brioche::SenzaGlutine:
			return "Senza Glutine";
			break;
		default:
			break;
	}
}

std::string Brioche::formaToString() const {
	switch (forma) {
		case Brioche::Cornetto:
			return "Cornetto";
			break;
		case Brioche::Girella:
			return "Girella";
			break;
		case Brioche::Ciambella:
			return "Ciambella";
			break;
		default:
			break;
	}
}

std::string Brioche::ripienoToString() const {
	switch (ripieno) {
		case Brioche::Vuota:
			return "Vuota";
			break;
		case Brioche::Cioccolato:
			return "Cioccolato";
			break;
		case Brioche::Marmellata:
			return "Marmellata";
			break;
		case Brioche::Crema:
			return "Crema";
			break;
		default:
			break;
	}
}

void Brioche::setPrezzoPreparazione(const double& prezzoPreparazioneBrioche) {
	if (prezzoPreparazioneBrioche >= 0)
		prezzoPreparazione = prezzoPreparazioneBrioche;
}	

void Brioche::setBarCode(const std::string& barCodeBrioche) {
	if (barCodeBrioche != "")
		barCode = barCodeBrioche;
}

void Brioche::setImpasto(const Brioche::Impasto& impastoBrioche) {
		impasto = impastoBrioche;
}

void Brioche::setForma(const Forma& formaBrioche) {
		forma = formaBrioche;
}

void Brioche::setRipieno(const Ripieno& ripienoBrioche) {
	ripieno = ripienoBrioche;
}

void Brioche::serialize(Json::Value& root) const {
	Json::Value brioche;
	
	brioche["Tipo"] = getTipo();
	
	brioche["Nome"] = getNome();
	brioche["Scadenza"] = getScadenza();
	brioche["Eta minima"] = getEtaMinima();
	
	brioche["Carboidrati"] = getCarboidrati();
	brioche["Proteine"] = getProteine();
	brioche["Grassi"] = getGrassi();
	brioche["Vegano"] = isVegan();

	brioche["Prezzo preparazione"] = getPrezzoPreparazione();
	brioche["Bar Code"] = getBarCode();
	brioche["Impasto"] = impastoToString();
	brioche["Forma"] = formaToString();
	brioche["Ripieno"] = ripienoToString();
	
	root["Cibo"]["items"].append(brioche);
}

bool Brioche::operator==(const Brioche& prod) const {
	return Cibo::operator==(prod)
		&& prod.prezzoPreparazione == prezzoPreparazione
		&& prod.barCode == barCode
		&& prod.impasto == impasto
		&& prod.forma == forma
		&& prod.ripieno== ripieno;
}

bool Brioche::operator!=(const Brioche& prod) const {
	return !(*this == prod);
}
