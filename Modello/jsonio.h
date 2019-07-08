#ifndef JSONIO_H
#define JSONIO_H

#include "Gerarchia/prodotto.h"
#include "Gerarchia/smartptr.h"
#include "../Qontainer/Qontainer.h"
#include <ostream>
#include <fstream>

class JsonIO {
private:
	std::string path;
public:
	JsonIO(const std::string& ="json/Data.json");
	
	Qontainer<SmartPtr<Prodotto>> read() const;
    void write(const Qontainer<SmartPtr<Prodotto>>&) const;
	
};



#endif // JSONIO_H
