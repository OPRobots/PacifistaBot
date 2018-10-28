/**
 * Fichero con los movimientos y posiciones básicos del robot.
 * 
 * @file Movimientos.ino
 * @author Álex Santos
 * @date 2018-09-23
 */

/**
 * Mueve todos los servos a su posición estandar/inicial.
 * 
 */
void posicion_estandar() {

  POSICION = POSICION_ESTANDAR;

  for (int servo = 0; servo < NUM_SERVOS_PIERNA_IZQUIERDA; servo++) {
    servosPiernaIzquierda[servo].attach(pinesServosPiernaIzquierda[servo]);
    set_servo_position(TIPO_SERVO_PIERNA_IZQUIERDA, servo, posicionesEstandarPiernaIzquierda[servo]);
  }
  for (int servo = 0; servo < NUM_SERVOS_PIERNA_DERECHA; servo++) {
    servosPiernaDerecha[servo].attach(pinesServosPiernaDerecha[servo]);
    set_servo_position(TIPO_SERVO_PIERNA_DERECHA, servo, posicionesEstandarPiernaDerecha[servo]);
  }
  for (int servo = 0; servo < NUM_SERVOS_CADERA; servo++) {
    servosCadera[servo].attach(pinesServosCadera[servo]);
    servosCadera[servo].write(posicionesEstandarCadera[servo]);
  }
  for (int servo = 0; servo < NUM_SERVOS_BRAZO_IZQUIERDO; servo++) {
    servosBrazoIzquierdo[servo].attach(pinesServosBrazoIzquierdo[servo]);
    set_servo_position(TIPO_SERVO_BRAZO_IZQUIERDO, servo, posicionesEstandarBrazoIzquierdo[servo]);
  }
  for (int servo = 0; servo < NUM_SERVOS_BRAZO_DERECHO; servo++) {
    servosBrazoDerecho[servo].attach(pinesServosBrazoDerecho[servo]);
    set_servo_position(TIPO_SERVO_BRAZO_DERECHO, servo, posicionesEstandarBrazoDerecho[servo]);
  }
}

/**
 * Mueve los servos de las piernas para agachar el robot y bajar su centro de gravedad.
 * 
 */
void posicion_agachado() {
  POSICION = POSICION_AGACHADO;

  const byte numServos = 8;
  short ajustesAgacharse[numServos][5];
  byte servosAgacharse[numServos][2];
  short posicionesObjetivo[numServos];

  servosAgacharse[0][TIPO_SERVO] = TIPO_SERVO_PIERNA_DERECHA;
  servosAgacharse[0][POS_SERVO] = POS_SERVO_TOBILLO;

  servosAgacharse[1][TIPO_SERVO] = TIPO_SERVO_PIERNA_DERECHA;
  servosAgacharse[1][POS_SERVO] = POS_SERVO_PIERNA;

  servosAgacharse[2][TIPO_SERVO] = TIPO_SERVO_PIERNA_IZQUIERDA;
  servosAgacharse[2][POS_SERVO] = POS_SERVO_TOBILLO;

  servosAgacharse[3][TIPO_SERVO] = TIPO_SERVO_PIERNA_IZQUIERDA;
  servosAgacharse[3][POS_SERVO] = POS_SERVO_PIERNA;

  servosAgacharse[4][TIPO_SERVO] = TIPO_SERVO_CADERA;
  servosAgacharse[4][POS_SERVO] = POS_SERVO_CADERA_DE;

  servosAgacharse[5][TIPO_SERVO] = TIPO_SERVO_CADERA;
  servosAgacharse[5][POS_SERVO] = POS_SERVO_CADERA_IZ;

  servosAgacharse[6][TIPO_SERVO] = TIPO_SERVO_PIERNA_IZQUIERDA;
  servosAgacharse[6][POS_SERVO] = POS_SERVO_PIE;

  servosAgacharse[7][TIPO_SERVO] = TIPO_SERVO_PIERNA_DERECHA;
  servosAgacharse[7][POS_SERVO] = POS_SERVO_PIE;

  posicionesObjetivo[0] = 28;
  posicionesObjetivo[1] = 20;
  posicionesObjetivo[2] = 110;
  posicionesObjetivo[3] = 63;
  posicionesObjetivo[4] = 95;
  posicionesObjetivo[5] = 82;
  posicionesObjetivo[6] = 64;
  posicionesObjetivo[7] = 58;

  for (int servo = 0; servo < numServos; servo++) {
    int pos_actual = get_posicion_actual(servosAgacharse[servo][TIPO_SERVO], servosAgacharse[servo][POS_SERVO]);
    int desfase = pos_actual - posicionesObjetivo[servo];

    ajustesAgacharse[servo][OFFSET] = pos_actual;
    ajustesAgacharse[servo][PERIODO] = 1000;
    ajustesAgacharse[servo][AMPLITUD] = abs(desfase);
    ajustesAgacharse[servo][FASE] = desfase > 0 ? 180 : 0;
    ajustesAgacharse[servo][DEFAULT] = 0;
  }
  ejecutar_movimiento(servosAgacharse, ajustesAgacharse, numServos, 0.25f);
}

