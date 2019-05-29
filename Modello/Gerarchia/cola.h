#ifndef COLA_H
#define COLA_H

#include "bevanda.h"

class Cola : public Bevanda {
public:
	enum Tipo { Classica, Zero, Light, Diet, Stevia };
	enum Contenitore { Lattina, Bottiglia, Spina };
private:
	static double tassa;

	double prezzoNetto;
	std::string barCode;
	Tipo tipo;
	Contenitore contenitore;
	double litri;
public:
	Cola(std::string, double, double, double, double, std::string, Tipo, Contenitore, double, bool = false, int = 2020, int = 14);
	Cola(const Cola&);
	virtual Cola* clone() const override;
	virtual ~Cola() = default;

	double getPrezzoNetto() const;
	virtual double getPrezzo() const override;
	virtual std::string getBarCode() const override;
	Tipo getTipo() const;
	std::string tipoToString() const;
	Contenitore getContenitore() const;
	std::string contenitoreToString() const;
	double getLitri() const;

	void setTassa(const double&);
	void setPrezzoNetto(const double&);
	void setBarCode(const std::string&);
	void setTipo(const Tipo&);
	void setContenitore(const Contenitore&);
	void setLitri(const double&);

	virtual bool operator==(const Cola&) const;
	virtual bool operator!=(const Cola&) const;

};

#endif // COLA_H
