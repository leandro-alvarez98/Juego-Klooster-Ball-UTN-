#pragma once

#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
class Sonidos
{
 private: 
	 Music musica;
	 SoundBuffer buffer;
	 Sound sound;

 public:

	 Sonidos();
	 

	void ReproducirMusicaFondo();
	void DetenerMusica();
	void ReproducirMusicaNivel1();
	void ReproducirMusicaNivel2();
	void ReproducirMusicaNivel3();
	void PausarMusica();
	void Reanudar();

	void ReproducirFlipper();
	void ReproducirGentes();
	void ReproducirArranque();
	void ReproducirSeleccion(int);
	void ReproducirGameOver();
	void ReproducirRestarBola();
	void ReproducirChoque();
	void ReproducirLanzamiento();
	
};

