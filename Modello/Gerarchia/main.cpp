#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <ostream>

#include "../model.h"
#include "../json/json.h"
#include "prodotto.h"
#include "brioche.h"

using namespace std;

int main(int argc, char **argv)
{
	//Model mod;
	
	//mod.save();


	Json::Reader rd;
	Json::Value root;
	std::ifstream is;
	is.open("../json/Data.json", std::ios::in);
	
	rd.parse(is,root);
	
	//Briosche br("Nutella", 25, 25, 26, 45, true, "AAAA", Briosche::Classico, Briosche::Cornetto, Briosche::Cioccolato, 2020, 14);
	//Briosche* br2 = br.create(root);
	
	Brioche* br = dynamic_cast<Brioche*>(Prodotto::unserialize(root));

	
	cout << br->getNome();
	cout << br->getBarCode() << endl;
	
	is.close();


	
/*
	std::ifstream prova("output.json", std::ifstream::binary);
	Json::Value root;
	Json::Reader reader;
	
	bool parsedSuccess = reader.parse(prova, root, false);
	if(!parsedSuccess) {
		cout<<"Failed to parse JSON"<< endl << reader.getFormatedErrorMessages() << endl;
		return 1;
	}
	
	const Json::Value& prodotto = root["Prodotto"]; 
	std::cout << prodotto[0]["nome"].asString();
	
*/

}
