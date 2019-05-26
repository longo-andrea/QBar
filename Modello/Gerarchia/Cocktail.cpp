#include "Cocktail.h"

double Cocktail::tassa = 0.70;

Cocktail::Cocktail(std::string nomeProdotto, double carboidratiBevada, double proteineBevanda, double grassiBevanda, double prezzoNettoCocktail, std::string barCodeCocktail, Quantita quantitaCocktail, Classificazione famigliaCocktail, double gradazioneAlcolicaCocktail, bool alcoholicBevanda, int scadenzaProdotto, int etaMinimaProdotto) 
	: Bevanda(nomeProdotto, carboidratiBevada, proteineBevanda, grassiBevanda, alcoholicBevanda, scadenzaProdotto, etaMinimaProdotto), prezzoNetto(prezzoNettoCocktail >= 0 ? prezzoNettoCocktail : 0), barCode(barCodeCocktail), quantita(quantitaCocktail), famiglia(famigliaCocktail), gradazioneAlcolica(gradazioneAlcolicaCocktail >= 0 ? gradazioneAlcolicaCocktail : 0) {}

Cocktail::Cocktail(const Cocktail& cocktail) : Bevanda(cocktail), prezzoNetto(cocktail.prezzoNetto), barCode(cocktail.barCode), quantita(cocktail.quantita), famiglia(cocktail.famiglia), gradazioneAlcolica(cocktail.gradazioneAlcolica) {}

Cocktail* Cocktail::clone() const {
	return new Cocktail(*this);
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
		case Cocktail::Analcolico:
			return "Analcolico";
			break;
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

std::string Cocktail::getBarCode() const {
	return barCode;
}

double Cocktail::getPrezzo() const {
	return prezzoNetto + tassa;
}

double Cocktail::calcolaCalorie() const {
	return Bevanda::calcolaCalorie() + gradazioneAlcolica * valoreEnergeticoAlcol;
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