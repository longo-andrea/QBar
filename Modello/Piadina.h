#ifndef PIADINA_H
#define PIADINA_H

#include "Cibo.h"
#include <iostream>

class Piadina : public Cibo {
public:
	enum Impasto { Classico, Cereali, Integrale, Kamut };
private:
	static double tassa;

	double prezzoPreparazione;
	std::string barCode;
	Impasto impasto;

public:
	Piadina(std::string, double, double, double, double, std::string, Impasto, int = 2020, int = 14);
	Piadina(const Piadina&);
	Piadina& operator=(const Piadina&);
	virtual ~Piadina() =default;
		
	double getPrezzoPreparazione() const override;
	std::string getBarCode() const override;
	double getPrezzo() const override;
	Impasto getImpasto() const;
	std::string impastoToString() const;

	void setTassa(const double&);
	void setPrezzoPreparazione(const double&);
	void setBarCode(const std::string&);
	void setImpasto(Impasto);

	virtual bool operator==(const Piadina&) const;
	virtual bool operator!=(const Piadina&) const;

};

#endif // !PIADINA_H
