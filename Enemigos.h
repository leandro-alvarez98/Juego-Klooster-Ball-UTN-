#ifndef ENEMIGOS_H
#define ENEMIGOS_H

#include "Bola.h"
#include "HitBox.h"

/*
    Clase Proveniente de Bumpers
*/

enum TipoEnemigo 
{
    redondo,
    rectangular
};

class Enemigos
{
    protected:
        TipoEnemigo tipo;
        int puntos;

    public:
        Enemigos();

        Enemigos(TipoEnemigo _tipo, int _puntos);

        void set_tipo(TipoEnemigo _tipo);
        void set_puntos(int _puntos); 

        TipoEnemigo get_tipo(); 
        int get_puntos();
};
#endif