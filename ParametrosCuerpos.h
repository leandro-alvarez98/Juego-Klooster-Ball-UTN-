#ifndef PARAMETROSCUERPOS_H
#define PARAMETROSCUERPOS_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "SetsGlobales.h"
#include "FisicasPorTipo.h"

/*
    Clase proveniente de Body
*/

class Cuerpo 
{
    protected:
        float masa;
        float masaInversa;
        float restitucion;
        float inercia;
        float inerciaInversa;
        float velocidadAngular;
        float angulo;

    public:
        FisicasPorTipo* fisicaTipo;
        sf::Vector2f posicion;
        sf::Vector2f velocidad;
        sf::Vector2f aceleracion;
        Cuerpo();
        Cuerpo(const sf::Vector2f&, const sf::Vector2f&, const sf::Vector2f&, const float);

        void update(float);
        void updateBola(float);
        void setRestitucion(const float);
        void setMasa(const float);
        void setPosicion(const sf::Vector2f&);
        void setVelocidad(const sf::Vector2f&);
        void setAceleracion(const sf::Vector2f&);
        void setInercia(const float);
        void setVelocidadAngular(const float);

        float getRestitucion() const;
        float getMasa() const;
        float getMasaInversa() const;
        sf::Vector2f getAceleracion() const;
        sf::Vector2f getPosicion() const;
        sf::Vector2f getVelocidad() const;
        float getInerciaInversa()const; 
        float getVelocidadAngular() const;
        float getGradosAngulo() const;
        float getRadioAngulo() const;
        void setRadioAngulo(const float);

        void AplicarImpulso(const sf::Vector2f, const sf::Vector2f);
        void AplicarAnguloDeImpulso(const float);
        float ProductoCruzado(const sf::Vector2f&, const sf::Vector2f&) const;
};
#endif