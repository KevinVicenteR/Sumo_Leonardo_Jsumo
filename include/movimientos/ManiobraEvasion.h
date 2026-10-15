#ifndef MANIOBRA_EVASION_H
#define MANIOBRA_EVASION_H

#include "movimientos/MandoMotores.h"
#include "movimientos/BusquedaRival.h"
#include "estrategia/DecisionMovimiento.h"

class ManiobraEvasion {
public:
    bool activa() const { return fase != Fase::Libre; }

    bool iniciar(int sentido, unsigned long duracionRetroceso, unsigned long duracionGiro,
                 unsigned long ahora, bool unSensor, bool veniaAvanzando = true);

    bool continuar(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
                   unsigned long ahora, BusquedaRival& busqueda);

    void actualizarSalidaSuave(unsigned long ahora);
    int limiteSalidaSuave() const { return limiteSalida; }

private:
    enum class Fase { Libre, Retrocediendo, GirandoSalida, Frenando, Girando, Asentando };

    bool separarse(bool linea, MandoMotores& mando, IMotor& motor, unsigned long ahora);
    bool reintentarSiAtascado(bool linea, MandoMotores& mando, IMotor& motor, unsigned long ahora);

    bool rivalConfirmado(const DecisionMovimiento& decision, bool linea, unsigned long ahora);

    Fase fase = Fase::Libre;
    bool viendoRival = false;
    unsigned long inicioRival = 0;
    bool huboCorte = false;
    unsigned long ultimoCorte = 0;
    unsigned long inicioFase = 0;
    unsigned long inicioEvasion = 0;
    bool negroContinuo = false;
    unsigned long inicioNegro = 0;
    bool unSensor = false;
    bool sinRetroceso = false;
    unsigned long duracionRetroceso = 0;
    unsigned long duracionGiro = 0;
    int sentidoGiro = 1;
    bool salidaSuave = false;
    unsigned long inicioSalidaSuave = 0;
    int limiteSalida = 255;
};

#endif
