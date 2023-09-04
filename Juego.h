#ifndef JUEGO_H
#define JUEGO_H
#include "Jugadores.h"
#include "ArchivoJugadores.h"
#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "SetsGlobales.h"
#include "Bola.h"
#include "Rectangulo.h"
#include "HitBox.h"
#include "Colisiones.h"
#include "EnemigoRedondo.h"
#include "EnemigoRectangular.h"
#include "Flippers.h"
#include "Sonidos.h"
#include <list>

/*
    Clase proveniente de Main 
    Pienso que la usemos para crear dos o tres mapas y manejemos todo de acá
*/

class Juego
{
	private:
		//Ventana
		sf::RenderWindow ventana;
		sf::VideoMode video_mode;
		sf::Event evento;
        Sonidos sonido;
        sf::Texture textura;
        sf::Sprite sprite;
        
        sf::Font fuente_de_texto;

        ///Game Logic
        bool bool_En_Juego;
        bool bool_Fin_Juego;
        int puntaje_total;
        int bolas_restantes;
        int puntaje_mas_alto;
        int intentos;
        bool BandSonido;

        void InitJuego();

	public:
        Juego();
        void primer_nivel(Jugadores& jugador);
        void segundo_nivel(Jugadores& jugador);
        void tercer_nivel(Jugadores& jugador);
        void restar_bola();
        void MoverKlooster();
};

#endif





