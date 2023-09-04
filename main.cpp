#include <iostream>
#include "Juego.h"
#include "Manager.h"
using namespace std;

int main()
{
	
	Manager menu;

	srand(time(NULL));

	while (menu.Ventana_Esta_Abierta())
	{
		menu.Actualizar();
	}

	return 0;
}