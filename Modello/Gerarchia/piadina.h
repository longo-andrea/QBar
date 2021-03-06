#ifndef PIADINA_H
#define PIADINA_H

#include "cibo.h"
#include <iostream>

class Piadina : public Cibo {
public:
	enum Impasto { Classico, Cereali, Integrale, Kamut };
private:
	class inizializzaPiadina{
	private:
		Piadina* ptr;
	
	public:	
		inizializzaPiadina();
		~inizializzaPiadina();
	};

	static inizializzaPiadina mappaPiadina;
	static double tassa;

	double prezzoPreparazione;
	std::string barCode;
	Impasto impasto;
	
	Piadina* create(Json::Value&) const override;

public:
	Piadina(const std::string& ="No Name", double =0, double =0, double =0, double =0, bool =false, const std::string& ="No Bar Code", Impasto =Impasto::Classico, int = 2020, int = 14);
	Piadina(const Piadina&);
	virtual Piadina* clone() const override;
	virtual ~Piadina() =default;
		
	double getPrezzoPreparazione() const override;
	std::string getBarCode() const override;
	double getPrezzo() const override;
	std::string getTipo() const override;
	
	Impasto getImpasto() const;
	std::string impastoToString() const;

	void setPrezzoPreparazione(const double&);
	void setBarCode(const std::string&);
	void setImpasto(Impasto);
	
	void serialize(Json::Value&) const override;

	virtual bool operator==(const Piadina&) const;
	virtual bool operator!=(const Piadina&) const;

    static Impasto stringToImpasto(const std::string&);
};

#endif // !PIADINA_H
