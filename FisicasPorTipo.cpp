#include "FisicasPorTipo.h"

FisicasPorTipo::FisicasPorTipo()
{
	tipo = circulo;
}

void FisicasPorTipo::setTipo(Tipo _tipo)
{
	tipo = _tipo;
}

Tipo FisicasPorTipo::getTipo()
{
	return tipo;
}
