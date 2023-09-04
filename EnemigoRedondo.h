#ifndef ENEMIGOREDONDO_H
#define ENEMIGOREDONDO_H

#include <SFML/Graphics.hpp>
#include "Enemigos.h"
/*
	Esta clase proviene de roundBumper
*/

class EnemigoRedondo : public Enemigos, public Bola
{
	private:

	public:
		EnemigoRedondo();

		EnemigoRedondo(const sf::Vector2f _posicion, const float _radio, const int _puntos, const sf::Color _color);
};
#endif
