#ifndef VINO_H
#define VINO_H

#include "bevanda.h"

class Vino : public Bevanda {
public:
	enum Regione { Veneto, Emilia, Toscana, Friuli };
private:
	static double tassa;

	double prezzoNetto;
	double gradazioneAlcolica;
	std::string barCode;
	unsigned int annoProduzione;
	Regione regione;
	double litri;


public:
	Vino(std::string, double, double, double, double, double, double, std::string, int, Regione, bool =true, int = 2020, int = 18);
	Vino(const Vino&);
	virtual Vino* clone() const override;
	virtual ~Vino() = default;

	double getPrezzoNetto() const;
	virtual double getPrezzo() const override;
	double getGradazioneAlcolica() const;
	virtual std::string getBarCode() const override;
	unsigned int getAnnoProduzione() const;
	Regione getRegione() const;
	std::string regioneToString() const;
	double getLitri() const;
	virtual double calcolaCalorie() const override;

	void setTassa(const double&);
	void setPrezzoNetto(const double&);
	void setGradazioneAlcolica(const double&);
	void setBarCode(const std::string&);
	void setAnnoProduzione(const int&);
	void setRegione(const Regione&);
	void setLitri(const double&);

	virtual bool operator==(const Vino&) const;
	virtual bool operator!=(const Vino&) const;
};


#endif // !VINO_H


