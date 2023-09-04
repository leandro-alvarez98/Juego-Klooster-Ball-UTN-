#define _USE_MATH_DEFINES
#include "ParametrosCuerpos.h"

Cuerpo::Cuerpo()
{
    sf::Vector2f aux;
    aux.x = 0.f;
    aux.y = 0.f;

    setPosicion(aux);
    setVelocidad(aux);
    setAceleracion(aux);
    setMasa(1);
    setRestitucion(0);
    setVelocidadAngular(0);
    setRadioAngulo(0);
    setInercia(0);
}

Cuerpo::Cuerpo(const sf::Vector2f& _posicion, const sf::Vector2f& _velocidad, const sf::Vector2f& _aceleracion, const float _restitucion)
{
    posicion = _posicion;
    velocidad = _velocidad;
    aceleracion = _aceleracion;
    restitucion = _restitucion;
    setMasa(1);
    setVelocidadAngular(0);
    setRadioAngulo(0);
    setInercia(0);
}

void Cuerpo::update(float deltaTime)
{
    sf::Vector2f velocidadBase(velocidad + (aceleracion * deltaTime));

    posicion += ((getVelocidad() + velocidadBase) / 2.f) * deltaTime;

    velocidad = velocidadBase;

    float anguloNuevo = angulo + (velocidadAngular * deltaTime);

    setRadioAngulo(anguloNuevo);

    if (velocidad.x > MAX_VELOCITY_X) 
    {
        velocidad.x = (MAX_VELOCITY_X);
    }
    else if (velocidad.y > MAX_VELOCITY_Y) 
    {
        velocidad.y = (MAX_VELOCITY_Y);
    }
}

void Cuerpo::updateBola(float deltaTime)
{
    sf::Vector2f velocidadBase(velocidad + (aceleracion * deltaTime));

    posicion += ((getVelocidad() + velocidadBase) / 2.f) * deltaTime;

    velocidad = velocidadBase;

    float anguloNuevo = angulo + (velocidadAngular * deltaTime);

    setRadioAngulo(anguloNuevo);

    //Regula la velocidad en X
    if (velocidad.x > MAX_VELOCITY_X)
    {
        velocidad.x = (MAX_VELOCITY_X);
    }

    //Regula la velocidad en Y
    if (velocidad.y > MAX_VELOCITY_Y)
    {
        velocidad.y = (MAX_VELOCITY_Y);
    }
    else if (velocidad.y > 0 && velocidad.y < MIN_VELOCITY_Y)
    {
        velocidad.y = MIN_VELOCITY_Y;
    }
}



void Cuerpo::setRestitucion(float _restitucion) //!< Sets de restitucion
{
    restitucion = _restitucion;
}

void Cuerpo::setMasa(const float _masa)
{
    masa = _masa;

    if (masa == 0.0f) 
    {
        masaInversa = 0.0f;
    }
    else 
    {
        masaInversa = 1.0f / masaInversa;
    }
}

void Cuerpo::setRadioAngulo(const float _angulo)
{
    const float rotacionEntera = 2.f * M_PI;

    float anguloNuevo = _angulo;
    //abs devuelve la distancia del numero hacia el 0 osea siempre un num positivo
    while (std::abs(anguloNuevo) > rotacionEntera) 
    {
        if (anguloNuevo > 0)
            anguloNuevo -= rotacionEntera;
        else
            anguloNuevo += rotacionEntera;
    }

    angulo = anguloNuevo;
}

void Cuerpo::setAceleracion(const sf::Vector2f &_aceleracion)
{
    aceleracion = _aceleracion;
}

void Cuerpo::setPosicion(const sf::Vector2f& _posicion)
{
    posicion = _posicion;
}

void Cuerpo::setVelocidad(const sf::Vector2f& _velocidad)
{
    velocidad = _velocidad;
}

float Cuerpo::getRestitucion() const
{
    return restitucion;
}

float Cuerpo::getMasa() const
{
    return masa;
}

float Cuerpo::getMasaInversa() const
{
    return masaInversa;
}

float Cuerpo::getInerciaInversa() const
{
    return inerciaInversa;
}

float Cuerpo::getVelocidadAngular() const
{
    return velocidadAngular;
}

void Cuerpo::setInercia(const float _inercia)
{
    inercia = _inercia;
    if (inercia == 0.0f)
        inerciaInversa = 0.0f;
    else
        inerciaInversa = 1.0f / _inercia;
}

void Cuerpo::setVelocidadAngular(const float _velocidadAngular)
{
    velocidadAngular = _velocidadAngular;
}

void Cuerpo::AplicarAnguloDeImpulso(const float _anguloDeImpulso)
{
    velocidadAngular += _anguloDeImpulso;
}

float Cuerpo::getRadioAngulo() const
{
    return angulo;
}

float Cuerpo::getGradosAngulo() const
{
    return angulo * (180 / M_PI);
}

sf::Vector2f Cuerpo::getAceleracion() const
{
    return aceleracion;
}

sf::Vector2f Cuerpo::getPosicion() const
{
    return posicion;
}

sf::Vector2f Cuerpo::getVelocidad() const
{
    return velocidad;
}

void Cuerpo::AplicarImpulso(const sf::Vector2f _impulso, const sf::Vector2f _contacto)
{
    velocidad += _impulso * getMasaInversa();
    velocidadAngular += ProductoCruzado(_impulso, _contacto) * getInerciaInversa();
}

float Cuerpo::ProductoCruzado(const sf::Vector2f & _valor, const sf::Vector2f& _contacto) const
{
    return (_contacto.x * _valor.y) - (_contacto.y * _valor.x);
}
