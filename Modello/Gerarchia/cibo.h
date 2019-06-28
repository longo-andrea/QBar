#ifndef CIBO_H
#define CIBO_H

#include "prodotto.h"
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

	Cibo(const std::string& ="No Name", double =0, double =0, double =0, bool =false, int = 2020, int = 14);
	Cibo(const Cibo&);
	virtual ~Cibo() =default;

	double getCarboidrati() const;
	double getProteine() const;
	double getGrassi() const;
	bool isVegan() const;

	void setCarboidrati(const double&);
	void setProteine(const double&);
	void setGrassi(const double&);
	void setIsVegan(const bool&);

	virtual double getPrezzoPreparazione() const = 0;
	virtual std::string getBarCode() const = 0;
	virtual double getPrezzo() const = 0;

    double calcolaCalorie() const override;

	virtual bool operator==(const Cibo&) const;
	virtual bool operator!=(const Cibo&) const;

};

#endif // CIBO_H
