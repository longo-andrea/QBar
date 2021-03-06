#ifndef BEVANDA_H
#define BEVANDA_H

#include "prodotto.h"
#include <iostream>

class Bevanda : public Prodotto {
protected:
	static double valoreEnergeticoAlcol;
private:
	static double valoreEnergeticoCarboidrati;
	static double valoreEnergeticoProteine;
	static double valoreEnergeticoGrassi;

	double carboidrati;
	double proteine;
	double grassi;
	bool alcoholic;

public:
	Bevanda(const std::string& ="No Name", double =0, double=0, double =0, bool =false, int = 2020, int = 14);
	Bevanda(const Bevanda&);
	virtual ~Bevanda() = default;

	double getCarboidrati() const;
	double getProteine() const;
	double getGrassi() const;
	bool isAlcoholic() const;
    virtual double getPrezzoNetto() const = 0;

	void setCarboidrati(const double&);
	void setProteine(const double&);
	void setGrassi(const double&);
	void setAlcoholic(const bool&);

    virtual double calcolaCalorie() const;

	virtual bool operator==(const Bevanda&) const;
	virtual bool operator!=(const Bevanda&) const;
};

#endif // !BEVANDA_H