/**
 * Alterna entre las dos posiciones de hombros: Lateral y Frontal
 * 
 */
void posicion_hombros() {
  const byte numServos = 2;
  short ajustesHombros[numServos][5];
  byte servosHombros[numServos][2];
  short posicionesObjetivo[numServos];

  servosHombros[0][TIPO_SERVO] = TIPO_SERVO_BRAZO_IZQUIERDO;
  servosHombros[0][POS_SERVO] = POS_SERVO_HOMBRO;

  servosHombros[1][TIPO_SERVO] = TIPO_SERVO_BRAZO_DERECHO;
  servosHombros[1][POS_SERVO] = POS_SERVO_HOMBRO;

  switch (MODO_HOMBROS) {
  case MODO_HOMBROS_ADELANTE:
    posicionesEstandarBrazoIzquierdo[POS_SERVO_HOMBRO] = 125;
    posicionesEstandarBrazoDerecho[POS_SERVO_HOMBRO] = 43;
    break;
  case MODO_HOMBROS_ATRAS:
    posicionesEstandarBrazoIzquierdo[POS_SERVO_HOMBRO] = 45;
    posicionesEstandarBrazoDerecho[POS_SERVO_HOMBRO] = 123;
    break;
  }

  posicionesObjetivo[0] = posicionesEstandarBrazoIzquierdo[POS_SERVO_HOMBRO];
  posicionesObjetivo[1] = posicionesEstandarBrazoDerecho[POS_SERVO_HOMBRO];

  for (int servo = 0; servo < numServos; servo++) {
    int pos_actual = get_posicion_actual(servosHombros[servo][TIPO_SERVO], servosHombros[servo][POS_SERVO]);
    int desfase = pos_actual - posicionesObjetivo[servo];

    ajustesHombros[servo][OFFSET] = pos_actual;
    ajustesHombros[servo][PERIODO] = 1000;
    ajustesHombros[servo][AMPLITUD] = abs(desfase);
    ajustesHombros[servo][FASE] = desfase > 0 ? 180 : 0;
    ajustesHombros[servo][DEFAULT] = 0;
  }

  ejecutar_movimiento(servosHombros, ajustesHombros, numServos, 0.25f);
}

/**
 * Extiende el BRAZO IZQUIERDO para realizar un empujón.
 * 
 */
void movimiento_puno_izquierdo() {
  const byte numServos = 1;
  short ajustesPunoIzquierdo[numServos][5];
  byte servosPunoIzquierdo[numServos][2];
  servosPunoIzquierdo[0][TIPO_SERVO] = TIPO_SERVO_BRAZO_IZQUIERDO;
  servosPunoIzquierdo[0][POS_SERVO] = POS_SERVO_BRAZO;

  ajustesPunoIzquierdo[0][OFFSET] = get_posicion_actual(servosPunoIzquierdo[0][TIPO_SERVO], servosPunoIzquierdo[0][POS_SERVO]);
  ajustesPunoIzquierdo[0][PERIODO] = 1200;
  ajustesPunoIzquierdo[0][AMPLITUD] = 90;
  ajustesPunoIzquierdo[0][FASE] = 180;
  ajustesPunoIzquierdo[0][DEFAULT] = 1;

  ejecutar_movimiento(servosPunoIzquierdo, ajustesPunoIzquierdo, numServos, 0.5f);
}

