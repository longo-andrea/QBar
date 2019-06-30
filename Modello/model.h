#ifndef MODEL_H
#define MODEL_H

// INCLUDE DA SISTEMARE !!!!!!!!!!!!
#include "Gerarchia/brioche.h"
#include "Gerarchia/vino.h"
#include "Gerarchia/smartptr.h"
#include "../Qontainer/Qontainer.h"
#include <ostream>
#include <fstream>
#include "json/json.h"
#include "jsonio.h"

class Model{
private:
	Qontainer<SmartPtr<Prodotto>> prodotti;
	
public:
	Model() = default;
	
	void save(const std::string&) const;
	void load(const std::string&);
	
	void add(Prodotto*); 
    void remove(Prodotto*);
    Prodotto* operator[](unsigned int) const;

    int count() const;
	
};


#endif // MODEL_H
