#ifndef CONTROL_MOVIMIENTO_H
#define CONTROL_MOVIMIENTO_H

#include "movimientos/IControlMovimiento.h"
#include "movimientos/MandoMotores.h"
#include "movimientos/ManiobraEvasion.h"
#include "movimientos/RutinaInicio.h"
#include "movimientos/BusquedaRival.h"
#include "movimientos/GiroLateral.h"
#include "movimientos/ParoPerdida.h"
#include "movimientos/ControlAtaque.h"
#include "movimientos/LimitadorBorde.h"
#include "Parametros.h"

class ControlMovimiento: public IControlMovimiento {
public:
    explicit ControlMovimiento(int rampaPwmPorMs = RampaPwmPorMs, int patronBusqueda = PatronBusqueda)
        : rampa(rampaPwmPorMs), patron(patronBusqueda), mando(rampaPwmPorMs), busqueda(patronBusqueda) {}

    void ejecutar(const DecisionMovimiento& decision, IMotor& motor, unsigned long ahora) override;

    void reiniciar();
    void iniciarRutina(int rutinaInicio, int ladoInicio) {
        rutina.iniciar(rutinaInicio, ladoInicio);
        limitadorBorde.colocarSalida(rutinaInicio);
    }

private:
    void actualizarLimites(const DecisionMovimiento& decision);
    void empezarEvasionSiHayBorde(const DecisionMovimiento& decision, unsigned long ahora);
    bool resistirEnBorde(const DecisionMovimiento& decision, IMotor& motor);
    void ejecutarAccion(const DecisionMovimiento& decision, IMotor& motor, unsigned long ahora);

    int rampa;
    int patron;

    MandoMotores mando;
    ManiobraEvasion evasion;
    RutinaInicio rutina;
    BusquedaRival busqueda;
    GiroLateral giroLateral;
    ParoPerdida paro;
    ControlAtaque ataque;
    LimitadorBorde limitadorBorde;
};

#endif
