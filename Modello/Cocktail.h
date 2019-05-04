#ifndef COCKTAIL_H
#define COCKTAIL_H

#include "Bevanda.h"

class Cocktail : public Bevanda {
public:
	enum Quantita { Short, Medium, Long };
	enum Classificazione { Analcolico, Coffe, Cooler, Exotic, Wine };
private:
	static double tassa;

	double prezzoNetto;
	std::string barCode;
	Quantita quantita;
	Classificazione famiglia;
	double gradazioneAlcolica;

public:
	Cocktail(std::string, double, double, double, double, std::string, Quantita, Classificazione, double, bool, int = 2020, int = 18);
	Cocktail(const Cocktail&);
	virtual Cocktail* clone() const override;
	virtual ~Cocktail() = default;

	double getPrezzoNetto() const;
	Quantita getQuantita() const;
	std::string quantitaToString() const;
	Classificazione getFamiglia() const;
	std::string famigliaToString() const;
	double getGradazioneAlcolica() const;
	virtual std::string getBarCode() const override;
	virtual double getPrezzo() const override;

	void setPrezzoNetto(const double&);
	void setQuantita(const Quantita&);
	void setFamiglia(const Classificazione&);
	void setGradazioneAlcolica(const double&);
	void setBarCode(const std::string&);

	virtual bool operator==(const Cocktail&) const;
	virtual bool operator!=(const Cocktail&) const;
};

#endif // COCKTAIL_H
