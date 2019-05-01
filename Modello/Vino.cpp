#include "vino.h"

double Vino::tassa = 2;
double Vino::valoreEnergeticoAlcol = 7;

Vino::Vino(std::string nomeProdotto, double carboidratiBevanda, double proteineBevanda, double grassiBevanda, bool alcohoilcBevanda, double gradazioneAlcolicaVino, double prezzoNettoVino, std::string barCodeVino, unsigned int annoProduzioneVino, Regione regioneVino, int scadenzaProdotto, int etaMinimaProdotto) 
	: Bevanda(nomeProdotto, carboidratiBevanda, proteineBevanda, grassiBevanda, alcohoilcBevanda, scadenzaProdotto, etaMinimaProdotto), prezzoNetto(prezzoNettoVino), gradazioneAlcolica(gradazioneAlcolicaVino), barCode(barCodeVino), annoProduzione(annoProduzioneVino), regione(regioneVino) {}

Vino::Vino(const Vino& vino) : Bevanda(vino), prezzoNetto(vino.prezzoNetto), gradazioneAlcolica(vino.gradazioneAlcolica), barCode(vino.barCode), annoProduzione(vino.annoProduzione), regione(vino.regione) {}

Vino* Vino::clone() const {
	return new Vino(*this);
}

double Vino::getPrezzoNetto() const {
	return prezzoNetto;
}

double Vino::getPrezzo() const {
	return prezzoNetto + tassa;
}

double Vino::getGradazioneAlcolica() const {
	return gradazioneAlcolica;
}

std::string Vino::getBarCode() const {
	return barCode;
}

unsigned int Vino::getAnnoProduzione() const {
	return annoProduzione;
}

Vino::Regione Vino::getRegione() const {
	return regione;
}

std::string Vino::regioneToString() const {
	switch (regione) {
		case Vino::Veneto:
			return "Veneto";
			break;
		case Vino::Emilia:
			return "Emilia-Romagna";
			break;
		case Vino::Toscana:
			return "Toscana";
			break;
		case Vino::Friuli:
			return "Friulia-Venezia-Giulia";
			break;
		default:
			break;
	}
}

void Vino::setTassa(const double& tassaVino) {
	if (tassaVino >= 0)
		tassa = tassaVino;
}

void Vino::setPrezzoNetto(const double& prezzoNettoVino) {
	if (prezzoNettoVino >= 0)
		prezzoNetto = prezzoNettoVino;
}

void Vino::setGradazioneAlcolica(const double& gradazioneVino) {
	if (gradazioneVino >= 0)
		gradazioneAlcolica = gradazioneVino;
}

void Vino::setBarCode(const std::string& barCodeVino) {
	if (barCodeVino != "")
		barCode = barCodeVino;
}

void Vino::setAnnoProduzione(const unsigned int& annoProduzioneVino) {
	annoProduzione = annoProduzioneVino;
}

void Vino::setRegione(const Regione& regioneVino) {
	regione = regioneVino;
}

double Vino::calcolaCalorie() const {
	return Bevanda::calcolaCalorie() + gradazioneAlcolica * valoreEnergeticoAlcol;
}

bool Vino::operator==(const Vino& prod) const {
	return Bevanda::operator==(prod)
		&& prod.prezzoNetto == prezzoNetto
		&& prod.gradazioneAlcolica == gradazioneAlcolica
		&& prod.barCode == barCode
		&& prod.annoProduzione == annoProduzione
		&& prod.regione == regione;
}

bool Vino::operator!=(const Vino& prod) const {
	return !(*this == prod);
}