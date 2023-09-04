#ifndef COLISIONES_H
#define COLISIONES_H

#include <cmath>
#include "bola.h"
#include "Rectangulo.h"
#include "HitBox.h"
#include "Rotacion.h"



class Colisiones
{
    protected:
        Cuerpo* cuerpo_a;
        Cuerpo* cuerpo_b; 

    private:
        float penetracion;
        sf::Vector2f normal;
        sf::Vector2f punto_de_contacto;

    public:
        Colisiones();

        Colisiones(Cuerpo* first , Cuerpo* second);

        bool CirculoVsCirculo();  //Determina colision entre circulo - circulo

        bool CirculoVsRectangulo(); //Determina colision entre circulo - rectangulo

        bool CirculoVsHitbox(); //Determina colision entre circulo - hitbox

        void aplicarCaida();

        sf::Vector2f get_normal() const { return normal;}

        float get_penetracion() const { return penetracion;}

        void aplicarImpulso();

        void correctPosition();

        sf::Vector2f Ajustar(const sf::Vector2f& tamañoRectangulo, const sf::Vector2f& posicionCirculo); //Determina el punto mas cecano al borde de AABB
};
#endif
