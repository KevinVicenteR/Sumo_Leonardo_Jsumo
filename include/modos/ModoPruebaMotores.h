#ifndef MODO_PRUEBA_MOTORES_H
#define MODO_PRUEBA_MOTORES_H

#include "hardware/DriverMotores.h"
#include "hardware/PlacaXMotion.h"

class ModoPruebaMotores {
public:
    ModoPruebaMotores(PlacaXMotion& placa, DriverMotores& motores): placa(placa), motores(motores) {}

    void iniciar();
    void actualizar();

private:
    void paso(const __FlashStringHelper* texto, int izq, int der);

    PlacaXMotion& placa;
    DriverMotores& motores;
};

#endif
