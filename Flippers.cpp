 #include "Flippers.h"

Flippers::Flippers(const sf::Vector2f& _position, float _angulo , const sf::Vector2f& _extensionMedia, sf::Color _color, bool _lado)
{
	cuerpo = Cuerpo();
	cuerpo.setPosicion(_position);
	cuerpo.setAceleracion(sf::Vector2f(0,0));
	cuerpo.setVelocidad(sf::Vector2f(0, 0));
	cuerpo.setMasa(0.f);
	cuerpo.setInercia(0.f);
	cuerpo.setRestitucion(0.2f);

	en_lado_izquierdo = _lado;

	if (en_lado_izquierdo == true) 
	{
		cuerpo.setRadioAngulo(_angulo);
	}
	else 
	{
		cuerpo.setRadioAngulo(-_angulo);
	}

	forma = HitBoxFisicas(_position, _extensionMedia);

	cuerpo.fisicaTipo = (FisicasPorTipo*)&forma;

	color = _color;

	/*
	_texture.loadFromFile("flipper.png");
	_sprite.setTexture(_texture);
	_sprite.setPosition(_position);	
	*/

}

//aplica la velocidad al rotar los flippers
void Flippers::Mover(std::string evento)
{
	if (evento == "arriba") 
	{
		if (en_lado_izquierdo == true)
		{
			cuerpo.AplicarAnguloDeImpulso(PADDLE_SPEED);
		}
		else 
		{
			cuerpo.AplicarAnguloDeImpulso(-PADDLE_SPEED);
		}
	}
	else if (evento == "abajo")
	{
		if (en_lado_izquierdo == true)
		{
			cuerpo.AplicarAnguloDeImpulso(-PADDLE_SPEED);
		}
		else
		{
			cuerpo.AplicarAnguloDeImpulso(PADDLE_SPEED);
		}
	}
}

void Flippers::rotarFlipper()
{

	if (en_lado_izquierdo == true) 
	{

		if (cuerpo.getRadioAngulo() > PADDLE_MAX_ANGLE) 
		{
			cuerpo.setRadioAngulo((const float)PADDLE_MAX_ANGLE);
			cuerpo.setVelocidadAngular(0.f);
		}

		if (cuerpo.getRadioAngulo() < PADDLE_MIN_ANGLE) 
		{
			cuerpo.setRadioAngulo((const float)PADDLE_MIN_ANGLE);
			cuerpo.setVelocidadAngular(0.f);
		}
	}
	else 
	{
		if (cuerpo.getRadioAngulo() < -PADDLE_MAX_ANGLE)
		{
			cuerpo.setRadioAngulo((const float)-PADDLE_MAX_ANGLE);
			cuerpo.setVelocidadAngular(0.f);
		}

		if (cuerpo.getRadioAngulo() > -PADDLE_MIN_ANGLE)
		{
			cuerpo.setRadioAngulo((const float)-PADDLE_MIN_ANGLE);
			cuerpo.setVelocidadAngular(0.f);
		}
	}

}

void Flippers::draw(sf::RenderTarget& target, sf::RenderStates states) const
{ 
	const sf::Vector2f tamanio(forma.get_extension_media().x * (PIXELTOMETER * 2), //x
								forma.get_extension_media().y * (PIXELTOMETER * 2)); //y

	sf::RectangleShape rectangle;

	rectangle.setSize(sf::Vector2f(tamanio.x, tamanio.y));

	rectangle.setOrigin(tamanio.x / 2, tamanio.y / 2);

	rectangle.setPosition(cuerpo.getPosicion().x * PIXELTOMETER, cuerpo.getPosicion().y * PIXELTOMETER);

	rectangle.setRotation(cuerpo.getGradosAngulo());

	rectangle.setFillColor(color);

	target.draw(rectangle);
}