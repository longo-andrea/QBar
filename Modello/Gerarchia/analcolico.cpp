#include "analcolico.h"

Analcolico::inizializzaAnalcolico::inizializzaAnalcolico() {
	ptr = new Analcolico();
	mappaProdotto[ptr->getTipo()] = ptr;
}

Analcolico::inizializzaAnalcolico::~inizializzaAnalcolico() {
	delete ptr;
}

Analcolico::inizializzaAnalcolico Analcolico::mappaAnalcolico;

double Analcolico::tassa = 0.50;

Analcolico::Analcolico(const std::string& nomeProdotto, double carboidratiBevanda, double proteineBevanda, double grassiBevanda, double prezzoNettoAnalcolico, const std::string& barCodeAnalcolico, Variante varianteAnalcolico, Contenitore contenitoreAnalcolico, double litriAnalcolico, bool isAlcoholicBevanda, int scadenzaProdotto, int etaMinimaProdotto)
	: Bevanda(nomeProdotto, carboidratiBevanda, proteineBevanda, grassiBevanda, isAlcoholicBevanda, scadenzaProdotto, etaMinimaProdotto), prezzoNetto(prezzoNettoAnalcolico >= 0 ? prezzoNettoAnalcolico : 0), barCode(barCodeAnalcolico), variante(varianteAnalcolico), contenitore(contenitoreAnalcolico), litri(litriAnalcolico >=0 ? litriAnalcolico : 0) {}

Analcolico::Analcolico(const Analcolico& analcolico) : Bevanda(analcolico), prezzoNetto(analcolico.prezzoNetto), barCode(analcolico.barCode), variante(analcolico.variante), contenitore(analcolico.contenitore), litri(analcolico.litri) {}

Analcolico* Analcolico::clone() const {
	return new Analcolico(*this);
}

double Analcolico::getPrezzo() const {
	return prezzoNetto + tassa;
}

std::string Analcolico::getBarCode() const {
	return barCode;
}

std::string Analcolico::getTipo() const {
	return "Analcolico";
}

double Analcolico::getPrezzoNetto() const {
	return prezzoNetto;
}

Analcolico::Variante Analcolico::getVariante() const {
	return variante;
}

std::string Analcolico::varianteToString() const {
	switch (variante) {
		case Analcolico::Classica:
			return "Classica";
			break;
		case Analcolico::Zero:
			return "Zero";
			break;
		case Analcolico::Light:
			return "Light";
			break;
		case Analcolico::Diet:
			return "Diet";
			break;
		default:
			break;
	}
}

Analcolico::Contenitore Analcolico::getContenitore() const {
	return contenitore;
}

std::string Analcolico::contenitoreToString() const {
	switch (contenitore) {
		case Analcolico::Lattina:
			return "Lattina";
			break;
		case Analcolico::Bottiglia:
			return "Bottiglia";
			break;
		case Analcolico::Spina:
			return "Spina";
			break;
		default:
			break;
	}
}

double Analcolico::getLitri() const {
	return litri;
}

void Analcolico::setTassa(const double& tassaAnalcolico) {
	if (tassaAnalcolico >= 0)
		tassa = tassaAnalcolico;
}

void Analcolico::setPrezzoNetto(const double& prezzoNettoAnalcolico) {
	if (prezzoNettoAnalcolico >= 0)
		prezzoNetto = prezzoNettoAnalcolico;
}

void Analcolico::setBarCode(const std::string& barCodeAnalcolico) {
	if (barCodeAnalcolico != "")
		barCode = barCodeAnalcolico;
}

void Analcolico::setVariante(const Variante& varianteAnalcolico) {
	variante = varianteAnalcolico;
}

void Analcolico::setContenitore(const Contenitore& contenitoreAnalcolico) {
	contenitore = contenitoreAnalcolico;
}

void Analcolico::setLitri(const double& litriAnalcolico) {
	if (litriAnalcolico >= 0)
		litri = litriAnalcolico;
}

void Analcolico::serialize(Json::Value& root) const {
	Json::Value analcolico;
	
	analcolico["Tipo"] = getTipo();
	
	analcolico["Nome"] = getNome();
	analcolico["Scadenza"] = getScadenza();
	analcolico["Eta minima"] = getEtaMinima();
	
	analcolico["Carboidrati"] = getCarboidrati();
	analcolico["Proteine"] = getProteine();
	analcolico["Grassi"] = getGrassi();
	analcolico["Alcolico"] = isAlcoholic();
	
	analcolico["Prezzo netto"] = getPrezzoNetto();
	analcolico["Bar Code"] = getBarCode();
	analcolico["Variante"] = varianteToString();
	analcolico["Contenitore"] = contenitoreToString();
	analcolico["Litri"] = getLitri();
	
	root["items"].append(analcolico);		
}

bool Analcolico::operator==(const Analcolico& prod) const {
	return Bevanda::operator==(prod)
		&& prod.prezzoNetto == prezzoNetto
		&& prod.barCode == barCode
		&& prod.variante == variante
		&& prod.contenitore == contenitore
		&& prod.litri == litri;
}

bool Analcolico::operator!=(const Analcolico& prod) const {
	return !(*this == prod);
}

/* ----- PRIVATE METHODS ----- */

Analcolico* Analcolico::create(Json::Value& root) const {
	std::string nomeProdotto = root["Nome"].asString();
	int scadenzaProdotto = root["Scandeza"].asInt();
	int etaMinimaProdotto = root["Eta minima"].asInt();
	
	double carboidratiBevanda = root["Carboidrati"].asDouble();
	double proteineBevanda = root["Proteine"].asDouble();
	double grassiBevanda = root["Grassi"].asDouble();
	bool isAlcoholicBevanda = root["Alcolico"].asBool();

	double prezzoNettoAnalcolico = root["Prezzo netto"].asDouble();
	std::string barCodeAnalcolico = root["Bar Code"].asString();
	int litriAnalcolico = root["Litri"].asDouble();
	Variante varianteAnalcolico = stringToVariante(root["Variante"].asString());
	Contenitore contenitoreAnalcolico = stringToContenitore(root["Contenitore"].asString());
	
	return new Analcolico(nomeProdotto, carboidratiBevanda, proteineBevanda, grassiBevanda, prezzoNettoAnalcolico, barCodeAnalcolico, varianteAnalcolico, contenitoreAnalcolico, litriAnalcolico, isAlcoholicBevanda, scadenzaProdotto, etaMinimaProdotto);
}
	
Analcolico::Variante Analcolico::stringToVariante(const std::string& varianteString) {
	if(varianteString == "Classica")
		return Variante::Classica;
	else if(varianteString == "Zero")
		return Variante::Zero;
	else if(varianteString == "Light")
		return Variante::Light;
	else if(varianteString == "Diet")
		return Variante::Diet;
}
	
Analcolico::Contenitore Analcolico::stringToContenitore(const std::string& contenitoreString) {
	if(contenitoreString == "Lattina")
		return Contenitore::Lattina;
	else if(contenitoreString == "Bottiglia")
		return Contenitore::Bottiglia;
	else if(contenitoreString == "Spina")
		return Contenitore::Spina;
}

