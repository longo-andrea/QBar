#ifndef BRIOCHE_H
#define BRIOCHE_H

#include "cibo.h"

class Brioche : public Cibo {
public:
	enum Impasto { Classico, Integrale, SenzaGlutine };
	enum Forma { Cornetto, Girella, Ciambella };
	enum Ripieno { Vuota, Cioccolato, Marmellata, Crema };
private:
	static double tassa;
	
	double prezzoPreparazione;
	std::string barCode;
	Impasto impasto;
	Forma forma;
	Ripieno ripieno;

public:
	Brioche(std::string, double, double, double, double, bool,std::string, Impasto, Forma, Ripieno, int = 2020, int = 14);
	Brioche(const Brioche&);
	virtual Brioche* clone() const override;
	virtual ~Brioche() =default;

	double getPrezzoPreparazione() const override;
	std::string getBarCode() const override;
	double getPrezzo() const override;
	std::string getTipo() const override;
	
	Impasto getImpasto() const;
	Forma getForma() const;
	Ripieno getRipieno() const;
	std::string impastoToString() const;
	std::string formaToString() const;
	std::string ripienoToString() const;

	void setPrezzoPreparazione(const double&);
	void setBarCode(const std::string&);
	void setImpasto(const Impasto&);
	void setForma(const Forma&);
	void setRipieno(const Ripieno&);
	
	void serialize(Json::Value&) const override;

	virtual bool operator==(const Brioche&) const;
	virtual bool operator!=(const Brioche&) const;

};

#endif // BRIOCHE_H
