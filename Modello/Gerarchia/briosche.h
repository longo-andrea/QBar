#ifndef BRIOSCHE_H
#define BRIOSCHE_H

#include "cibo.h"

class Briosche : public Cibo {
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
	Briosche(std::string, double, double, double, double, bool,std::string, Impasto, Forma, Ripieno, int = 2020, int = 14);
	Briosche(const Briosche&);
	virtual Briosche* clone() const override;
	virtual ~Briosche() =default;

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

	virtual bool operator==(const Briosche&) const;
	virtual bool operator!=(const Briosche&) const;

};

#endif // BRIOSCHE_H
