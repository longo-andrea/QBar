#ifndef MODEL_H
#define MODEL_H

#include "Gerarchia/prodotto.h"
#include "Gerarchia/smartptr.h"
#include "../Qontainer/Qontainer.h"
#include "jsonio.h"

class Model{
private:
	Qontainer<SmartPtr<Prodotto>> prodotti;
	
public:
	Model() = default;
	
	void save(const std::string&) const;
	void load(const std::string&);
	
	void add(Prodotto*); 
    void remove(int i);

    int getIndexNome(std::string, int=0) const;
    int getIndexTipo(std::string, int=0) const;
    int getIndexScadenza(int, int=0) const;
    int getIndexEtaMinima(int, int=0) const;

    Prodotto* operator[](unsigned int) const;

    int count() const;
	
};


#endif // MODEL_H
