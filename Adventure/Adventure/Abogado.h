#pragma once
#include "Empleado.h"
class Abogado :
    public Empleado
{
private:
	int casosGanados;
    public:
        //Constructor
        Abogado(std::string n, int id, double s ,int i);

		

        void Trabajar() override;
		void CalcularBono() override;
};

