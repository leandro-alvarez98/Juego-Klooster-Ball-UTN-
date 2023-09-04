#include "HitBoxFisicas.h"

HitBoxFisicas::HitBoxFisicas()
{
    tipo = Obb;
}

HitBoxFisicas::HitBoxFisicas(const sf::Vector2f& _origen, const sf::Vector2f& _extensionMedia)
{
    tipo = Obb;
    extensionMedia = _extensionMedia;
}

void HitBoxFisicas::set_extension_media(const sf::Vector2f _extensionMedia)
{
    extensionMedia = _extensionMedia;
}

sf::Vector2f HitBoxFisicas::get_extension_media() const
{
    return extensionMedia;
}

float HitBoxFisicas::get_ancho() const
{
    return get_maximo().x - get_minimo().x;
}

float HitBoxFisicas::get_alto() const
{
    return get_maximo().y - get_minimo().y;
}

sf::Vector2f HitBoxFisicas::get_minimo() const
{
    return -extensionMedia;
}

sf::Vector2f HitBoxFisicas::get_maximo() const
{
    return extensionMedia;
}