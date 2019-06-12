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
	prodotti.push_back(prod);
}
    
		
	
	
	/*
void Model::save() {
	
	Brioche brio("Nutella", 25, 25, 26, 45, true, "AAAA", Brioche::Classico, Brioche::Cornetto, Brioche::Cioccolato, 2020, 14);
	Vino wine("Egiziano", 25, 36, 45, 55, 8.50, 8, "A56F", 5, Vino::Friuli);
	Vino wine2("Secondo", 25, 36, 45, 55, 8.50, 8, "A56F", 5, Vino::Friuli);
	Vino wine3("Terzo", 25, 36, 45, 55, 8.50, 8, "A56F", 5, Vino::Friuli);
	
	qb.push_back(&brio);
	qb.push_back(&wine);
	qb.push_back(&wine2);
	qb.push_back(&wine3);

	Json::Value root;
	
	auto it = qb.begin();
	for(; it!=qb.end(); it++)
		(*it)->serialize(root);
	
	Json::StreamWriterBuilder builder;
	std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	
	std::ofstream os;
	os.open(file, std::ios::in | std::ios::trunc);
	
	writer->write(root, &os);
	
	os.close();
	
}
*/
