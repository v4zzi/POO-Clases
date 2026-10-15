#pragma once
#include "Empleado.h"
class Diseñador :
    public Empleado
{
    public:
        //Constructor
        Diseñador(std::string n, int id, double s, std::string h);



		void Trabajar() override;
		void CalcularBono() override;
};

