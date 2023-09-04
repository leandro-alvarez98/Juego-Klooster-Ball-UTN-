#include "RectanguloFisicas.h"

RectanguloFisicas::RectanguloFisicas()
{
    tipo = aabb;
}

RectanguloFisicas::RectanguloFisicas(const sf::Vector2f& _origen, const sf::Vector2f& _extensionMedia)
{
    extensionMedia = _extensionMedia;
    tipo = aabb;
}

void RectanguloFisicas::set_extensionMedia(const sf::Vector2f _extensionMedia)
{
    extensionMedia = _extensionMedia;
}

sf::Vector2f RectanguloFisicas::get_extensionMedia() const
{
    return extensionMedia;
}

float RectanguloFisicas::get_ancho() const
{
    return get_maximo().x - get_minimo().x;
}

float RectanguloFisicas::get_alto() const
{
    return get_maximo().y - get_minimo().y;
}

sf::Vector2f RectanguloFisicas::get_minimo() const
{
    return -extensionMedia;
}

sf::Vector2f RectanguloFisicas::get_maximo() const
{
    return extensionMedia;
}