#include <iostream>
#include <vector>
#include "Desarrollador.h"
#include "Abogado.h"
#include "Diseñador.h"

int main()
{
    std::cout << "Hello World!\n";
	Desarrollador dev1("Warcos", 101, 100.0, "C++");
	Abogado ab1("Oscar", 102, 180.0,6);
	Diseñador dis1("Icazu", 103, 150.0, "Photoshop");

	std::cout << "Salario antes del bono : " << dev1.GetSalario() << std::endl;
	std::cout << "Salario despues del bono : " << dev1.GetSalario() * 1.25f << std::endl;
	dev1.CalcularBono();
	dev1.Trabajar();
	std::cout << std::endl;

	std::cout << "Salario antes del bono : " << ab1.GetSalario() << std::endl;
	std::cout << "Salario despues del bono : " << ab1.GetSalario() * 1.35f << std::endl;
	ab1.CalcularBono();
	ab1.Trabajar();
	std::cout << std::endl;

	std::cout << "Salario antes del bono : " << dis1.GetSalario() << std::endl;
	std::cout << "Salario despues del bono : " << dis1.GetSalario() * 1.20f << std::endl;
	dis1.CalcularBono();
	dis1.Trabajar();
	std::cout << std::endl;

	std::vector<Empleado*> listaDeEmpleados;
	listaDeEmpleados.push_back(&dev1);
	listaDeEmpleados.push_back(&ab1);
	listaDeEmpleados.push_back(&dis1);

	for (int i = 0; i < listaDeEmpleados.size(); i++)
	{
		listaDeEmpleados[i]->SetSalario(5);
		listaDeEmpleados[i]->Trabajar();
		listaDeEmpleados[i]->CalcularBono();
	}
}