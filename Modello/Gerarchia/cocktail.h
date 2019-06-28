#ifndef COCKTAIL_H
#define COCKTAIL_H

#include "bevanda.h"

class Cocktail : public Bevanda {
public:
	enum Quantita { Short, Medium, Long };
	enum Classificazione { Coffe, Cooler, Exotic, Wine };
private:
	class inizializzaCocktail{
	private:
		Cocktail* ptr;
	
	public:	
		inizializzaCocktail();
		~inizializzaCocktail();
	};

	static inizializzaCocktail mappaCocktail;
	static double tassa;

	double prezzoNetto;
	std::string barCode;
	Quantita quantita;
	Classificazione famiglia;
	double gradazioneAlcolica;
	
	Cocktail* create(Json::Value&) const override;

public:
	Cocktail(const std::string& ="No Name", double =0, double =0, double =0, double =0, const std::string& ="No Bar Code", Quantita =Quantita::Long, Classificazione =Classificazione::Coffe, double =0, bool =true, int = 2020, int = 18);
	Cocktail(const Cocktail&);
	virtual Cocktail* clone() const override;
	virtual ~Cocktail() = default;

	std::string getBarCode() const override;
	double getPrezzo() const override;
	double calcolaCalorie() const override;
	std::string getTipo() const override;
	
	double getPrezzoNetto() const;
	Quantita getQuantita() const;
	std::string quantitaToString() const;
	Classificazione getFamiglia() const;
	std::string famigliaToString() const;
	double getGradazioneAlcolica() const;

	void setPrezzoNetto(const double&);
	void setQuantita(const Quantita&);
	void setFamiglia(const Classificazione&);
	void setGradazioneAlcolica(const double&);
	void setBarCode(const std::string&);
	
	void serialize(Json::Value&) const override;

	virtual bool operator==(const Cocktail&) const;
	virtual bool operator!=(const Cocktail&) const;

    static Quantita stringToQuantita(const std::string&);
    static Classificazione stringToClassificazione(const std::string&);
};

#endif // COCKTAIL_H
