#include "EnemigoRedondo.h"

EnemigoRedondo::EnemigoRedondo()
{
    cuerpo = Cuerpo();

    cuerpo.setPosicion(sf::Vector2f(0.f,0.f));

    cuerpo.setRestitucion(0.9f);

    cuerpo.setMasa(0.f);

    circulo = FisicasCirculo(0.f);

    cuerpo.fisicaTipo = (FisicasPorTipo*)&circulo;

    set_color(sf::Color::Black);

    set_tipo(redondo);

    set_puntos(0);
}

EnemigoRedondo::EnemigoRedondo(const sf::Vector2f _posicion, const float _radio, const int _puntos, const sf::Color _color)
{
    cuerpo = Cuerpo();

    cuerpo.setPosicion(_posicion);

    cuerpo.setRestitucion(0.9f);

    cuerpo.setMasa(0.f);

    circulo = FisicasCirculo(_radio);

    cuerpo.fisicaTipo = (FisicasPorTipo*)&circulo;

    set_color(_color);

    set_tipo(redondo);

    set_puntos(_puntos);
}