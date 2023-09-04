#ifndef HITBOX_H
#define HITBOX_H

#include <SFML/Graphics.hpp>
#include "SetsGlobales.h"
#include "HitBoxFisicas.h"
#include "ParametrosCuerpos.h"

/*
    Clase proveniente de OBB
    Crea una hitbox para el sistema de colisiones
*/

class HitBox : public sf::Drawable
{
    protected:

        HitBoxFisicas forma;

        sf::Color color;

    public:
        Cuerpo cuerpo;

        HitBox();
        
        HitBox(const sf::Vector2f _origen, const sf::Vector2f _extensionMedia, const float _angulo, const sf::Color _color);
   
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
   
        sf::Color get_color() const;
  
        void set_color(const sf::Color& _color);
};
#endif

