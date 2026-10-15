#ifndef CONTROLADOR_ROBOT_H
#define CONTROLADOR_ROBOT_H

#include "hardware/IMotor.h"
#include "sensores/IPercepcion.h"
#include "estrategia/IEstrategiaCombate.h"
#include "movimientos/IControlMovimiento.h"

class ControladorRobot {
public:
    ControladorRobot(IPercepcion& percepcion, IEstrategiaCombate& estrategia,
                     IControlMovimiento& controlMovimiento, IMotor& motor);
    void actualizar();

private:
    IPercepcion& percepcion;
    IEstrategiaCombate& estrategia;
    IControlMovimiento& controlMovimiento;
    IMotor& motor;
    LecturasSensores lecturas{};
};

#endif
