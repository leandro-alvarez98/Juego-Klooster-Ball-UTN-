#ifndef BOLA_H
#define BOLA_H

#include <SFML/Graphics.hpp>
#include "SetsGlobales.h"
#include "FisicasCirculo.h"
#include "ParametrosCuerpos.h"

/*
	Clase Proveniente de Ball
*/

class Bola : public sf::Drawable
{
	protected:
		FisicasCirculo circulo;

		sf::Color color;

	public:
		Cuerpo cuerpo;

		Bola();

		Bola(const sf::Vector2f, const sf::Vector2f, const sf::Vector2f, const float);

		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

		sf::Color get_color() const;

		void set_color(const sf::Color& );
};
#endif

