#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SetsGlobales.h"
#include "Juego.h"
#include "Jugadores.h"

/*
	Clase para controlar el menú y la continuidad del juego
*/

class Manager
{
	private:
		int main_menu_selected;
		sf::Text main_menu[max_main_menu];
		sf::Text menu_niveles[max_main_menu];

		sf::RenderWindow* ventana;
		sf::VideoMode video_mode;
		sf::Font font;
		sf::Event evento;
		Sonidos sonido;
		sf::Texture textura[4];
		sf::Sprite sprite[4];

		bool BandMusica;
		void Init_Menu();


	public:
		Manager();
		~Manager();
		const bool Ventana_Esta_Abierta() const;
		void Actualizar();
		void Up(int tipo_de_menu);
		void Down(int tipo_de_menu);
		int MainMenuPressed();
		void DibujarMenu(sf::RenderWindow*& ventana, int tipo_de_menu);
		void IniciarJuego();
		bool IngresarNombre(Jugadores& _jugador);
		void RankingDePuntajes();
		void OrdenarJugadoresxPuntos(Jugadores*& _vector, int _tamanio);
		void MoverKlooster();
};
#endif