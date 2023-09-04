#include "Sonidos.h"



Sonidos::Sonidos() {
	

}

void Sonidos::ReproducirMusicaFondo() {
	if (!musica.openFromFile("Sonidos/Musica.wav")) {
		std::cout << "No se cargo la musica" << std::endl;
	}

	musica.setVolume(15);
	musica.setLoop(true);
	musica.play();
}

void Sonidos::PausarMusica()
{
	musica.pause();
}
void Sonidos::Reanudar()
{
	musica.play();
}
void Sonidos::DetenerMusica()
{
	musica.stop();
}
void Sonidos::ReproducirFlipper()
{
	if (!buffer.loadFromFile("Sonidos/SonidoFlipper.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}

	sound.setBuffer(buffer);
	sound.setVolume(25);
	sound.play();
}
void Sonidos::ReproducirGentes() {
	if (!buffer.loadFromFile("Sonidos/gentes.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}

	sound.setBuffer(buffer);
	sound.setVolume(25);
	sound.play();

}
void Sonidos::ReproducirArranque() {

	if (!buffer.loadFromFile("Sonidos/Arranque.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);

	sound.play();
}

void Sonidos::ReproducirLanzamiento() {

	if (!buffer.loadFromFile("Sonidos/deploy.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);

	sound.play();
}

void Sonidos::ReproducirSeleccion(int caso)
{
	switch(caso)
	{
		case 1:
		{
			if (!buffer.loadFromFile("Sonidos/seleccion.wav")) {
				std::cout << "No se cargo los sonidos" << std::endl;
			}
			break;
		}
		case 2:
		{
			if (!buffer.loadFromFile("Sonidos/Erase.wav")) {
				std::cout << "No se cargo los sonidos" << std::endl;
			}
			break;
		}
		case 3:
		{
			if (!buffer.loadFromFile("Sonidos/Error.wav")) {
				std::cout << "No se cargo los sonidos" << std::endl;
			}
			break;
		}
		case 4:
		{
			if (!buffer.loadFromFile("Sonidos/typeSound.wav")) {
				std::cout << "No se cargo los sonidos" << std::endl;
			}
			break;
		}
	}
	sound.setBuffer(buffer);
	sound.setVolume(40);

	sound.play();
	
}

void Sonidos::ReproducirGameOver()
{
	if (!buffer.loadFromFile("Sonidos/Fin.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.setVolume(100);

	sound.play();
}

void Sonidos::ReproducirRestarBola()
{
	if (!buffer.loadFromFile("Sonidos/RestarBola.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.setVolume(100);

	sound.play();
}

void Sonidos::ReproducirChoque()
{
	if (!buffer.loadFromFile("Sonidos/Choque.wav")) {
		std::cout << "No se cargo los sonidos" << std::endl;
	}
	sound.setBuffer(buffer);
	sound.setVolume(50);

	sound.play();
}
void Sonidos::ReproducirMusicaNivel1()
{
	if (!musica.openFromFile("Sonidos/Musica1.wav")) {
		std::cout << "No se cargo la musica" << std::endl;
	}

	musica.setVolume(10);
	musica.setLoop(true);
	musica.play();

}
void Sonidos::ReproducirMusicaNivel2()
{
	if (!musica.openFromFile("Sonidos/Musica2.wav")) {
		std::cout << "No se cargo la musica" << std::endl;
	}

	musica.setVolume(10);
	musica.setLoop(true);
	musica.play();
}

void Sonidos::ReproducirMusicaNivel3()
{
	if (!musica.openFromFile("Sonidos/Musica3.wav")) {
		std::cout << "No se cargo la musica" << std::endl;
	}

	musica.setVolume(10);
	musica.setLoop(true);
	musica.play();
}

