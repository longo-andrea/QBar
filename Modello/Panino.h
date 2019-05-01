#ifndef PANINO_H
#define PANINO_H

#include "Cibo.h"
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
	Panino(std::string, double, double, double, double, std::string, Pane, bool=false, int = 2020, int = 14);
	Panino(const Panino&);
	virtual ~Panino() = default;

	double getPrezzoPreparazione() const override;
	std::string getBarCode() const override;
	double getPrezzo() const override;
	Pane getPane() const;
	std::string paneToString() const;

	void setTassa(const double&);
	void setPrezzoPreparazione(const double&);
	void setBarCode(const std::string&);
	void setPane(Pane);

	virtual bool operator==(const Panino&) const;
	virtual bool operator!=(const Panino&) const;

};

#endif // PANINO_H
