#include "Enemigos.h"

Enemigos::Enemigos()
{
    tipo = redondo;
    puntos = 0;
}

Enemigos::Enemigos(TipoEnemigo _tipo, int _puntos)
{
    tipo = _tipo;
    puntos = _puntos;
}

void Enemigos::set_tipo(TipoEnemigo _tipo)
{
    tipo = _tipo;
}

void Enemigos::set_puntos(int _puntos)
{
    puntos = _puntos;
}

TipoEnemigo Enemigos::get_tipo()
{
    return tipo;
}

int Enemigos::get_puntos()
{
    return puntos;
}