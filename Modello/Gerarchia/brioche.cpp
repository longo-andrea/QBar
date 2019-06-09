#include "brioche.h"

Brioche::inizializzaBrioche::inizializzaBrioche() {
	ptr = new Brioche();
	mappaProdotto[ptr->getTipo()] = ptr;
}

Brioche::inizializzaBrioche::~inizializzaBrioche() {
	delete ptr;
}

Brioche::inizializzaBrioche Brioche::mappaBrioche;

double Brioche::tassa = 0.10;

Brioche::Brioche(const std::string& nomeProdotto, double carboidratiCibo, double proteineCibo, double grassiCibo, double prezzoPreparazioneBrioche, bool isVeganCibo, const std::string& barCodeBrioche, Impasto impastoBrioche, Forma formaBrioche, Ripieno ripienoBrioche, int scadenzaProdotto, int etaMinimaProdotto) 
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

/* ----- PRIVATE METHODS ----- */

Brioche* Brioche::create(Json::Value& root) const {
	std::string nomeProdotto = root["Nome"].asString();
	int scadenzaProdotto = root["Scandeza"].asInt();
	int etaMinimaProdotto = root["Eta minima"].asInt();
	
	double carboidratiCibo = root["Carboidrati"].asDouble();
	double proteineCibo = root["Proteine"].asDouble();
	double grassiCibo = root["Grassi"].asDouble();
	bool isVeganCibo = root["Vegano"].asBool();

	double prezzoPreparazioneBrioche = root["Prezzo preparazione"].asDouble();
	std::string barCodeBrioche = root["Bar Code"].asString();
	Impasto impastoBriosche = stringToImpasto(root["Impasto"].asString());
	Forma formaBriosche = stringToForma(root["Forma"].asString());
	Ripieno ripienoBriosche = stringToRipieno(root["Ripieno"].asString());
	
	return new Brioche(nomeProdotto, carboidratiCibo, proteineCibo, grassiCibo, prezzoPreparazioneBrioche, isVeganCibo, barCodeBrioche);/*, impastoBriosche, formaBriosche, ripienoBriosche, scadenzaProdotto, etaMinimaProdotto); */
}
	
Brioche::Impasto Brioche::stringToImpasto(const std::string& impastoString) {
	if(impastoString == "Classico")
		return Impasto::Classico;
	else if(impastoString == "Integrale")
		return Impasto::Integrale;
	else if(impastoString == "Senza Glutine")
		return Impasto::SenzaGlutine;
}
	
Brioche::Forma Brioche::stringToForma(const std::string& formaString) {
	if(formaString == "Cornetto")
		return Forma::Cornetto;
	else if(formaString == "Girella")
		return Forma::Girella;
	else if(formaString == "Ciambella")
		return Forma::Ciambella;
}

Brioche::Ripieno Brioche::stringToRipieno(const std::string& ripienoString) {
	if(ripienoString == "Vuota")
		return Ripieno::Vuota;
	else if(ripienoString == "Cioccolata")
		return Ripieno::Cioccolato;
	else if(ripienoString == "Marmellata")
		return Ripieno::Marmellata;
	else if(ripienoString == "Crema")
		return Ripieno::Crema;
}
