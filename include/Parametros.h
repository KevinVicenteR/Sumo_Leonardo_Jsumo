#ifndef PARAMETROS_H
#define PARAMETROS_H

constexpr int VelocidadMaxima = 255;
constexpr int VelocidadFreno = 140;

constexpr int VelocidadAtaque = 130;
constexpr int VelocidadEmpuje = 255;
constexpr int VelocidadAtaqueDirecto = 0;
constexpr int PorcentajeAjuste = 85;
constexpr bool Corregir45EnPivote = true;
constexpr int VelocidadCurva = 85;
constexpr bool ResistirEnBorde = false;

constexpr bool GiroLateralEnRueda = false;
constexpr int VelocidadRuedaPivote = 180;
constexpr int VelocidadPivoteLateral = 220;

constexpr int VelocidadRetroceso = 255;
constexpr int VelocidadGiroEvasion = 75;

constexpr int VelocidadAvance = 80;
constexpr int VelocidadGiroBusqueda = 75;

constexpr int MascaraEnemigosActivosHigh = 31;
constexpr unsigned long TiempoRetencionEnemigo = 40;
constexpr unsigned long ConfirmacionSensorEnemigo = 0;

constexpr int PorcentajeUmbralLinea = 15;
constexpr int UmbralLineaMinimo = 60;
constexpr int MuestrasCalibracionPiso = 64;
constexpr int NegroPisoIzquierdo = 994;
constexpr int NegroPisoDerecho = 972;
constexpr int PorcentajeCercaBorde = 70;
constexpr int VelocidadCercaBorde = 100;

constexpr unsigned long TiempoFrenadoRuedas = 80;
constexpr unsigned long TauRuedas = 80;
constexpr int VelocidadMinimaFreno = 20;
constexpr unsigned long TiempoParoPerdida = 150;

constexpr unsigned long TiempoRetrocesoAmbos = 200;
constexpr unsigned long TiempoRetrocesoUnSensor = 90;
constexpr int VelocidadRetrocesoUnSensor = 118;
constexpr unsigned long TiempoSeparacionBorde = 90;
constexpr unsigned long TiempoSeparacionUnSensor = 50;
constexpr unsigned long TiempoMaximoRecuperacionBorde = 700;
constexpr bool CortarEvasionAlVerRival = true;
constexpr unsigned long TiempoConfirmarRivalEnEvasion = 20;
constexpr unsigned long EsperaEntreCortesEvasion = 2000;
constexpr unsigned long TiempoMaxParadoEnLinea = 300;
constexpr unsigned long TiempoReintentoRetroceso = 150;
constexpr unsigned long TiempoFrenado = 80;
constexpr unsigned long TiempoAsentamientoEvasion = 100;
constexpr unsigned long TiempoGiroEvasion = 240;
constexpr unsigned long TiempoGiroEvasionAmbos = 300;
constexpr bool SalirGirandoSiNoAvanza = false;
constexpr int AvanceMinimoParaRetroceder = 50;
constexpr unsigned long RetrocesoExtraAVelocidadMaxima = 300;
constexpr unsigned long TiempoSalidaSuaveUnSensor = 500;
constexpr int VelocidadSalidaUnSensor = 90;

constexpr unsigned long TiempoAvanceBusqueda = 1500;
constexpr unsigned long TiempoGiroBusqueda = 150;
constexpr unsigned long TiempoPausaBusqueda = 100;
constexpr unsigned long TiempoPulsoAvance = 0;
constexpr unsigned long TiempoPausaPulso = 40;
constexpr int PorcentajeArcoZigzag = 100;
constexpr unsigned long TiempoArcoZigzag = 0;

constexpr unsigned long TiempoEmbestida = 2500;
constexpr unsigned long TiempoMaxGiroLateral = 400;

