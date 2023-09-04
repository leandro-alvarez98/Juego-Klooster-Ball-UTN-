#include "EnemigoRectangular.h"

EnemigoRectangular::EnemigoRectangular()
{
    cuerpo = Cuerpo();

    cuerpo.setPosicion(sf::Vector2f(0,0));

    cuerpo.setRestitucion(0);

    cuerpo.setMasa(0);

    forma = HitBoxFisicas();

    cuerpo.fisicaTipo = (FisicasPorTipo*)&forma;

    set_color(sf::Color::Black);

    set_tipo(rectangular);

    set_puntos(0);
}

EnemigoRectangular::EnemigoRectangular(const sf::Vector2f _posicion, const sf::Vector2f _extensionMedia, const float _angulo, const int _puntos, const sf::Color _color)
{
    cuerpo = Cuerpo();

    cuerpo.setPosicion(_posicion);

    cuerpo.setRestitucion(0.5);

    cuerpo.setMasa(0);

    cuerpo.setRadioAngulo(_angulo);

    forma = HitBoxFisicas(_posicion, _extensionMedia);

    cuerpo.fisicaTipo = (FisicasPorTipo*)&forma;

    set_color(_color);

    set_tipo(rectangular);

    set_puntos(_puntos);

}