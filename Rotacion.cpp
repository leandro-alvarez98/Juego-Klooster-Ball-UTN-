#include "Rotacion.h"

float productoEscalar(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
    float producto = 0;
    producto = v1.x * v2.x + v1.y * v2.y;
    return producto;
}

float productoEscalar(const sf::Vector2f& v1)
{
    float producto = 0;
    producto = v1.x * v1.x + v1.y * v1.y;
    return producto;
}


Rotacion::Rotacion()
{
    matriz_datos[0] = 0;
    matriz_datos[1] = 0;
    matriz_datos[2] = 0;
    matriz_datos[3] = 0;
}

Rotacion::Rotacion(const float _radianes)
{
    set_radianes(_radianes);
}

void Rotacion::set_radianes(const float _radianes)
{
    float fCos = cosf(_radianes);
    float fSin = sinf(_radianes);
    matriz_datos[0] = fCos;
    matriz_datos[1] = -fSin;
    matriz_datos[2] = fSin;
    matriz_datos[3] = fCos;
}

sf::Vector2f Rotacion::rotar_vector(const sf::Vector2f& _vectorARotar) const
{
    sf::Vector2f fila1 = sf::Vector2f(matriz_datos[0], matriz_datos[1]);

    sf::Vector2f fila2 = sf::Vector2f(matriz_datos[2], matriz_datos[3]);

    return sf::Vector2f(productoEscalar(fila1, _vectorARotar), productoEscalar(fila2, _vectorARotar));
}

sf::Vector2f Rotacion::rotar_vector_inversamente(const sf::Vector2f& _vectorARotar) const
{
    sf::Vector2f columna1 = sf::Vector2f(matriz_datos[0], matriz_datos[2]);
    sf::Vector2f columna2 = sf::Vector2f(matriz_datos[1], matriz_datos[3]);

    return sf::Vector2f(productoEscalar(columna1, _vectorARotar), productoEscalar(columna2, _vectorARotar));
}
