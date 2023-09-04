#ifndef ROTACION_H
#define ROTACION_H

#include <SFML/Graphics.hpp>
#include <cmath>
/*
    Clase proveniente de rotationMat
    Crea una matriz de rotacion
 */

class Rotacion
{
    protected:
        float matriz_datos[4];
    public:
        Rotacion();
        Rotacion(const float);
        void set_radianes(const float);

        sf::Vector2f rotar_vector(const sf::Vector2f&) const;

        sf::Vector2f rotar_vector_inversamente(const sf::Vector2f& _vectorARotar) const;
};
#endif
