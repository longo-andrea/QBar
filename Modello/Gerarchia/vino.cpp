#include "vino.h"

Vino::inizializzaVino::inizializzaVino() {
	ptr = new Vino();
    mappaProdotto["Vino"] = ptr;
}

Vino::inizializzaVino::~inizializzaVino() {
	delete ptr;
}

Vino::inizializzaVino Vino::mappaVino;

double Vino::tassa = 1.20;

Vino::Vino(const std::string& nomeProdotto, double carboidratiBevanda, double proteineBevanda, double grassiBevanda, double prezzoNettoVino, const std::string& barCodeVino, Regione regioneVino, double gradazioneAlcolicaVino, double litriVino, int annoProduzioneVino, bool isAlcoholicBevanda, int scadenzaProdotto, int etaMinimaProdotto) 
    : Bevanda(nomeProdotto, carboidratiBevanda, proteineBevanda, grassiBevanda, isAlcoholicBevanda, scadenzaProdotto, etaMinimaProdotto), prezzoNetto(prezzoNettoVino >= 0 ? prezzoNettoVino : 0), barCode(barCodeVino), regione(regioneVino), annoProduzione(annoProduzioneVino >= 0 ? annoProduzioneVino : 0), litri(litriVino >= 0 ? litriVino : 0), gradazioneAlcolica(gradazioneAlcolicaVino >= 0 ? gradazioneAlcolicaVino : 0) {}
	
Vino::Vino(const Vino& vino) : Bevanda(vino), prezzoNetto(vino.prezzoNetto), barCode(vino.barCode), regione(vino.regione), annoProduzione(vino.annoProduzione), litri(vino.litri), gradazioneAlcolica(vino.gradazioneAlcolica) {}

Vino* Vino::clone() const {
	return new Vino(*this);
}

std::string Vino::getBarCode() const {
	return barCode;	
}

double Vino::getPrezzo() const {
	return prezzoNetto + tassa;
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

Vino::Regione Vino::getRegione() const {
	return regione;
}

std::string Vino::regioneToString() const {
	switch (regione) {
		case Vino::Emilia:
			return "Emilia";
			break;
		case Vino::Veneto:
			return "Veneto";
			break;
		case Vino::Friuli:
			return "Friuli";
			break;
		case Vino::Toscana:
			return "Toscana";
			break;
		default:
			break;
	}
}
	
int Vino::getAnnoProduzione() const {
	return annoProduzione;
}

double Vino::getLitri() const {
	return litri;
}

double Vino::getGradazioneAlcolica()  const {
	return gradazioneAlcolica;
}

void Vino::setBarCode(const std::string& barCodeVino) {
	if(barCodeVino != "")
		barCode = barCodeVino;
}

void Vino::setPrezzoNetto(const double& prezzoNettoVino) {
	if(prezzoNettoVino >= 0)
		prezzoNetto = prezzoNettoVino;
}

void Vino::setRegione(const Regione& regioneVino) {
	regione = regioneVino;
}

void Vino::setAnnoProduzione(const int& annoProduzioneVino) {
	if(annoProduzioneVino >= 0)
		annoProduzione = annoProduzioneVino;
}

void Vino::setLitri(const double& litriVino) {
	if(litriVino >= 0)
		litri = litriVino;
}

void Vino::setGradazioneAlcolica(const double& gradazioneAlcolicaVino) {
	if(gradazioneAlcolicaVino >= 0)
		gradazioneAlcolica = gradazioneAlcolicaVino;
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
	vino["Regione"] = regioneToString();
	vino["Anno"] = getAnnoProduzione();
	vino["Litri"] = getLitri();
	vino["Gradazione"] = getGradazioneAlcolica();
	
	root["items"].append(vino);		
}

bool Vino::operator==(const Vino& prod) const {
	return Bevanda::operator==(prod)
		&& prod.prezzoNetto == prezzoNetto
		&& prod.barCode == barCode
		&& prod.regione == regione
		&& prod.annoProduzione == annoProduzione
		&& prod.litri == litri
		&& prod.gradazioneAlcolica == gradazioneAlcolica;
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
	Regione regioneVino = stringToRegione(root["Regione"].asString());
	int annoProduzioneVino = root["Anno"].asInt();
	double litriVino = root["Litri"].asDouble();
	double gradazioneAlcolicaVino = root["Gradazione"].asDouble();
	
	return new Vino(nomeProdotto, carboidratiBevanda, proteineBevanda, grassiBevanda, prezzoNettoVino, barCodeVino, regioneVino, gradazioneAlcolicaVino, litriVino, annoProduzioneVino, isAlcoholicBevanda, scadenzaProdotto, etaMinimaProdotto);
}
	
Vino::Regione Vino::stringToRegione(const std::string& regioneString) {
	if(regioneString == "Veneto")
		return Regione::Veneto;
	else if(regioneString == "Emilia")
		return Regione::Emilia;
	else if(regioneString == "Friuli")
		return Regione::Friuli;
	else if(regioneString == "Toscana")
		return Regione::Toscana;
}
	
