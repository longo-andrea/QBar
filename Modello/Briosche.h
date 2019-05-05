#ifndef BRIOSCHE_H
#define BRIOSCHE_H

#include "Cibo.h"

class Briosche : public Cibo {
public:
	enum Impasto { Classico, Integrale, SenzaGlutine };
	enum Tipo { Cornetto, Girella, Ciambella };
	enum Ripieno { Vuota, Cioccolato, Marmellata, Crema };
private:
	static double tassa;
	
	double prezzoPreparazione;
	std::string barCode;
	Impasto impasto;
	Tipo tipo;
	Ripieno ripieno;

public:
	Briosche(std::string, double, double, double, double, bool,std::string, Impasto, Tipo, Ripieno, int = 2020, int = 14);
	Briosche(const Briosche&);
	virtual Briosche* clone() const override;
	virtual ~Briosche() =default;

	double getPrezzoPreparazione() const override;
	std::string getBarCode() const override;
	double getPrezzo() const override;
	Impasto getImpasto() const;
	Tipo getTipo() const;
	Ripieno getRipieno() const;
	std::string impastoToString() const;
	std::string tipoToString() const;
	std::string ripienoToString() const;

	void setPrezzoPreparazione(const double&);
	void setBarCode(const std::string&);
	void setImpasto(const Impasto&);
	void setTipo(const Tipo&);
	void setRipieno(const Ripieno&);

	virtual bool operator==(const Briosche&) const;
	virtual bool operator!=(const Briosche&) const;

};

#endif // BRIOSCHE_H