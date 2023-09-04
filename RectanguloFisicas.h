#ifndef RECTANGULOFISICAS_H
#define RECTANGULOFISICAS_H


#include "SFML/Graphics.hpp"
#include "FisicasPorTipo.h"

/*
    Clase proveniente de rectPhys
*/

class RectanguloFisicas : public FisicasPorTipo
{
    private:

        sf::Vector2f extensionMedia;

    public:
        RectanguloFisicas();

        RectanguloFisicas(const sf::Vector2f& _origen, const sf::Vector2f& _extensionMedia);

        void set_extensionMedia(const sf::Vector2f _extensionMedia);

        sf::Vector2f get_extensionMedia() const;

        float get_ancho() const;

        float get_alto()const;

        sf::Vector2f get_minimo() const;

        sf::Vector2f get_maximo() const;
};
#endif

