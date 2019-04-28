#include "Panino.h"

double Panino::tassa = 0.40;

Panino::Panino(std::string nomeProdotto, double carboidratiCibo, double proteineCibo, double grassiCibo, double prezzoPreparazionePanino, std::string barCodePanino, Panino::Pane panePanino, bool PaninoVegano, int scadenzaProdotto, int etaMinimaProdotto)
	: Cibo(nomeProdotto, carboidratiCibo, proteineCibo, grassiCibo, PaninoVegano, scadenzaProdotto, etaMinimaProdotto), prezzoPreparazione(prezzoPreparazionePanino >= 0 ? prezzoPreparazionePanino : 0), barCode(barCodePanino), pane(panePanino) {}

Panino::Panino(const Panino& panino) : Cibo(panino), prezzoPreparazione(panino.getPrezzoPreparazione()), barCode(panino.getBarCode()), pane(panino.getPane()) {}

Panino& Panino::operator=(const Panino& copiaPanino) {
	if (this != &copiaPanino) {
		setNomeProdotto(copiaPanino.getNome());
		setScadenza(copiaPanino.getScadenza());
		setEtaMinima(copiaPanino.getEtaMinima());
		setCarboidrati(copiaPanino.getCarboidrati());
		setProteine(copiaPanino.getProteine());
		setGrassi(copiaPanino.getGrassi());
		prezzoPreparazione = copiaPanino.prezzoPreparazione;
		barCode = copiaPanino.barCode;
		pane = copiaPanino.pane;
	}
	return *this;
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

void Panino::setTassa(const double& tassaPanino) {
	if (tassaPanino >= 0)
		tassa = tassaPanino;
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

bool Panino::operator==(const Prodotto& prod) const {
	return dynamic_cast<const Panino*>(&prod) && Cibo::operator==(prod)
		&& static_cast<const Panino&>(prod).prezzoPreparazione == prezzoPreparazione
		&& static_cast<const Panino&>(prod).barCode == barCode
		&& static_cast<const Panino&>(prod).pane == pane;
}

bool Panino::operator!=(const Prodotto& prod) const {
	return !(*this == prod);
}