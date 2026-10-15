#include "Diseñador.h"

Diseñador::Diseñador(std::string n, int id, double s, std::string h)
	:Empleado(n, id, s)
{
}



void Diseñador::Trabajar()
{
	std::cout << nombre << " esta diseñando un proyecto creativo." << std::endl;
}

void Diseñador::CalcularBono()
{
	std::cout << "Su bono es: " << (GetSalario() * 1.20f) << std::endl;
}
