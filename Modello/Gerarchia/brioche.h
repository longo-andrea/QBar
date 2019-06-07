#ifndef BRIOCHE_H
#define BRIOCHE_H

#include "cibo.h"

class Brioche : public Cibo {
public:
	enum Impasto { Classico, Integrale, SenzaGlutine };
	enum Forma { Cornetto, Girella, Ciambella };
	enum Ripieno { Vuota, Cioccolato, Marmellata, Crema };
	
private:
	class inizializzaBrioche{
	private:
		Brioche* ptr;
	
	public:	
		inizializzaBrioche();
		~inizializzaBrioche();
	};

	static inizializzaBrioche mappaBrioche;
	static double tassa;
	
	double prezzoPreparazione;
	std::string barCode;
	Impasto impasto;
	Forma forma;
	Ripieno ripieno;
	
	Impasto stringToImpasto(const std::string&) const;
	Forma stringToForma(const std::string&) const;
	Ripieno stringToRipieno(const std::string&) const;

public:
	Brioche(const std::string& ="No Name", double =0, double =0, double =0, double =0, bool =false, const std::string& ="No Bar Code", Impasto =Impasto::Classico, Forma =Forma::Cornetto, Ripieno =Ripieno::Vuota, int = 2020, int = 14);
	Brioche(const Brioche&);
	virtual Brioche* clone() const override;
	virtual ~Brioche() =default;
	Brioche* create(Json::Value&) const override;

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
