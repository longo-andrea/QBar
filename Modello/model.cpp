#include "model.h"

Model::Model() : file("../json/Data.json")  {}
	
void Model::save() {
	
	Brioche brio("Nutella", 25, 25, 26, 45, true, "AAAA", Brioche::Classico, Brioche::Cornetto, Brioche::Cioccolato, 2020, 14);
	Brioche brio2("Nuttti", 25, 25, 26, 45, true, "AAAA", Brioche::Classico, Brioche::Cornetto, Brioche::Cioccolato, 2020, 14);

	
	qb.push_back(&brio);
	qb.push_back(&brio2);

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

void Model::load() const {

}
