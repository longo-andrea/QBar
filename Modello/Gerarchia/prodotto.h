#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <string>

#include <iostream>
#include "../json/json.h"

class Prodotto {
private:
	std::string nome;
	unsigned int scadenza;
	unsigned int etaMinima;
	
	virtual Prodotto* create(Json::Value&) const = 0;
	
protected:
	static std::map<std::string,Prodotto*> mappaProdotto;

public:
	Prodotto(const std::string& ="No Name", int =2020, int =14);
	Prodotto(const Prodotto&);
	virtual Prodotto* clone() const = 0;
	virtual ~Prodotto() = default;

	std::string getNome() const;
	int getScadenza() const;
	int getEtaMinima() const;
	virtual std::string getBarCode() const = 0;
	virtual double getPrezzo() const = 0;
	virtual std::string getTipo() const = 0;

	void setNome(const std::string&);
	void setScadenza(const int&);
	void setEtaMinima(const int&);

	virtual void serialize(Json::Value&) const = 0;
	static Prodotto* unserialize(Json::Value&);

	virtual bool operator==(const Prodotto&) const;
	virtual bool operator!=(const Prodotto&) const;
	
};


#endif // !PRODOTTO_H