constexpr bool UsarEstimadorBorde = true;
constexpr bool EstimadorLimitaEmbestida = true;
constexpr float RadioDohyo = 0.35f;
constexpr float AnchoLineaBorde = 0.025f;
constexpr float DistanciaSensorPiso = 0.078f;
constexpr float SeparacionSensoresPiso = 0.04f;
constexpr float TrochaRuedas = 0.085f;
constexpr float VelocidadRuedaMaxima = 1.0f;
constexpr int ZonaMuertaPwm = 40;
constexpr float TauRuedaEstimador = 0.06f;
constexpr float RadioSalidaEstimado = 0.15f;
constexpr float IncertSalidaCentro = 0.06f;
constexpr float RadioSalidaRound3 = 0.295f;
constexpr float IncertSalidaRound3 = 0.03f;
constexpr float IncertRumboRound3 = 0.3f;
constexpr float ErrorDistancia = 0.3f;
constexpr float ErrorGiro = 0.25f;
constexpr float DerivaRumbo = 0.3f;
constexpr float EmpujonAtaque = 0.15f;
constexpr float EmpujonContacto = 0.4f;
constexpr float EmpujonLateral = 0.2f;
constexpr float AnguloLineaLado = 0.6f;
constexpr float IncertAnguloLinea = 0.5f;
constexpr float IncertPosicionLinea = 0.02f;
constexpr float SigmasSeguridad = 1.0f;
constexpr float MargenBorde = 0.09f;
constexpr float DesaceleracionFreno = 4.0f;
constexpr float RetardoReaccion = 0.04f;
constexpr int VelocidadMinimaEstimador = 100;
constexpr float IncertPosicionConfiable = 0.08f;
constexpr float IncertRumboConfiable = 0.8f;

constexpr int PatronBusqueda = 1;
constexpr int PorcentajeArcoBusqueda = 50;
constexpr unsigned long TiempoArcoBusqueda = 900;
constexpr unsigned long TiempoArranqueBusqueda = 400;
constexpr unsigned long TiempoArranqueSuave = 1000;
constexpr int RampaPwmPorMs = 1;

constexpr bool DipActivoBajo = true;
constexpr int VelocidadGiroRound4 = 120;
constexpr unsigned long TiempoMaxGiroRound4 = 1000;
constexpr int VelocidadGiroInicio = 180;
constexpr int VelocidadGiroRound2 = 150;
constexpr unsigned long TiempoMaxGiroEspalda = 500;
constexpr unsigned long TiempoMaxGiroLado = 500;
constexpr unsigned long TiempoEsquivaRound1 = 0;
constexpr unsigned long TiempoEsquivaRound2 = 0;
constexpr int VelocidadEsquiva = 160;
constexpr bool PivoteRound2 = true;
constexpr int VelocidadPivoteInicio = 180;
constexpr int VelocidadAvanceInicio = 40;
constexpr unsigned long TiempoAvanceInicio = 4000;
constexpr unsigned long TiempoAceleracionRound3 = 2500;
constexpr bool EsperarRound3 = false;
constexpr unsigned long TiempoEsperaRound3 = 3000;
constexpr int VelocidadEmbestidaInicio = 160;
constexpr int VelocidadEmbestidaMaxima = 160;
constexpr int VelocidadAtaqueRound12 = 160;
constexpr unsigned long TiempoEmbestidaInicio = 800;

constexpr unsigned long ConfirmacionDeteccion = 5;
constexpr unsigned long TiempoMinimoGiroEspalda = 80;
constexpr unsigned long TiempoMinimoGiroLado = 60;
constexpr unsigned long TiempoMinimoAvanceInicio = 150;
constexpr unsigned long TiempoMinimoGiroLateral = 60;

constexpr bool ModuloArranqueActivoAlto = true;
constexpr unsigned long FiltroModuloArranqueMs = 30;
constexpr unsigned long FiltroParadaModuloMs = 150;
constexpr unsigned long EsperaInicioCombateMs = 5000;

constexpr unsigned long TiempoReanudarCombate = 500;
constexpr bool ReiniciarTrasParada = true;
constexpr unsigned long TiempoMinimoParaReanudar = 1000;

constexpr int rutinaSegunInterruptores(int dip) {
    return (dip & 3) == 0 ? 1 : (dip & 3) == 1 ? 2 : (dip & 3) == 2 ? 3 : 4;
}

constexpr int RutinaForzada = -1;
constexpr int LadoForzado = 0;

#endif
