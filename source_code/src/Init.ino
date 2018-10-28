/**
 * Fichero con todos los procesos iniciales del programa que se deberán ejecutar una sola vez al inicio del mismo. 
 * 
 * @file Init.ino
 * @author Álex Santos
 * @date 2018-09-23
 */

/**
* Función principal de inicialización de componentes.
*
*/
void init_all() {
  init_serial();
  delay(100);
  init_posiciones_iniciales();
  posicion_estandar();
}

/**
* Inicialización del puerto Serial.
*
*/
void init_serial() {
  Serial.begin(9600);
}

/**
* Establece los valores para las posiciones iniciales de cada grupo de servos
*
*/
void init_posiciones_iniciales() {
  ///////////////////////////////////////////
  // Posiciones iniciales PIERNA IZQUIERDA //
  ///////////////////////////////////////////
  posicionesEstandarPiernaIzquierda[POS_SERVO_PIERNA] = 83;
  posicionesEstandarPiernaIzquierda[POS_SERVO_TOBILLO] = 80;
  posicionesEstandarPiernaIzquierda[POS_SERVO_PIE] = 64;

  posicionesActualesPiernaIzquierda[POS_SERVO_PIERNA] = posicionesEstandarPiernaIzquierda[POS_SERVO_PIERNA];
  posicionesActualesPiernaIzquierda[POS_SERVO_TOBILLO] = posicionesEstandarPiernaIzquierda[POS_SERVO_TOBILLO];
  posicionesActualesPiernaIzquierda[POS_SERVO_PIE] = posicionesEstandarPiernaIzquierda[POS_SERVO_PIE];

  /////////////////////////////////////////
  // Posiciones iniciales PIERNA DERECHA //
  /////////////////////////////////////////
  posicionesEstandarPiernaDerecha[POS_SERVO_PIERNA] = 0;
  posicionesEstandarPiernaDerecha[POS_SERVO_TOBILLO] = 58;
  posicionesEstandarPiernaDerecha[POS_SERVO_PIE] = 58;

  posicionesEstandarPiernaDerecha[POS_SERVO_PIERNA] = posicionesEstandarPiernaDerecha[POS_SERVO_PIERNA];
  posicionesEstandarPiernaDerecha[POS_SERVO_TOBILLO] = posicionesEstandarPiernaDerecha[POS_SERVO_TOBILLO];
  posicionesEstandarPiernaDerecha[POS_SERVO_PIE] = posicionesEstandarPiernaDerecha[POS_SERVO_PIE];

  /////////////////////////////////
  // Posiciones iniciales CADERA //
  /////////////////////////////////
  posicionesEstandarCadera[POS_SERVO_CADERA_IZ] = 82;
  posicionesEstandarCadera[POS_SERVO_CADERA_DE] = 95;

  posicionesActualesCadera[POS_SERVO_CADERA_IZ] = posicionesEstandarCadera[POS_SERVO_CADERA_IZ];
  posicionesActualesCadera[POS_SERVO_CADERA_DE] = posicionesEstandarCadera[POS_SERVO_CADERA_DE];

  //////////////////////////////////////////
  // Posiciones iniciales BRAZO IZQUIERDO //
  //////////////////////////////////////////
  posicionesEstandarBrazoIzquierdo[POS_SERVO_HOMBRO] = 45;
  posicionesEstandarBrazoIzquierdo[POS_SERVO_BRAZO] = 170;

  posicionesActualesBrazoIzquierdo[POS_SERVO_HOMBRO] = posicionesEstandarBrazoIzquierdo[POS_SERVO_HOMBRO];
  posicionesActualesBrazoIzquierdo[POS_SERVO_BRAZO] = posicionesEstandarBrazoIzquierdo[POS_SERVO_BRAZO];

  ////////////////////////////////////////
  // Posiciones iniciales BRAZO DERECHO //
  ////////////////////////////////////////
  posicionesEstandarBrazoDerecho[POS_SERVO_HOMBRO] = 123;
  posicionesEstandarBrazoDerecho[POS_SERVO_BRAZO] = 30;

  posicionesActualesBrazoDerecho[POS_SERVO_HOMBRO] = posicionesEstandarBrazoDerecho[POS_SERVO_HOMBRO];
  posicionesActualesBrazoDerecho[POS_SERVO_BRAZO] = posicionesEstandarBrazoDerecho[POS_SERVO_BRAZO];
}


