#include "Prodotto.h"

Prodotto::Prodotto(std::string nomeProdotto, int scadenzaProdotto, int etaMinimaProdotto) : nome(nomeProdotto), scadenza(scadenzaProdotto >= 2019 ? scadenzaProdotto : 2019), etaMinima(etaMinimaProdotto >= 14 ? etaMinimaProdotto : 14) {}

Prodotto::Prodotto(const Prodotto& prod) : nome(prod.nome), scadenza(prod.scadenza), etaMinima(prod.etaMinima) {}

std::string Prodotto::getNome() const {
	return nome;
}

int Prodotto::getScadenza() const {
	return scadenza;
}

int Prodotto::getEtaMinima() const {
	return etaMinima;
}

void Prodotto::setNome(const std::string& nomeProdotto) {
	if (nomeProdotto != "")
		nome = nomeProdotto;
}

void Prodotto::setScadenza(const int& scadenzaProdotto) {
	if(scadenzaProdotto >= 2019)
		scadenza = scadenzaProdotto;
}

void Prodotto::setEtaMinima(const int& etaMinimaProdotto) {
	if (etaMinimaProdotto >= 0)
		etaMinima = etaMinimaProdotto;
}

bool Prodotto::operator==(const Prodotto& prod) const {
	return nome == prod.nome &&
		scadenza == prod.scadenza &&
		etaMinima == prod.etaMinima;
}

bool Prodotto::operator!=(const Prodotto& prod) const {
	return !(*this == prod);
}
