#include "Abogado.h"
Abogado::Abogado(std::string n, int id, double s, int i)
	:Empleado(n, id, s)
{
	casosGanados = i;
}



void Abogado::Trabajar()
{
	std::cout << nombre << " esta trabajando en un caso legal." << std::endl;
}

void Abogado::CalcularBono()
{
	std::cout << "Su bono es: " << (GetSalario() * 1.35f) << std::endl;
}