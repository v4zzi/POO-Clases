#include "Desarrollador.h"



Desarrollador::Desarrollador(std::string n, int id, double s, std::string l)
	:Empleado(n, id, s)
{
	this->lenguaje = l;
}

void Desarrollador::Trabajar()
{
	std::cout << nombre << " usa " << this->lenguaje << " para su codigo " << std::endl;
}

void Desarrollador::CalcularBono()
{
	std::cout << "Su bono es: " << (GetSalario() * 1.25f) << std::endl;
}
