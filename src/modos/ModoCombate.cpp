#include <Arduino.h>
#include <avr/wdt.h>
#include "modos/ModoCombate.h"
#include "Pines.h"
#include "Parametros.h"

ModoCombate::ModoCombate(PlacaXMotion& placaRef, DriverMotores& motoresRef, Percepcion& percepcionRef,
                         ControlMovimiento& controlRef, ControladorRobot& robotRef)
    : placa(placaRef), motores(motoresRef), percepcion(percepcionRef), controlMovimiento(controlRef),
      robot(robotRef), moduloArranque(FiltroModuloArranqueMs, FiltroParadaModuloMs) {}

void ModoCombate::iniciar() {
    MCUSR = 0;
    wdt_disable();
    placa.inicializarPines();
    motores.deshabilitar();
    if (PIN_MODULO_ARRANQUE < 0) {
        empezarCombate();
    }
}

void ModoCombate::empezarCombate() {
    placa.inicializarPines();
    motores.deshabilitar();
    percepcion = Percepcion();
    percepcion.calibrarPiso();
    controlMovimiento.reiniciar();
    const int dip = placa.leerInterruptores();
    const int rutina = RutinaForzada >= 0 ? RutinaForzada : rutinaSegunInterruptores(dip);
    const int lado = LadoForzado != 0 ? LadoForzado : (dip & 4) ? -1 : 1;
    controlMovimiento.iniciarRutina(rutina, lado);
    enCombate = true;
    combateEmpezado = true;
    inicioCombate = millis();
}

void ModoCombate::actualizar() {
    if (PIN_MODULO_ARRANQUE >= 0) {
        const bool senalAlta = digitalRead((uint8_t)PIN_MODULO_ARRANQUE) == HIGH;
        if (!moduloArranque.enMarcha(senalAlta == ModuloArranqueActivoAlto, millis())) {
            motores.deshabilitar();
            esperandoInicio = false;
            if (enCombate) {
                inicioParada = millis();
            }
            if (combateEmpezado && ReiniciarTrasParada &&
                millis() - inicioParada >= TiempoReanudarCombate) {
                reiniciarPlaca();
                return;
            }
            if (combateEmpezado) {
                percepcion.leer();
            }
            enCombate = false;
            return;
        }
        if (!enCombate) {
            const bool paradaCorta = millis() - inicioParada < TiempoReanudarCombate;
            const bool estabaEnMarcha = inicioParada - inicioCombate >= TiempoMinimoParaReanudar;
            if (combateEmpezado && paradaCorta && estabaEnMarcha) {
                enCombate = true;
            } else {
                if (!esperandoInicio) {
                    esperandoInicio = true;
                    inicioEspera = millis();
                }
                if (millis() - inicioEspera < EsperaInicioCombateMs) {
                    return;
                }
                esperandoInicio = false;
                empezarCombate();
            }
        }
    }

    robot.actualizar();
}

void ModoCombate::reiniciarPlaca() {
    motores.deshabilitar();
    wdt_enable(WDTO_15MS);
    while (true) {
    }
}
