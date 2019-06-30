#include "jsonio.h"

JsonIO::JsonIO(const std::string& file) : path(file) {}
	
Qontainer<SmartPtr<Prodotto>> JsonIO::read() const {
	Qontainer<SmartPtr<Prodotto>> prodotti;
	
	std::ifstream ifs;
	ifs.open(path, std::ios::in);
	if(ifs.fail()){
		std::cout << "Errore apertura file" << std::endl;
		return prodotti;
	 }
	
    Json::Reader reader;
	Json::Value root; 

    reader.parse(ifs,root);

    for(int i = 0; i < root["items"].size(); i++)
		prodotti.push_back(Prodotto::unserialize(root["items"][i]));
	
	ifs.close();
}

void JsonIO::write(const Qontainer<SmartPtr<Prodotto>>& prodotti) const {
	Json::Value root;
	
	auto it = prodotti.begin();
	for(; it != prodotti.end(); it++)
		(*it)->serialize(root);
	
	Json::StreamWriterBuilder builder;
	std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	
	std::ofstream os;
	os.open(path, std::ios::in | std::ios::trunc);
	if(os.fail()){
		std::cout << "Errore apertura file" << std::endl;
	}
	
	writer->write(root, &os);
	
	os.close();
}
