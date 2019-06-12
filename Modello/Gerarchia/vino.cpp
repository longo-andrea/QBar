#include "vino.h"

Vino::inizializzaVino::inizializzaVino() {
	ptr = new Vino();
	mappaProdotto[ptr->getTipo()] = ptr;
}

Vino::inizializzaVino::~inizializzaVino() {
	delete ptr;
}

Vino::inizializzaVino Vino::mappaVino;

double Vino::tassa = 2;

Vino::Vino(const std::string& nomeProdotto, double carboidratiBevanda, double proteineBevanda, double grassiBevanda, double gradazioneAlcolicaVino, double prezzoNettoVino, double litriVino, const std::string& barCodeVino, int annoProduzioneVino, Regione regioneVino, bool alcohoilcBevanda, int scadenzaProdotto, int etaMinimaProdotto)
	: Bevanda(nomeProdotto, carboidratiBevanda, proteineBevanda, grassiBevanda, alcohoilcBevanda, scadenzaProdotto, etaMinimaProdotto), prezzoNetto(prezzoNettoVino >= 0 ? prezzoNettoVino : 0), gradazioneAlcolica(gradazioneAlcolicaVino >= 0 ? gradazioneAlcolicaVino : 0), barCode(barCodeVino), annoProduzione(annoProduzioneVino >= 0 ? annoProduzioneVino : 1400), regione(regioneVino), litri(litriVino >= 0 ? litriVino : 0) {}

Vino::Vino(const Vino& vino) : Bevanda(vino), prezzoNetto(vino.prezzoNetto), gradazioneAlcolica(vino.gradazioneAlcolica), barCode(vino.barCode), annoProduzione(vino.annoProduzione), regione(vino.regione), litri(vino.litri) {}

Vino* Vino::clone() const {
	return new Vino(*this);
}

double Vino::getPrezzo() const {
	return prezzoNetto + tassa;
}

std::string Vino::getBarCode() const {
	return barCode;
}

double Vino::calcolaCalorie() const {
	return Bevanda::calcolaCalorie() + gradazioneAlcolica * valoreEnergeticoAlcol;
}

std::string Vino::getTipo() const {
	return "Vino";
}

double Vino::getPrezzoNetto() const {
	return prezzoNetto;
}

double Vino::getGradazioneAlcolica() const {
	return gradazioneAlcolica;
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

double Vino::getLitri() const {
	return litri;
}

void Vino::setTassa(const double& tassaVino) {
	if(tassaVino >= 0)
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

void Vino::setAnnoProduzione(const int& annoProduzioneVino) {
	if (annoProduzioneVino >= 1400)
		annoProduzione = annoProduzioneVino;
}

void Vino::setRegione(const Regione& regioneVino) {
	regione = regioneVino;
}

void Vino::setLitri(const double& litriVino) {
	if (litriVino >= 0)
		litri = litriVino;
}

void Vino::serialize(Json::Value& root) const {
	Json::Value vino;
	
	vino["Tipo"] = getTipo();
	
	vino["Nome"] = getNome();
	vino["Scadenza"] = getScadenza();
	vino["Eta minima"] = getEtaMinima();
	
	vino["Carboidrati"] = getCarboidrati();
	vino["Proteine"] = getProteine();
	vino["Grassi"] = getGrassi();
	vino["Alcolico"] = isAlcoholic();
	
	vino["Prezzo netto"] = getPrezzoNetto();
	vino["Bar Code"] = getBarCode();
	vino["Anno"] = getAnnoProduzione();
	vino["Regione"] = regioneToString();
	vino["Gradazione"] = getGradazioneAlcolica();
	vino["Quantita"] = getLitri();
	
	root["Bevanda"]["items"].append(vino);				
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

/* ----- PRIVATE METHODS ----- */

Vino* Vino::create(Json::Value& root) const {
	std::string nomeProdotto = root["Nome"].asString();
	int scadenzaProdotto = root["Scandeza"].asInt();
	int etaMinimaProdotto = root["Eta minima"].asInt();
	
	double carboidratiBevanda = root["Carboidrati"].asDouble();
	double proteineBevanda = root["Proteine"].asDouble();
	double grassiBevanda = root["Grassi"].asDouble();
	bool isAlcoholicBevanda = root["Alcolico"].asBool();

	double prezzoNettoVino = root["Prezzo netto"].asDouble();
	std::string barCodeVino = root["Bar Code"].asString();
	
	double gradazioneAlcolicaVino = root["Gradazione"].asDouble();
	unsigned int annoProduzioneVino = root["Anno"].asUInt();
	Regione regioneVino = stringToRegione(root["Regione"].asString());
	double litriVino = root["Quantita"].asDouble();
	
	
	return new Vino(nomeProdotto, carboidratiBevanda, proteineBevanda, grassiBevanda, gradazioneAlcolicaVino, prezzoNettoVino, litriVino, barCodeVino, annoProduzioneVino, regioneVino, isAlcoholicBevanda, scadenzaProdotto, etaMinimaProdotto);
}
	
Vino::Regione Vino::stringToRegione(const std::string& regioneString) {
	if(regioneString == "Veneto")
		return Regione::Veneto;
	else if(regioneString == "Emilia")
		return Regione::Emilia;
	else if(regioneString == "Toscana")
		return Regione::Toscana;
	else if(regioneString == "Friulia-Venezia-Giulia")
		return Regione::Friuli;	
}
