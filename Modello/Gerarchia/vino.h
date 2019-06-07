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
	Vino(const std::string& ="No Name", double =0, double =0, double =0, double =0, double =0, double =0, const std::string& ="No Bar Code", int =0, Regione =Regione::Veneto, bool =true, int =2020, int =18);
	Vino(const Vino&);
	virtual Vino* clone() const override;
	virtual ~Vino() = default;

	double getPrezzo() const override;
	std::string getBarCode() const override;
	double calcolaCalorie() const override;
	std::string getTipo() const override;

	double getPrezzoNetto() const;
	double getGradazioneAlcolica() const;
	unsigned int getAnnoProduzione() const;
	Regione getRegione() const;
	std::string regioneToString() const;
	double getLitri() const;

	void setTassa(const double&);
	void setPrezzoNetto(const double&);
	void setGradazioneAlcolica(const double&);
	void setBarCode(const std::string&);
	void setAnnoProduzione(const int&);
	void setRegione(const Regione&);
	void setLitri(const double&);

	void serialize(Json::Value&) const override;

	virtual bool operator==(const Vino&) const;
	virtual bool operator!=(const Vino&) const;
};


#endif // !VINO_H


