#include "movimientos/RutinaInicio.h"

void RutinaInicio::iniciar(int rutinaElegida, int ladoElegido) {
    rutina = rutinaElegida;
    lado = ladoElegido < 0 ? -1 : 1;
    enCurso = false;
    conRutina = rutinaElegida != 0;
}

bool RutinaInicio::continuar(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
                             unsigned long ahora, BusquedaRival& busqueda, ControlAtaque& ataque) {
    if (rutina == 0) {
        return false;
    }
    if (!enCurso) {
        enCurso = true;
        inicio = ahora;
        rivalVisto.reiniciar();
        ladoDecidido = false;
        busqueda.fijarSentido(lado);
    }

    if (frenandoGiro) {
        const bool sigue = ahora - inicioFreno < freno.duracion;
        if (sigue) {
            mando.mover(motor, freno.izq, freno.der, true);
        } else {
            frenandoGiro = false;
            rutina = 0;
        }
        return sigue;
    }

    const unsigned long t = ahora - inicio;
    bool sigue = false;
    if (rutina == 2) {
        decidirLado(decision, busqueda);
    }
    const unsigned long esquiva = rutina == 1 ? TiempoEsquivaRound1 : rutina == 2 ? TiempoEsquivaRound2 : 0;
    if (t < esquiva) {
        mando.mover(motor, VelocidadEsquiva, VelocidadEsquiva, true);
        return true;
    }
    if (rutina == 1 || rutina == 2) {
        const unsigned long tGiro = t - esquiva;
        sigue = girar(decision, mando, motor, ahora, tGiro, busqueda, ataque);
    } else if (rutina == 3) {
        sigue = avanzarAlCentro(decision, mando, motor, ahora, t, ataque);
    } else if (rutina == 4) {
        sigue = explorar(decision, mando, motor, ahora, t);
    }
    if (!sigue) {
        rutina = 0;
    }
    return sigue;
}

bool RutinaInicio::girar(const DecisionMovimiento& decision, MandoMotores& mando, IMotor& motor,
                         unsigned long ahora, unsigned long t, BusquedaRival& busqueda,
                         ControlAtaque& ataque) {
    const unsigned long maximo = rutina == 1 ? TiempoMaxGiroEspalda : TiempoMaxGiroLado;
    const unsigned long minimo = rutina == 1 ? TiempoMinimoGiroEspalda : TiempoMinimoGiroLado;
    const bool confirmado = rivalVisto.actualizar(veDeFrente(decision), ahora);
    const bool encontrado = confirmado && t >= minimo;
    const bool sigue = !encontrado && t < maximo;

    if (encontrado) {
        ataque.iniciarEmbestida(ahora);
        if (mando.calcularFreno(TiempoFrenadoRuedas, freno)) {
            frenandoGiro = true;
            inicioFreno = ahora;
            mando.mover(motor, freno.izq, freno.der, true);
            return true;
        }
    }

    if (sigue && rutina == 2 && PivoteRound2) {
        mando.mover(motor, lado > 0 ? VelocidadPivoteInicio : 0, lado > 0 ? 0 : VelocidadPivoteInicio, true);
    } else if (sigue) {
        const int velocidad = rutina == 2 ? VelocidadGiroRound2 : VelocidadGiroInicio;
        mando.mover(motor, lado * velocidad, -lado * velocidad, true);
    }
    return sigue;
}

bool RutinaInicio::avanzarAlCentro(const DecisionMovimiento& decision, MandoMotores& mando,
                                   IMotor& motor, unsigned long ahora, unsigned long t,
                                   ControlAtaque& ataque) {
    const bool esperando = EsperarRound3 && t >= TiempoAvanceInicio;
    const bool visto = decision.tipo != TipoAccion::Busqueda;
    const bool confirmado = rivalVisto.actualizar(visto, ahora);
    const unsigned long fin = TiempoAvanceInicio + (EsperarRound3 ? TiempoEsperaRound3 : 0);
    const bool encontrado = confirmado && t >= TiempoMinimoAvanceInicio;
    const bool sigue = !encontrado && t < fin;
    if (encontrado && esAtaque(decision.tipo)) {
        ataque.iniciarAproximacion(ahora);
    }
    if (sigue && esperando) {
        mando.mover(motor, 0, 0, true);
    } else if (sigue) {
        mando.mover(motor, VelocidadAvanceInicio, VelocidadAvanceInicio);
    }
    return sigue;
}

bool RutinaInicio::explorar(const DecisionMovimiento& decision, MandoMotores& mando,
                            IMotor& motor, unsigned long ahora, unsigned long t) {
    const bool confirmado = rivalVisto.actualizar(decision.tipo != TipoAccion::Busqueda, ahora);
    const bool sigue = !confirmado && t < TiempoMaxGiroRound4;
    if (sigue) {
        mando.mover(motor, lado * VelocidadGiroRound4, -lado * VelocidadGiroRound4, true);
    }
    return sigue;
}

void RutinaInicio::decidirLado(const DecisionMovimiento& decision, BusquedaRival& busqueda) {
    if (ladoDecidido) {
        return;
    }
    const TipoAccion t = decision.tipo;
    const bool izquierda = t == TipoAccion::DefensaIzq || t == TipoAccion::CorregirIzq;
    const bool derecha = t == TipoAccion::DefensaDer || t == TipoAccion::CorregirDer;
    if (!izquierda && !derecha) {
        return;
    }
    lado = izquierda ? -1 : 1;
    busqueda.fijarSentido(lado);
    ladoDecidido = true;
}
