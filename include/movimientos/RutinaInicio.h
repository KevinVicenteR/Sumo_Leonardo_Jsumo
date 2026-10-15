#ifndef RUTINA_INICIO_H
#define RUTINA_INICIO_H

#include "movimientos/MandoMotores.h"
#include "movimientos/Confirmacion.h"
#include "movimientos/BusquedaRival.h"
#include "movimientos/ControlAtaque.h"
#include "estrategia/DecisionMovimiento.h"

class RutinaInicio {
public:
    void iniciar(int rutinaElegida, int lado);
    void cancelar() { rutina = 0; }

    int actual() const { return rutina; }
    bool elegida() const { return conRutina; }

    bool continuar(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
                   unsigned long ahora, BusquedaRival& busqueda, ControlAtaque& ataque);

private:
    bool girar(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
               unsigned long ahora, unsigned long t, BusquedaRival& busqueda, ControlAtaque& ataque);
    void decidirLado(const DecisionMovimiento& decision, BusquedaRival& busqueda);
    bool avanzarAlCentro(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
                         unsigned long ahora, unsigned long t, ControlAtaque& ataque);
    bool explorar(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
                  unsigned long ahora, unsigned long t);

    int rutina = 0;
    int lado = 1;
    bool conRutina = false;
    bool enCurso = false;
    unsigned long inicio = 0;
    bool ladoDecidido = false;
    Confirmacion rivalVisto;
    bool frenandoGiro = false;
    unsigned long inicioFreno = 0;
    Freno freno;
};

#endif
