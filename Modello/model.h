#ifndef MODEL_H
#define MODEL_H

#include "Gerarchia/briosche.h"
#include "Gerarchia/piadina.h"
#include "Gerarchia/analcolico.h"
#include "Gerarchia/smartptr.h"
#include "../Qontainer/Qontainer.h"
#include <ostream>
#include <fstream>
#include "json/json.h"

class Model{
private:
	Qontainer<Prodotto*> qb;
	std::string file; 
public:
	Model();
	
	void save();
	void load() const;
	
};


#endif // MODEL_H
