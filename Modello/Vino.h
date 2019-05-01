#ifndef VINO_H
#define VINO_H

#include "Bevanda.h"

class Vino : public Bevanda {
public:
	enum Regione { Veneto, Emilia, Toscana, Friuli };
private:
	static double tassa;
	static double valoreEnergeticoAlcol;

	double prezzoNetto;
	double gradazioneAlcolica;
	std::string barCode;
	unsigned int annoProduzione;
	Regione regione;


public:
	Vino(std::string, double, double, double, bool, double, double, std::string, unsigned int, Regione, int = 2020, int = 18);
	Vino(const Vino&);
	virtual ~Vino() = default;

	double getPrezzoNetto() const;
	virtual double getPrezzo() const override;
	double getGradazioneAlcolica() const;
	virtual std::string getBarCode() const override;
	unsigned int getAnnoProduzione() const;
	Regione getRegione() const;
	std::string regioneToString() const;

	void setTassa(const double&);
	void setPrezzoNetto(const double&);
	void setGradazioneAlcolica(const double&);
	void setBarCode(const std::string&);
	void setAnnoProduzione(const unsigned int&);
	void setRegione(const Regione&);

	virtual double calcolaCalorie() const override;

	virtual bool operator==(const Vino&) const;
	virtual bool operator!=(const Vino&) const;
};


#endif // !VINO_H


