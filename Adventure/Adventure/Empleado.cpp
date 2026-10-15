#include "Empleado.h"
Empleado::Empleado(std::string n, int id, double s)
{
	this->nombre = n;
	this->id = id;
	this->salario = s;
}

Empleado::~Empleado()
{
}

void Empleado::SetSalario(double newSalario)
{
	if (newSalario >= 0)
		this->salario = newSalario;
}

double Empleado::GetSalario()
{
	return salario;
}

void Empleado::CalcularBono()
{
	std::cout << "El bono es: " << (salario * .25f) << std::endl;
}

void Empleado::Trabajar()
{
	std::cout << "Trabajando" << std::endl;
}