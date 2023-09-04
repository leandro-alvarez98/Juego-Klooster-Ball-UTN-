#ifndef HITBOXFISICAS_H
#define HITBOXFISICAS_H

#include <SFML/Graphics.hpp>
#include "FisicasPorTipo.h"
#include <cmath>

/*
    Clase proveniente de obbPhys
*/

class HitBoxFisicas : public FisicasPorTipo
{
    private:
         sf::Vector2f extensionMedia;

    public:
        HitBoxFisicas();

        HitBoxFisicas(const sf::Vector2f&, const sf::Vector2f&);

        float get_ancho() const;

        float get_alto()const;

        sf::Vector2f get_minimo() const;

        sf::Vector2f get_maximo() const;

        void set_extension_media(const sf::Vector2f);

        sf::Vector2f get_extension_media() const;
};
#endif