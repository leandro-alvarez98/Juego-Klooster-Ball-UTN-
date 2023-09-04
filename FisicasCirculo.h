#ifndef FISICASCIRCULO_H
#define FISICASCIRCULO_H

#include "FisicasPorTipo.h"

/*
    Clase proveniente de CirclePhys
*/

class FisicasCirculo : public FisicasPorTipo 
{
    private:
        float radio;

    public:

        FisicasCirculo()
        {
            tipo = Tipo::circulo; 
            radio = 0.f;
        };

        FisicasCirculo(const float _radio) { tipo = Tipo::circulo; radio = _radio; };

        void setRadio(const float _radio) { radio = _radio; };

        float getRadio() const { return radio;};
};

#endif
