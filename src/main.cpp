#include <Arduino.h>
#include "hardware/DriverMotores.h"
#include "hardware/PlacaXMotion.h"
#include "sensores/Percepcion.h"
#include "estrategia/EstrategiaReglas.h"
#include "movimientos/ControlMovimiento.h"
#include "robot/ControladorRobot.h"

PlacaXMotion placaXMotion;
DriverMotores driverMotores;
Percepcion percepcionSensores;
EstrategiaReglas estrategiaCombate;
ControlMovimiento controlMovimiento;
ControladorRobot controladorRobot(percepcionSensores, estrategiaCombate, controlMovimiento, driverMotores);

#if defined(MODO_PRUEBA_MOTORES)
#include "modos/ModoPruebaMotores.h"
ModoPruebaMotores modoActivo(placaXMotion, driverMotores);
#else
#include "modos/ModoCombate.h"
ModoCombate modoActivo(placaXMotion, driverMotores, percepcionSensores, controlMovimiento, controladorRobot);
#endif

void setup() {
    modoActivo.iniciar();
}

void loop() {
    modoActivo.actualizar();
}
