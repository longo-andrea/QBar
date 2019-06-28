#ifndef PANINO_H
#define PANINO_H

#include "cibo.h"
#include <iostream>

class Panino : public Cibo {
public:
	enum Pane { Tartaruga, Arabo, Baguette, Integrale };
private:
	class inizializzaPanino{
	private:
		Panino* ptr;
	
	public:	
		inizializzaPanino();
		~inizializzaPanino();
	};

	static inizializzaPanino mappaPanino;
	static double tassa;

	double prezzoPreparazione;
	std::string barCode;	
	Pane pane;
	
	Panino* create(Json::Value&) const override;
	
public:
    Panino(const std::string& ="No Name", double =0, double =0, double =0, double =0, bool =false, const std::string& ="No Bar Code", Pane =Pane::Tartaruga, int = 2020, int = 14);
	Panino(const Panino&);
	virtual Panino* clone() const override;
	virtual ~Panino() = default;

	double getPrezzoPreparazione() const override;
	std::string getBarCode() const override;
	double getPrezzo() const override;
	std::string getTipo() const override;
	
	Pane getPane() const;
	std::string paneToString() const;

	void setPrezzoPreparazione(const double&);
	void setBarCode(const std::string&);
	void setPane(Pane);
	
	void serialize(Json::Value&) const override;

	virtual bool operator==(const Panino&) const;
	virtual bool operator!=(const Panino&) const;

    static Pane stringToPane(const std::string&);
};

#endif // PANINO_H
