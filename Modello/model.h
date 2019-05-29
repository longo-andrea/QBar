#ifndef MODEL_H
#define MODEL_H

#include "Gerarchia/Prodotto.h"
#include "Gerarchia/SmartPtr.h"
#include "../Qontainer/Qontainer.h"
#include <iostream>

class Model{
private:
	Qontainer<SmartPtr<Vino>> item;
	std::string path;
	
public:	
	Model();
	~Model() = default;
	
	void save() const;
	void load();
	
	void add(Prodotto*);
	void remove(int);
	
};


#endif // MODEL_H
