#include "model.h"

void Model::save(const std::string& file) const {
	JsonIO jsonio(file);
	jsonio.write(prodotti);
}

void Model::load(const std::string& file) {
	JsonIO jsonio(file);
	prodotti = jsonio.read();
}

void Model::add(Prodotto* prod) {
	prodotti.push_back(SmartPtr<Prodotto>(prod));
}

void Model::remove(int i) {
    prodotti.erase(prodotti.begin() + i);
}

int Model::getIndexNome(std::string nome, int from) const {
    int i = from;
    for(; i < count() && nome != prodotti[i]->getNome() ; i++);
    if(i == count()) return -1;
    return i;
}

int Model::getIndexTipo(std::string tipo, int from) const {
    int i = from;
    for(; i < count() && tipo != prodotti[i]->getTipo() ; i++);
    if(i == count()) return -1;
    return i;
}

int Model::getIndexScadenza(int scadenza, int from) const {
    int i = from;
    for(; i < count() && scadenza != prodotti[i]->getScadenza() ; i++);
    if(i == count()) return -1;
    return i;
}

int Model::getIndexEtaMinima(int eta, int from) const {
    int i = from;
    for(; i < count() && eta > prodotti[i]->getEtaMinima() ; i++);
    if(i == count()) return -1;
    return i;
}

Prodotto* Model::operator[](unsigned int index) const {
    return prodotti[index].operator->();
}

int Model::count() const {
    return prodotti.getSize();
}
