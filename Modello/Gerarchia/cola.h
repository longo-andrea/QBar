#ifndef COLA_H
#define COLA_H

#include "bevanda.h"

class Cola : public Bevanda {
public:
	enum Aroma { Classica, Zero, Light, Diet, Stevia };
	enum Contenitore { Lattina, Bottiglia, Spina };
private:
	static double tassa;

	double prezzoNetto;
	std::string barCode;
	Aroma aroma;
	Contenitore contenitore;
	double litri;
public:
	Cola(std::string, double, double, double, double, std::string, Aroma, Contenitore, double, bool = false, int = 2020, int = 14);
	Cola(const Cola&);
	virtual Cola* clone() const override;
	virtual ~Cola() = default;

	double getPrezzo() const override;
	std::string getBarCode() const override;
	std::string getTipo() const override;
		
	double getPrezzoNetto() const;
	Aroma getAroma() const;
	std::string aromaToString() const;
	Contenitore getContenitore() const;
	std::string contenitoreToString() const;
	double getLitri() const;

	void setTassa(const double&);
	void setPrezzoNetto(const double&);
	void setBarCode(const std::string&);
	void setAroma(const Aroma&);
	void setContenitore(const Contenitore&);
	void setLitri(const double&);

	virtual bool operator==(const Cola&) const;
	virtual bool operator!=(const Cola&) const;

};

#endif // COLA_H
