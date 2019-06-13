#include "cocktail.h"

Cocktail::inizializzaCocktail::inizializzaCocktail() {
	ptr = new Cocktail();
	mappaProdotto[ptr->getTipo()] = ptr;
}

Cocktail::inizializzaCocktail::~inizializzaCocktail() {
	delete ptr;
}

Cocktail::inizializzaCocktail Cocktail::mappaCocktail;

double Cocktail::tassa = 0.70;

Cocktail::Cocktail(const std::string& nomeProdotto, double carboidratiBevada, double proteineBevanda, double grassiBevanda, double prezzoNettoCocktail, const std::string& barCodeCocktail, Quantita quantitaCocktail, Classificazione famigliaCocktail, double gradazioneAlcolicaCocktail, bool alcoholicBevanda, int scadenzaProdotto, int etaMinimaProdotto) 
	: Bevanda(nomeProdotto, carboidratiBevada, proteineBevanda, grassiBevanda, alcoholicBevanda, scadenzaProdotto, etaMinimaProdotto), prezzoNetto(prezzoNettoCocktail >= 0 ? prezzoNettoCocktail : 0), barCode(barCodeCocktail), quantita(quantitaCocktail), famiglia(famigliaCocktail), gradazioneAlcolica(gradazioneAlcolicaCocktail >= 0 ? gradazioneAlcolicaCocktail : 0) {}

Cocktail::Cocktail(const Cocktail& cocktail) : Bevanda(cocktail), prezzoNetto(cocktail.prezzoNetto), barCode(cocktail.barCode), quantita(cocktail.quantita), famiglia(cocktail.famiglia), gradazioneAlcolica(cocktail.gradazioneAlcolica) {}

Cocktail* Cocktail::clone() const {
	return new Cocktail(*this);
}

std::string Cocktail::getBarCode() const {
	return barCode;
}

double Cocktail::getPrezzo() const {
	return prezzoNetto + tassa;
}

double Cocktail::calcolaCalorie() const {
	return Bevanda::calcolaCalorie() + gradazioneAlcolica * valoreEnergeticoAlcol;
}

std::string Cocktail::getTipo() const {
	return "Cocktail";
}

double Cocktail::getPrezzoNetto() const {
	return prezzoNetto;
}

Cocktail::Quantita Cocktail::getQuantita() const {
	return quantita;
}

std::string Cocktail::quantitaToString() const {
	switch (quantita) {
		case Cocktail::Short:
			return "Short";
			break;
		case Cocktail::Medium:
			return "Medium";
			break;
		case Cocktail::Long:
			return "Long";
			break;
		default:
			break;
	}
}

Cocktail::Classificazione Cocktail::getFamiglia() const {
	return famiglia;
}

std::string Cocktail::famigliaToString() const {
	switch (famiglia) {
		case Cocktail::Coffe:
			return "Coffe";
			break;
		case Cocktail::Cooler:
			return "Cooler";
			break;
		case Cocktail::Exotic:
			return "Exotic";
			break;
		case Cocktail::Wine:
			return "Wine";
			break;
		default:
			break;
	}
}

double Cocktail::getGradazioneAlcolica() const {
	return gradazioneAlcolica;
}

void Cocktail::setPrezzoNetto(const double& prezzoNettoCocktail) {
	if (prezzoNettoCocktail >= 0)
		prezzoNetto = prezzoNettoCocktail;
}

void Cocktail::setQuantita(const Quantita& quantitaCocktail) {
	quantita = quantitaCocktail;
}

void Cocktail::setFamiglia(const Classificazione& famigliaCocktail) {
	famiglia = famigliaCocktail;
}

void Cocktail::setGradazioneAlcolica(const double& gradazioneAlcolicaCocktail) {
	if (gradazioneAlcolicaCocktail >= 0)
		gradazioneAlcolica = gradazioneAlcolicaCocktail;
}

void Cocktail::setBarCode(const std::string& barCodeCocktail) {
	if (barCodeCocktail != "")
		barCode = barCodeCocktail;
}

void Cocktail::serialize(Json::Value& root) const {
	Json::Value cocktail;
	
	cocktail["Tipo"] = getTipo();
	
	cocktail["Nome"] = getNome();
	cocktail["Scadenza"] = getScadenza();
	cocktail["Eta minima"] = getEtaMinima();
	
	cocktail["Carboidrati"] = getCarboidrati();
	cocktail["Proteine"] = getProteine();
	cocktail["Grassi"] = getGrassi();
	cocktail["Alcolico"] = isAlcoholic();
	
	cocktail["Prezzo netto"] = getPrezzoNetto();
	cocktail["Bar Code"] = getBarCode();
	cocktail["Quantita"] = quantitaToString();
	cocktail["Famiglia"] = famigliaToString();
	cocktail["Gradazione"] = getGradazioneAlcolica();
	
	root["items"].append(cocktail);			
}

bool Cocktail::operator==(const Cocktail& prod) const {
	return Bevanda::operator==(prod)
		&& prod.prezzoNetto == prezzoNetto
		&& prod.barCode == barCode
		&& prod.quantita == quantita
		&& prod.famiglia == famiglia
		&& prod.gradazioneAlcolica == gradazioneAlcolica;
}

bool Cocktail::operator!=(const Cocktail& prod) const {
	return !(*this == prod);
}

/* ----- PRIVATE METHODS ----- */

Cocktail* Cocktail::create(Json::Value& root) const {
	std::string nomeProdotto = root["Nome"].asString();
	int scadenzaProdotto = root["Scandeza"].asInt();
	int etaMinimaProdotto = root["Eta minima"].asInt();
	
	double carboidratiBevanda = root["Carboidrati"].asDouble();
	double proteineBevanda = root["Proteine"].asDouble();
	double grassiBevanda = root["Grassi"].asDouble();
	bool isAlcoholicBevanda = root["Alcolico"].asBool();

	double prezzoNettoCocktail = root["Prezzo netto"].asDouble();
	std::string barCodeCocktail = root["Bar Code"].asString();
	Quantita quantitaCocktail = stringToQuantita(root["Quantita"].asString());
	Classificazione famigliaCocktail = stringToClassificazione(root["Famiglia"].asString());
	double gradazioneAlcolicaCocktail = root["Gradazione"].asDouble();
	
	return new Cocktail(nomeProdotto, carboidratiBevanda, proteineBevanda, grassiBevanda, prezzoNettoCocktail, barCodeCocktail, quantitaCocktail, famigliaCocktail, gradazioneAlcolicaCocktail, isAlcoholicBevanda, scadenzaProdotto, etaMinimaProdotto);
}
	
Cocktail::Quantita Cocktail::stringToQuantita(const std::string& quantitaString) {
	if(quantitaString == "Short")
		return Quantita::Short;
	else if(quantitaString == "Medium")
		return Quantita::Medium;
	else if(quantitaString == "Long")
		return Quantita::Long;
}
	
Cocktail::Classificazione Cocktail::stringToClassificazione(const std::string& classificazioneString) {
	if(classificazioneString == "Coffe")
		return Classificazione::Coffe;
	else if(classificazioneString == "Cooler")
		return Classificazione::Cooler;
	else if(classificazioneString == "Exotic")
		return Classificazione::Exotic;
	else if(classificazioneString == "Wine")
		return Classificazione::Wine;
}

