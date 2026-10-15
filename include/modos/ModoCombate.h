#ifndef MODO_COMBATE_H
#define MODO_COMBATE_H

#include "hardware/DriverMotores.h"
#include "hardware/PlacaXMotion.h"
#include "hardware/ModuloArranque.h"
#include "sensores/Percepcion.h"
#include "movimientos/ControlMovimiento.h"
#include "robot/ControladorRobot.h"

class ModoCombate {
public:
    ModoCombate(PlacaXMotion& placa, DriverMotores& motores, Percepcion& percepcion,
                ControlMovimiento& controlMovimiento, ControladorRobot& robot);

    void iniciar();
    void actualizar();

private:
    void empezarCombate();
    void reiniciarPlaca();

    PlacaXMotion& placa;
    DriverMotores& motores;
    Percepcion& percepcion;
    ControlMovimiento& controlMovimiento;
    ControladorRobot& robot;
    ModuloArranque moduloArranque;
    bool enCombate = false;
    bool combateEmpezado = false;
    bool esperandoInicio = false;
    unsigned long inicioEspera = 0;
    unsigned long inicioCombate = 0;
    unsigned long inicioParada = 0;
};

#endif