/**
 * Extiende el BRAZO DERECHO para realizar un empujón.
 * 
 */
void movimiento_puno_derecho() {
  const byte numServos = 1;
  short ajustesPunoDerecho[numServos][5];
  byte servosPunoDerecho[numServos][2];
  servosPunoDerecho[0][TIPO_SERVO] = TIPO_SERVO_BRAZO_DERECHO;
  servosPunoDerecho[0][POS_SERVO] = POS_SERVO_BRAZO;

  ajustesPunoDerecho[0][OFFSET] = get_posicion_actual(servosPunoDerecho[0][TIPO_SERVO], servosPunoDerecho[0][POS_SERVO]);
  ajustesPunoDerecho[0][PERIODO] = 1200;
  ajustesPunoDerecho[0][AMPLITUD] = 80;
  ajustesPunoDerecho[0][FASE] = 0;
  ajustesPunoDerecho[0][DEFAULT] = 1;

  ejecutar_movimiento(servosPunoDerecho, ajustesPunoDerecho, numServos, 0.5f);
}

/**
 * Realiza un movimiento similar al de sentadillas, agachandose y volviendo a la posición inicial.
 * 
 */
void movimiento_sentadillas() {

  const byte numServos = 4;
  short ajustesSentadillas[numServos][5];
  byte servosSentadillas[numServos][2];

  servosSentadillas[0][TIPO_SERVO] = TIPO_SERVO_PIERNA_IZQUIERDA;
  servosSentadillas[0][POS_SERVO] = POS_SERVO_PIERNA;

  servosSentadillas[1][TIPO_SERVO] = TIPO_SERVO_PIERNA_IZQUIERDA;
  servosSentadillas[1][POS_SERVO] = POS_SERVO_TOBILLO;

  servosSentadillas[2][TIPO_SERVO] = TIPO_SERVO_PIERNA_DERECHA;
  servosSentadillas[2][POS_SERVO] = POS_SERVO_PIERNA;

  servosSentadillas[3][TIPO_SERVO] = TIPO_SERVO_PIERNA_DERECHA;
  servosSentadillas[3][POS_SERVO] = POS_SERVO_TOBILLO;

  ajustesSentadillas[0][OFFSET] = get_posicion_actual(servosSentadillas[0][TIPO_SERVO], servosSentadillas[0][POS_SERVO]);
  ajustesSentadillas[0][PERIODO] = 2000;
  ajustesSentadillas[0][AMPLITUD] = 60;
  ajustesSentadillas[0][FASE] = 180;
  ajustesSentadillas[0][DEFAULT] = 1;

  ajustesSentadillas[1][OFFSET] = get_posicion_actual(servosSentadillas[1][TIPO_SERVO], servosSentadillas[1][POS_SERVO]);
  ajustesSentadillas[1][PERIODO] = 2000;
  ajustesSentadillas[1][AMPLITUD] = 60;
  ajustesSentadillas[1][FASE] = 0;
  ajustesSentadillas[1][DEFAULT] = 1;

  ajustesSentadillas[2][OFFSET] = get_posicion_actual(servosSentadillas[2][TIPO_SERVO], servosSentadillas[2][POS_SERVO]);
  ajustesSentadillas[2][PERIODO] = 2000;
  ajustesSentadillas[2][AMPLITUD] = 60;
  ajustesSentadillas[2][FASE] = 0;
  ajustesSentadillas[2][DEFAULT] = 1;

  ajustesSentadillas[3][OFFSET] = get_posicion_actual(servosSentadillas[3][TIPO_SERVO], servosSentadillas[3][POS_SERVO]);
  ajustesSentadillas[3][PERIODO] = 2000;
  ajustesSentadillas[3][AMPLITUD] = 60;
  ajustesSentadillas[3][FASE] = 180;
  ajustesSentadillas[3][DEFAULT] = 1;

  ejecutar_movimiento(servosSentadillas, ajustesSentadillas, numServos, 0.5f);
}

