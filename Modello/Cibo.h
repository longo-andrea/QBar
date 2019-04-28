#ifndef CIBO_H
#define CIBO_H

#include "Prodotto.h"
#include <string>
#include <iostream>

class Cibo : public Prodotto {
private:
	static double valoreEnergeticoCarboidrati;
	static double valoreEnergeticoProteine;
	static double valoreEnergeticoGrassi;

	double carboidrati;
	double proteine;
	double grassi;
	bool vegan;

public:

	Cibo(std::string, double, double, double, bool, int = 2020, int = 14);
	Cibo(const Cibo&);
	virtual ~Cibo() =default;

	double getCarboidrati() const;
	double getProteine() const;
	double getGrassi() const;
	bool isVegan() const;
	virtual double getPrezzoPreparazione() const = 0;
	virtual std::string getBarCode() const = 0;
	virtual double getPrezzo() const = 0;

	void setCarboidrati(const double&);
	void setProteine(const double&);
	void setGrassi(const double&);

	virtual double calcolaCalorie() const;

	virtual bool operator==(const Prodotto&) const override;
	virtual bool operator!=(const Prodotto&) const override;

};

#endif // CIBO_H