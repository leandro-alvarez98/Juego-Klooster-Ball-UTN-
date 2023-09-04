#ifndef ENEMIGORECTANGULAR_H
#define ENEMIGORECTANGULAR_H

#include <SFML/Graphics.hpp>
#include "Enemigos.h"
#include "HitBox.h"
#include "ParametrosCuerpos.h"

/*
    Clase proveniente de RectangleBumper
*/

class EnemigoRectangular : public Enemigos, public HitBox
{
    private:

    public:
        EnemigoRectangular();
        EnemigoRectangular(const sf::Vector2f _posicion, const sf::Vector2f _extensionMedia, const float _angulo, const int _puntos, const sf::Color _color);
};
#endif