/**
 * Realiza un movimiento de desplazamiento lateral hacia la izquierda.
 * 
 * @param repeticiones Número de veces que realiza el movimiento, por cada orden detectada.
 */
void movimiento_lateral_izquierda(int repeticiones) {
  for (byte loops = 0; loops < repeticiones; loops++) {
    const byte numServos = 7;
    short ajustesMovimientoLateralIzquierda[numServos][5];
    byte servosMovimientoLateralIzquierda[numServos][2];
    int periodo = 500;

    servosMovimientoLateralIzquierda[0][TIPO_SERVO] = TIPO_SERVO_PIERNA_IZQUIERDA;
    servosMovimientoLateralIzquierda[0][POS_SERVO] = POS_SERVO_PIERNA;

    servosMovimientoLateralIzquierda[1][TIPO_SERVO] = TIPO_SERVO_PIERNA_IZQUIERDA;
    servosMovimientoLateralIzquierda[1][POS_SERVO] = POS_SERVO_TOBILLO;

    servosMovimientoLateralIzquierda[2][TIPO_SERVO] = TIPO_SERVO_CADERA;
    servosMovimientoLateralIzquierda[2][POS_SERVO] = POS_SERVO_CADERA_IZ;

    servosMovimientoLateralIzquierda[3][TIPO_SERVO] = TIPO_SERVO_PIERNA_IZQUIERDA;
    servosMovimientoLateralIzquierda[3][POS_SERVO] = POS_SERVO_PIE;

    servosMovimientoLateralIzquierda[4][TIPO_SERVO] = TIPO_SERVO_PIERNA_DERECHA;
    servosMovimientoLateralIzquierda[4][POS_SERVO] = POS_SERVO_PIERNA;

    servosMovimientoLateralIzquierda[5][TIPO_SERVO] = TIPO_SERVO_PIERNA_DERECHA;
    servosMovimientoLateralIzquierda[5][POS_SERVO] = POS_SERVO_TOBILLO;

    servosMovimientoLateralIzquierda[6][TIPO_SERVO] = TIPO_SERVO_CADERA;
    servosMovimientoLateralIzquierda[6][POS_SERVO] = POS_SERVO_CADERA_DE;

    ajustesMovimientoLateralIzquierda[0][OFFSET] = get_posicion_actual(servosMovimientoLateralIzquierda[0][TIPO_SERVO], servosMovimientoLateralIzquierda[0][POS_SERVO]);
    ajustesMovimientoLateralIzquierda[0][PERIODO] = periodo;
    ajustesMovimientoLateralIzquierda[0][AMPLITUD] = 20;
    ajustesMovimientoLateralIzquierda[0][FASE] = 180;
    ajustesMovimientoLateralIzquierda[0][DEFAULT] = 1;

    ajustesMovimientoLateralIzquierda[1][OFFSET] = get_posicion_actual(servosMovimientoLateralIzquierda[1][TIPO_SERVO], servosMovimientoLateralIzquierda[1][POS_SERVO]);
    ajustesMovimientoLateralIzquierda[1][PERIODO] = periodo;
    ajustesMovimientoLateralIzquierda[1][AMPLITUD] = 20;
    ajustesMovimientoLateralIzquierda[1][FASE] = 0;
    ajustesMovimientoLateralIzquierda[1][DEFAULT] = 1;

    ajustesMovimientoLateralIzquierda[2][OFFSET] = get_posicion_actual(servosMovimientoLateralIzquierda[2][TIPO_SERVO], servosMovimientoLateralIzquierda[2][POS_SERVO]);
    ajustesMovimientoLateralIzquierda[2][PERIODO] = periodo;
    ajustesMovimientoLateralIzquierda[2][AMPLITUD] = 5;
    ajustesMovimientoLateralIzquierda[2][FASE] = 180;
    ajustesMovimientoLateralIzquierda[2][DEFAULT] = 1;

    ajustesMovimientoLateralIzquierda[3][OFFSET] = get_posicion_actual(servosMovimientoLateralIzquierda[3][TIPO_SERVO], servosMovimientoLateralIzquierda[3][POS_SERVO]);
    ajustesMovimientoLateralIzquierda[3][PERIODO] = periodo;
    ajustesMovimientoLateralIzquierda[3][AMPLITUD] = 9;
    ajustesMovimientoLateralIzquierda[3][FASE] = 180;
    ajustesMovimientoLateralIzquierda[3][DEFAULT] = 1;

    ajustesMovimientoLateralIzquierda[4][OFFSET] = get_posicion_actual(servosMovimientoLateralIzquierda[4][TIPO_SERVO], servosMovimientoLateralIzquierda[4][POS_SERVO]);
    ajustesMovimientoLateralIzquierda[4][PERIODO] = periodo;
    ajustesMovimientoLateralIzquierda[4][AMPLITUD] = 10;
    ajustesMovimientoLateralIzquierda[4][FASE] = 180;
    ajustesMovimientoLateralIzquierda[4][DEFAULT] = 1;

    ajustesMovimientoLateralIzquierda[5][OFFSET] = get_posicion_actual(servosMovimientoLateralIzquierda[5][TIPO_SERVO], servosMovimientoLateralIzquierda[5][POS_SERVO]);
    ajustesMovimientoLateralIzquierda[5][PERIODO] = periodo;
    ajustesMovimientoLateralIzquierda[5][AMPLITUD] = 10;
    ajustesMovimientoLateralIzquierda[5][FASE] = 0;
    ajustesMovimientoLateralIzquierda[5][DEFAULT] = 1;

    ajustesMovimientoLateralIzquierda[6][OFFSET] = get_posicion_actual(servosMovimientoLateralIzquierda[6][TIPO_SERVO], servosMovimientoLateralIzquierda[6][POS_SERVO]);
    ajustesMovimientoLateralIzquierda[6][PERIODO] = periodo;
    ajustesMovimientoLateralIzquierda[6][AMPLITUD] = 15;
    ajustesMovimientoLateralIzquierda[6][FASE] = 0;
    ajustesMovimientoLateralIzquierda[6][DEFAULT] = 1;

    ejecutar_movimiento(servosMovimientoLateralIzquierda, ajustesMovimientoLateralIzquierda, numServos, 0.5f);
    delay(50);
  }
}

