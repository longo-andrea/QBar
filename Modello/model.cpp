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
    
Prodotto* Model::operator[](unsigned int index) const {
    return prodotti[index].operator->();
}

int Model::count() const {
    return prodotti.getSize();
}
