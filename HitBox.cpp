#include "HitBox.h"

HitBox::HitBox()
{
    cuerpo = Cuerpo();

    forma = HitBoxFisicas();

    cuerpo.fisicaTipo = (FisicasPorTipo*)&forma;

    cuerpo.setAceleracion(sf::Vector2f(0,0));

    cuerpo.setVelocidad(sf::Vector2f(0, 0));

    cuerpo.setMasa(0);

    cuerpo.setInercia(0);

    cuerpo.setRestitucion(0.5);

    color = sf::Color::Black;
}

HitBox::HitBox(const sf::Vector2f _origen, const sf::Vector2f _extensionMedia, const float _angulo, const sf::Color _color)
{
    cuerpo = Cuerpo();

    cuerpo.setPosicion(_origen);

    cuerpo.setAceleracion(sf::Vector2f(0, 0));

    cuerpo.setVelocidad(sf::Vector2f(0, 0));

    cuerpo.setMasa(0);

    cuerpo.setInercia(0);

    cuerpo.setRestitucion(0.5);

    cuerpo.setRadioAngulo(_angulo);

    forma = HitBoxFisicas(_origen, _extensionMedia);

    cuerpo.fisicaTipo = (FisicasPorTipo*)&forma;

    color = _color;
}

void HitBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Vector2f aux;
    aux.x = PIXELTOMETER;
    aux.y = PIXELTOMETER;

    const sf::Vector2f size = forma.get_extension_media() * (aux.x + aux.y);

    sf::RectangleShape rectangle;

    rectangle.setSize(sf::Vector2f(size.x, size.y));

    rectangle.setOrigin(size.x/ 2, size.y/ 2);

    rectangle.setPosition(cuerpo.getPosicion().x * PIXELTOMETER, cuerpo.getPosicion().y * PIXELTOMETER);

    rectangle.setRotation(cuerpo.getGradosAngulo());

    rectangle.setFillColor(color);

    target.draw(rectangle);
}

sf::Color HitBox::get_color() const
{
    return color;
}

void HitBox::set_color(const sf::Color& _color)
{ 
    color = _color;
}
