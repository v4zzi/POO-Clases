#pragma once
#include "Empleado.h"
class Desarrollador :
    public Empleado
{
private:
	std::string lenguaje;
public:
	//Constructor
	Desarrollador(std::string n, int id, double s, std::string l);



	void Trabajar() override;
	void CalcularBono() override;
};

