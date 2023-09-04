#include "Bola.h"

Bola::Bola()
{
    sf::Vector2f aux;
    aux.x = 0.f;
    aux.y = 0.f;

    cuerpo = Cuerpo();

    cuerpo.setPosicion(aux);

    cuerpo.setAceleracion(aux);

    cuerpo.setVelocidad(aux);

    cuerpo.setRestitucion(1);

    cuerpo.setInercia(8);

    cuerpo.setMasa(1);

    circulo = FisicasCirculo(0);

    cuerpo.fisicaTipo = (FisicasPorTipo*)&circulo;

    color = sf::Color::White;
}

Bola::Bola(const sf::Vector2f _posicion, const sf::Vector2f _velocidad, const sf::Vector2f _aceleracion, const float _radio)
{
    cuerpo = Cuerpo();

    cuerpo.setPosicion(_posicion);

    cuerpo.setAceleracion(_aceleracion);

    cuerpo.setVelocidad(_velocidad);

    cuerpo.setRestitucion(1);

    cuerpo.setInercia(8.f);

    cuerpo.setMasa(1);

    circulo = FisicasCirculo(_radio);

    cuerpo.fisicaTipo = (FisicasPorTipo*)&circulo;

    color = sf::Color::White;
}

void Bola::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::CircleShape Bola = sf::CircleShape(circulo.getRadio() * PIXELTOMETER, 15);

    Bola.setFillColor(get_color());

    Bola.setOrigin(circulo.getRadio() * PIXELTOMETER, circulo.getRadio() * PIXELTOMETER);

    Bola.setPosition(cuerpo.getPosicion().x * PIXELTOMETER, cuerpo.getPosicion().y * PIXELTOMETER);

    target.draw(Bola);
}

sf::Color Bola::get_color() const
{
    return color;
}

void Bola::set_color(const sf::Color& _color)
{
    color = _color;
}
