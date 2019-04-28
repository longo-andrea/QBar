#include "Prodotto.h"

Prodotto::Prodotto(std::string nomeProdotto, int scadenzaProdotto, int etaMinimaProdotto) : nome(nomeProdotto), scadenza(scadenzaProdotto >= 2018 ? scadenzaProdotto : 2018 ), etaMinima(etaMinimaProdotto >= 14 ? etaMinimaProdotto : 14) {}

Prodotto::Prodotto(const Prodotto& prod) : nome(prod.getNome()), scadenza(prod.getScadenza()), etaMinima(prod.getEtaMinima()) {}

std::string Prodotto::getNome() const {
	return nome;
}

int Prodotto::getScadenza() const {
	return scadenza;
}

int Prodotto::getEtaMinima() const {
	return etaMinima;
}

void Prodotto::setNomeProdotto(const std::string& nomeProdotto) {
	if (nomeProdotto != "")
		nome = nomeProdotto;
}

void Prodotto::setScadenza(const int& scadenzaProdotto) {
	if(scadenzaProdotto >= 2018)
		scadenza = scadenzaProdotto;
}

void Prodotto::setEtaMinima(const int& etaMinimaProdotto) {
	if (etaMinimaProdotto >= 14)
		etaMinima = etaMinimaProdotto;
}

bool Prodotto::operator==(const Prodotto& prod) const {
	return this->nome == prod.nome &&
		this->scadenza == prod.scadenza &&
		this->etaMinima == prod.etaMinima;
}

bool Prodotto::operator!=(const Prodotto& prod) const {
	return !(*this == prod);
}