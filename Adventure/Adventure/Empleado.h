#pragma once

#include <iostream>

class Empleado
{
private:
	double salario;
protected:
	std::string nombre;
	int id;
public:
	//Constructor
	Empleado(std::string n, int id, double s);

	//Destructor
	virtual ~Empleado();

	void SetSalario(double newSalario);
	double GetSalario();

	virtual void CalcularBono();
	virtual void Trabajar();
};

