#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <SFML/Graphics.hpp>
#include "SetsGlobales.h"
#include "ParametrosCuerpos.h"
#include "RectanguloFisicas.h"

/*
    Clase proveniente de rect
    Crea y dibuja un rectangulo usando las funciones de SFML
*/

class Rectangulo : public sf::Drawable
{
    protected:
        RectanguloFisicas forma;
        sf::Color color;
    public:
        Cuerpo cuerpo;

        Rectangulo();

        Rectangulo(const sf::Vector2f _origen, const sf::Vector2f _extensionMedia, const sf::Color _color);
       
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void set_color(const sf::Color&);

        sf::Color get_color() const;

        Rectangulo(const RectanguloFisicas& forma, const sf::Color& color, const Cuerpo& cuerpo);
};

#endif

