#ifndef ANALCOLICO_H
#define ANALCOLICO_H

#include "bevanda.h"

class Analcolico : public Bevanda {
public:
	enum Variante { Classica, Zero, Light, Diet };
	enum Contenitore { Lattina, Bottiglia, Spina };
private:
	class inizializzaAnalcolico{
	private:
		Analcolico* ptr;
	
	public:	
		inizializzaAnalcolico();
		~inizializzaAnalcolico();
	};

	static inizializzaBrioche mappaAnalcolico;
	static double tassa;

	double prezzoNetto;
	std::string barCode;
	Variante variante;
	Contenitore contenitore;
	double litri;
	
	Analcolico* create(Json::Value&) const override;
	Variante stringToVariante(const std::string&) const;
	Contenitore stringToContenitore(const std::string&) const;

public:
	Analcolico(const std::string& ="No Name", double =0, double =0, double =0, double =0, const std::string& ="No Bar Code", Variante =Variante::Classica, Contenitore =Contenitore::Bottiglia, double =0, bool = false, int = 2020, int = 14);
	Analcolico(const Analcolico&);
	virtual Analcolico* clone() const override;
	virtual ~Analcolico() = default;

	double getPrezzo() const override;
	std::string getBarCode() const override;
	std::string getTipo() const override;
		
	double getPrezzoNetto() const;
	Variante getVariante() const;
	std::string varianteToString() const;
	Contenitore getContenitore() const;
	std::string contenitoreToString() const;
	double getLitri() const;

	void setTassa(const double&);
	void setPrezzoNetto(const double&);
	void setBarCode(const std::string&);
	void setVariante(const Variante&);
	void setContenitore(const Contenitore&);
	void setLitri(const double&);
	
	void serialize(Json::Value&) const override;

	virtual bool operator==(const Analcolico&) const;
	virtual bool operator!=(const Analcolico&) const;

};

#endif // ANALCOLICO_H
