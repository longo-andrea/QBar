#include "panino.h"

double Panino::tassa = 0.40;

Panino::Panino(std::string nomeProdotto, double carboidratiCibo, double proteineCibo, double grassiCibo, double prezzoPreparazionePanino, std::string barCodePanino, Panino::Pane panePanino, bool PaninoVegano, int scadenzaProdotto, int etaMinimaProdotto)
	: Cibo(nomeProdotto, carboidratiCibo, proteineCibo, grassiCibo, PaninoVegano, scadenzaProdotto, etaMinimaProdotto), prezzoPreparazione(prezzoPreparazionePanino >= 0 ? prezzoPreparazionePanino : 0), barCode(barCodePanino), pane(panePanino) {}

Panino::Panino(const Panino& panino) : Cibo(panino), prezzoPreparazione(panino.prezzoPreparazione), barCode(panino.barCode), pane(panino.pane) {}

Panino* Panino::clone() const {
	return new Panino(*this);
}

double Panino::getPrezzoPreparazione() const {
	return prezzoPreparazione;
}

std::string Panino::getBarCode() const {
	return barCode;
}

double Panino::getPrezzo() const {
	return prezzoPreparazione + tassa;
}

std::string Panino::getTipo() const {
	return "Panino";
}

Panino::Pane Panino::getPane() const {
	return pane;
}

std::string Panino::paneToString() const {
	switch (pane) {
		case Panino::Tartaruga:
			return "Tartaruga";
			break;
		case Panino::Arabo:
			return "Arabo";
			break;
		case Panino::Baguette:
			return "Baguette";
			break;
		case Panino::Integrale:
			return "Baguette";
			break;
		default:
			break;
	}
}

void Panino::setPrezzoPreparazione(const double& prezzoPreparazionePanino) {
	if (prezzoPreparazionePanino >= 0)
		prezzoPreparazione = prezzoPreparazionePanino;
}

void Panino::setBarCode(const std::string& barCodePanino) {
	if (barCodePanino != "")
		barCode = barCodePanino;
}

void Panino::setPane(Pane panePanino) {
	pane = panePanino;
}

void Panino::serialize(Json::Value& root) const {
	Json::Value panino;
	
	panino["Tipo"] = getTipo();
	
	panino["Nome"] = getNome();
	panino["Scadenza"] = getScadenza();
	panino["Eta minima"] = getEtaMinima();
	
	panino["Carboidrati"] = getCarboidrati();
	panino["Proteine"] = getProteine();
	panino["Grassi"] = getGrassi();
	panino["Vegano"] = isVegan();

	panino["Prezzo preparazione"] = getPrezzoPreparazione();
	panino["Bar Code"] = getBarCode();
	panino["Pane"] = paneToString();
	
	root["Cibo"]["items"].append(panino);
}

bool Panino::operator==(const Panino& prod) const {
	return Cibo::operator==(prod)
		&& prod.prezzoPreparazione == prezzoPreparazione
		&& prod.barCode == barCode
		&& prod.pane == pane;
}

bool Panino::operator!=(const Panino& prod) const {
	return !(*this == prod);
}