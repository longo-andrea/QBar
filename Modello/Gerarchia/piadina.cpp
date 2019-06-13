#include "piadina.h"

Piadina::inizializzaPiadina::inizializzaPiadina() {
	ptr = new Piadina();
	mappaProdotto[ptr->getTipo()] = ptr;
}

Piadina::inizializzaPiadina::~inizializzaPiadina() {
	delete ptr;
}

Piadina::inizializzaPiadina Piadina::mappaPiadina;

double Piadina::tassa = 0.30;

Piadina::Piadina(const std::string& nomeProdotto, double carboidratiCibo, double proteineCibo, double grassiCibo, double prezzoPreparazionePiadina, bool isVeganCibo, const std::string& barCodePiadina, Impasto impastoPiadina, int scadenzaProdotto, int etaMinimaProdotto) 
	: Cibo(nomeProdotto, carboidratiCibo, proteineCibo, grassiCibo, isVeganCibo, scadenzaProdotto, etaMinimaProdotto), prezzoPreparazione(prezzoPreparazionePiadina >= 0 ? prezzoPreparazionePiadina : 0), barCode(barCodePiadina), impasto(impastoPiadina) {}
	
Piadina::Piadina(const Piadina& piadina) : Cibo(piadina), prezzoPreparazione(piadina.prezzoPreparazione), barCode(piadina.barCode), impasto(piadina.impasto) {}

Piadina* Piadina::clone() const {
	return new Piadina(*this);
}

double Piadina::getPrezzoPreparazione() const {
	return prezzoPreparazione;
}

std::string Piadina::getBarCode() const {
	return barCode;
}
double Piadina::getPrezzo() const {
	return prezzoPreparazione + tassa;
}

std::string Piadina::getTipo() const {
	return "Piadina";
}

Piadina::Impasto Piadina::getImpasto() const {
	return impasto;
}

std::string Piadina::impastoToString() const {
	switch (impasto) {
		case Piadina::Classico:
			return "Classico";
			break;
		case Piadina::Cereali:
			return "Cereali";
			break;
		case Piadina::Integrale:
			return "Integrale";
			break;
		case Piadina::Kamut:
			return "Kamut";
			break;
		default:
			break;
	}
}

void Piadina::setPrezzoPreparazione(const double& prezzoPreparazionePiadina) {
	if (prezzoPreparazionePiadina >= 0)
		prezzoPreparazione = prezzoPreparazionePiadina;
}
void Piadina::setBarCode(const std::string& barCodePiadina) {
	if (barCodePiadina != "")
		barCode = barCodePiadina;
}

void Piadina::setImpasto(Piadina::Impasto impastoPiadina) {
	impasto = impastoPiadina;
}

void Piadina::serialize(Json::Value& root) const {
	Json::Value piadina;
	
	piadina["Tipo"] = getTipo();
	
	piadina["Nome"] = getNome();
	piadina["Scadenza"] = getScadenza();
	piadina["Eta minima"] = getEtaMinima();
	
	piadina["Carboidrati"] = getCarboidrati();
	piadina["Proteine"] = getProteine();
	piadina["Grassi"] = getGrassi();
	piadina["Vegano"] = isVegan();

	piadina["Prezzo preparazione"] = getPrezzoPreparazione();
	piadina["Bar Code"] = getBarCode();
	piadina["Impasto"] = impastoToString();
	
	root["items"].append(piadina);	
}

bool Piadina::operator==(const Piadina& prod) const {
	return Cibo::operator==(prod)
		&& prod.prezzoPreparazione == prezzoPreparazione
		&& prod.barCode == barCode
		&& prod.impasto == impasto;
}

bool Piadina::operator!=(const Piadina& prod) const {
	return !(*this == prod);
}

/* ----- PRIVATE METHODS ----- */

Piadina* Piadina::create(Json::Value& root) const {
	std::string nomeProdotto = root["Nome"].asString();
	int scadenzaProdotto = root["Scandeza"].asInt();
	int etaMinimaProdotto = root["Eta minima"].asInt();
	
	double carboidratiCibo = root["Carboidrati"].asDouble();
	double proteineCibo = root["Proteine"].asDouble();
	double grassiCibo = root["Grassi"].asDouble();
	bool isVeganCibo = root["Vegano"].asBool();

	double prezzoPreparazionePiadina = root["Prezzo preparazione"].asDouble();
	std::string barCodePiadina = root["Bar Code"].asString();
	Impasto impastoPiadina = stringToImpasto(root["Impasto"].asString());
	
	return new Piadina(nomeProdotto, carboidratiCibo, proteineCibo, grassiCibo, prezzoPreparazionePiadina, isVeganCibo, barCodePiadina, impastoPiadina, scadenzaProdotto, etaMinimaProdotto); 
}
	
Piadina::Impasto Piadina::stringToImpasto(const std::string& impastoString) {
	if(impastoString == "Classico")
		return Impasto::Classico;
	else if(impastoString == "Cereali")
		return Impasto::Cereali;
	else if(impastoString == "Integrale")
		return Impasto::Integrale;
	else if(impastoString == "Kamut")
		return Impasto::Kamut;
}
