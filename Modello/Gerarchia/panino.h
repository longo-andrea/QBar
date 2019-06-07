#ifndef PANINO_H
#define PANINO_H

#include "cibo.h"
#include <iostream>

class Panino : public Cibo {
public:
	enum Pane { Tartaruga, Arabo, Baguette, Integrale };
private:
	static double tassa;

	double prezzoPreparazione;
	std::string barCode;	
	Pane pane;

public:
	Panino(const std::string& ="No Name", double =0, double =0, double =0, double =0, const std::string& ="No Bar Code", Pane =Pane::Tartaruga, bool =false, int = 2020, int = 14);
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

};

#endif // PANINO_H
