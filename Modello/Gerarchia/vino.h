#ifndef VINO_H
#define VINO_H

#include "bevanda.h"

class Vino : public Bevanda {
public:
	enum Regione { Emilia, Veneto, Friuli, Toscana };
	
private:
	class inizializzaVino{
	private:
		Vino* ptr;
	
	public:	
		inizializzaVino();
		~inizializzaVino();
	};

	static inizializzaVino mappaVino;
	static double tassa;

	double prezzoNetto;
	std::string barCode;
	Regione regione;
	int annoProduzione;
	double litri;
	double gradazioneAlcolica;
	
	Vino* create(Json::Value&) const override;

public:
	Vino(const std::string& ="No Name", double =0, double =0, double =0, double =0, const std::string& ="No Bar Code", Regione =Regione::Veneto, double  =0, double =0, int =1980, bool =true, int = 2020, int = 18);
	Vino(const Vino&);
	virtual Vino* clone() const override;
	virtual ~Vino() = default;

	std::string getBarCode() const override;
	double getPrezzo() const override;
	double calcolaCalorie() const override;
	std::string getTipo() const override;
	
    double getPrezzoNetto() const override;
	Regione getRegione() const;
	std::string regioneToString() const;
	int getAnnoProduzione() const;
	double getLitri() const;
	double getGradazioneAlcolica() const;

	void setBarCode(const std::string&);
	void setPrezzoNetto(const double&);
	void setRegione(const Regione&);
	void setAnnoProduzione(const int&);
	void setLitri(const double&);
	void setGradazioneAlcolica(const double&);
	
	void serialize(Json::Value&) const override;

	virtual bool operator==(const Vino&) const;
	virtual bool operator!=(const Vino&) const;

    static Regione stringToRegione(const std::string&);
};

#endif // COCKTAIL_H

