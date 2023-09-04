#pragma once
#include <string>
#include <cstdio>
#include "Jugadores.h"

class ArchivoJugadores
{
private:
	std::string _ruta;
public:
	ArchivoJugadores();
	int getCantidadRegistros();
	bool guardar(Jugadores reg);
	Jugadores leer(int nroRegistro);
	void ListarTodo();

	//void CrearCopiadeSeguridad();
};


