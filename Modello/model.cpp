#include "model.h"

Model::Model() : file("../json/Data.json")  {}
	
void Model::save() {
	
	Briosche brio("Nutella", 25, 25, 26, 45, true, "AAAA", Briosche::Classico, Briosche::Cornetto, Briosche::Cioccolato, 2020, 14);
	Piadina brio2("Mortazza", 25, 25, 26, 45, true, "AAAA", Piadina::Integrale, 2020, 14);
	Analcolico anal("Cola", 25, 25, 26, 45, "AAAA", Analcolico::Diet, Analcolico::Lattina, 2.50);
	
	qb.push_back(&brio);
	qb.push_back(&brio2);
	qb.push_back(&anal);
	
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

void Model::load() const {}