/**
 * Realiza un movimiento de desplazamiento lateral hacia la derecha.
 * 
 * @param repeticiones Número de veces que realiza el movimiento, por cada orden detectada.
 */
void movimiento_lateral_derecha(int repeticiones) {
  for (byte loops = 0; loops < repeticiones; loops++) {
    const byte numServos = 7;
    short ajustesMovimientoLateralDerecha[numServos][5];
    byte servosMovimientoLateralDerecha[numServos][2];
    int periodo = 500;

    servosMovimientoLateralDerecha[0][TIPO_SERVO] = TIPO_SERVO_PIERNA_DERECHA;
    servosMovimientoLateralDerecha[0][POS_SERVO] = POS_SERVO_PIERNA;

    servosMovimientoLateralDerecha[1][TIPO_SERVO] = TIPO_SERVO_PIERNA_DERECHA;
    servosMovimientoLateralDerecha[1][POS_SERVO] = POS_SERVO_TOBILLO;

    servosMovimientoLateralDerecha[2][TIPO_SERVO] = TIPO_SERVO_CADERA;
    servosMovimientoLateralDerecha[2][POS_SERVO] = POS_SERVO_CADERA_DE;

    servosMovimientoLateralDerecha[3][TIPO_SERVO] = TIPO_SERVO_PIERNA_DERECHA;
    servosMovimientoLateralDerecha[3][POS_SERVO] = POS_SERVO_PIE;

    servosMovimientoLateralDerecha[4][TIPO_SERVO] = TIPO_SERVO_PIERNA_IZQUIERDA;
    servosMovimientoLateralDerecha[4][POS_SERVO] = POS_SERVO_PIERNA;

    servosMovimientoLateralDerecha[5][TIPO_SERVO] = TIPO_SERVO_PIERNA_IZQUIERDA;
    servosMovimientoLateralDerecha[5][POS_SERVO] = POS_SERVO_TOBILLO;

    servosMovimientoLateralDerecha[6][TIPO_SERVO] = TIPO_SERVO_CADERA;
    servosMovimientoLateralDerecha[6][POS_SERVO] = POS_SERVO_CADERA_IZ;

    ajustesMovimientoLateralDerecha[0][OFFSET] = get_posicion_actual(servosMovimientoLateralDerecha[0][TIPO_SERVO], servosMovimientoLateralDerecha[0][POS_SERVO]);
    ajustesMovimientoLateralDerecha[0][PERIODO] = periodo;
    ajustesMovimientoLateralDerecha[0][AMPLITUD] = 20;
    ajustesMovimientoLateralDerecha[0][FASE] = 0;
    ajustesMovimientoLateralDerecha[0][DEFAULT] = 1;

    ajustesMovimientoLateralDerecha[1][OFFSET] = get_posicion_actual(servosMovimientoLateralDerecha[1][TIPO_SERVO], servosMovimientoLateralDerecha[1][POS_SERVO]);
    ajustesMovimientoLateralDerecha[1][PERIODO] = periodo;
    ajustesMovimientoLateralDerecha[1][AMPLITUD] = 20;
    ajustesMovimientoLateralDerecha[1][FASE] = 180;
    ajustesMovimientoLateralDerecha[1][DEFAULT] = 1;

    ajustesMovimientoLateralDerecha[2][OFFSET] = get_posicion_actual(servosMovimientoLateralDerecha[2][TIPO_SERVO], servosMovimientoLateralDerecha[2][POS_SERVO]);
    ajustesMovimientoLateralDerecha[2][PERIODO] = periodo;
    ajustesMovimientoLateralDerecha[2][AMPLITUD] = 5;
    ajustesMovimientoLateralDerecha[2][FASE] = 0;
    ajustesMovimientoLateralDerecha[2][DEFAULT] = 1;

    ajustesMovimientoLateralDerecha[3][OFFSET] = get_posicion_actual(servosMovimientoLateralDerecha[3][TIPO_SERVO], servosMovimientoLateralDerecha[3][POS_SERVO]);
    ajustesMovimientoLateralDerecha[3][PERIODO] = periodo;
    ajustesMovimientoLateralDerecha[3][AMPLITUD] = 9;
    ajustesMovimientoLateralDerecha[3][FASE] = 0;
    ajustesMovimientoLateralDerecha[3][DEFAULT] = 1;

    ajustesMovimientoLateralDerecha[4][OFFSET] = get_posicion_actual(servosMovimientoLateralDerecha[4][TIPO_SERVO], servosMovimientoLateralDerecha[4][POS_SERVO]);
    ajustesMovimientoLateralDerecha[4][PERIODO] = periodo;
    ajustesMovimientoLateralDerecha[4][AMPLITUD] = 10;
    ajustesMovimientoLateralDerecha[4][FASE] = 0;
    ajustesMovimientoLateralDerecha[4][DEFAULT] = 1;

    ajustesMovimientoLateralDerecha[5][OFFSET] = get_posicion_actual(servosMovimientoLateralDerecha[5][TIPO_SERVO], servosMovimientoLateralDerecha[5][POS_SERVO]);
    ajustesMovimientoLateralDerecha[5][PERIODO] = periodo;
    ajustesMovimientoLateralDerecha[5][AMPLITUD] = 10;
    ajustesMovimientoLateralDerecha[5][FASE] = 180;
    ajustesMovimientoLateralDerecha[5][DEFAULT] = 1;

    ajustesMovimientoLateralDerecha[6][OFFSET] = get_posicion_actual(servosMovimientoLateralDerecha[6][TIPO_SERVO], servosMovimientoLateralDerecha[6][POS_SERVO]);
    ajustesMovimientoLateralDerecha[6][PERIODO] = periodo;
    ajustesMovimientoLateralDerecha[6][AMPLITUD] = 15;
    ajustesMovimientoLateralDerecha[6][FASE] = 180;
    ajustesMovimientoLateralDerecha[6][DEFAULT] = 1;

    ejecutar_movimiento(servosMovimientoLateralDerecha, ajustesMovimientoLateralDerecha, numServos, 0.5f);
    delay(50);
  }
}