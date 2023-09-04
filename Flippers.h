#ifndef FLIPPERS_H
#define FLIPPERS_H

#include <SFML/Graphics.hpp>
#include "SetsGlobales.h"
#include "HitBox.h"

/*
    Clase proveniente de Paddle
*/

class Flippers : public sf::Drawable
{
    private:
        /*
        sf::Sprite _sprite;
        sf::Texture _texture;        
        */
        bool en_lado_izquierdo; 
        HitBoxFisicas forma;
        sf::Color color;

    public:
        Cuerpo cuerpo;

        Flippers(const sf::Vector2f& _position, float _angulo, const sf::Vector2f& _extensionMedia, sf::Color _color, bool _lado);

        void Mover(std::string);

        void rotarFlipper();

        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};
#endif