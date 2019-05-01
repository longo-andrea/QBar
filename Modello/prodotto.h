#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <string>
#include <iostream>

class Prodotto {
private:
	std::string nome;
	unsigned int scadenza;
	unsigned int etaMinima;

public:
	Prodotto(std::string, int =2020, int =14);
	Prodotto(const Prodotto&);
	virtual Prodotto* clone() const = 0;
	virtual ~Prodotto() = default;

	std::string getNome() const;
	int getScadenza() const;
	int getEtaMinima() const;
	virtual std::string getBarCode() const = 0;
	virtual double getPrezzo() const = 0;

	void setNome(const std::string&);
	void setScadenza(const int&);
	void setEtaMinima(const int&);

	virtual bool operator==(const Prodotto&) const;
	virtual bool operator!=(const Prodotto&) const;
};


#endif // !PRODOTTO_H


