/**
 * Este fichero contendrá todas las funciones responsables de asignar posiciones y gestionar movimientos de todos los servos 
 * 
 * @file ServoControl.ino
 * @author Álex Santos
 * @date 2018-09-23
 */

/**
 * Función para asignar cierto offset(ángulo) a cada uno de los servos
 * 
 * @param tipo_servo    Indica la parte del robot a la que pertenece el Servo
 * @param pos_servo     Indica la posición del servo en el array de objetos Servo
 * @param servo_offset  El ángulo deseado para el Servo indicado
 */
void set_servo_position(byte tipo_servo, byte pos_servo, int servo_offset) {
  switch (tipo_servo) {
  case TIPO_SERVO_PIERNA_IZQUIERDA:
    servosPiernaIzquierda[pos_servo].write(servo_offset);
    posicionesActualesPiernaIzquierda[pos_servo] = servo_offset;
    break;
  case TIPO_SERVO_PIERNA_DERECHA:
    servosPiernaDerecha[pos_servo].write(servo_offset);
    posicionesActualesPiernaDerecha[pos_servo] = servo_offset;
    break;
  case TIPO_SERVO_CADERA:
    servosCadera[pos_servo].write(servo_offset);
    posicionesActualesCadera[pos_servo] = servo_offset;
    break;
  case TIPO_SERVO_BRAZO_IZQUIERDO:
    servosBrazoIzquierdo[pos_servo].write(servo_offset);
    posicionesActualesBrazoIzquierdo[pos_servo] = servo_offset;
    break;
  case TIPO_SERVO_BRAZO_DERECHO:
    servosBrazoDerecho[pos_servo].write(servo_offset);
    posicionesActualesBrazoDerecho[pos_servo] = servo_offset;
    break;
  }
}

/**
 * Desasigna el Servo y lo deja libre de movimiento.
 * Si el servo no estuviese asignado, no realiza ninguna acción. 
 * 
 * @param tipo_servo  Indica la parte del robot a la que pertenece el Servo
 * @param pos_servo   Indica la posición del servo en el array de objetos Servo
 */
void disable_servo(byte tipo_servo, byte pos_servo) {
  switch (tipo_servo) {
  case TIPO_SERVO_PIERNA_IZQUIERDA:
    servosPiernaIzquierda[pos_servo].detach();
    break;
  case TIPO_SERVO_PIERNA_DERECHA:
    servosPiernaDerecha[pos_servo].detach();
    break;
  case TIPO_SERVO_CADERA:
    servosCadera[pos_servo].detach();
    break;
  case TIPO_SERVO_BRAZO_IZQUIERDO:
    servosBrazoIzquierdo[pos_servo].detach();
    break;
  case TIPO_SERVO_BRAZO_DERECHO:
    servosBrazoDerecho[pos_servo].detach();
    break;
  }
}

/**
 * Obtiene la posición actual del servo indicado
 * 
 * @param tipo_servo  Indica la parte del robot a la que pertenece el Servo
 * @param pos_servo   Indica la posición del servo en el array de objetos Servo
 * @return byte Posición actual en grados
 */
byte get_posicion_actual(byte tipo_servo, byte pos_servo) {
  switch (tipo_servo) {
  case TIPO_SERVO_PIERNA_IZQUIERDA:
    return posicionesActualesPiernaIzquierda[pos_servo];
    break;
  case TIPO_SERVO_PIERNA_DERECHA:
    return posicionesActualesPiernaDerecha[pos_servo];
    break;
  case TIPO_SERVO_CADERA:
    return posicionesActualesCadera[pos_servo];
    break;
  case TIPO_SERVO_BRAZO_IZQUIERDO:
    return posicionesActualesBrazoIzquierdo[pos_servo];
    break;
  case TIPO_SERVO_BRAZO_DERECHO:
    return posicionesActualesBrazoDerecho[pos_servo];
    break;
  }
}

/**
 * Función base para la ejecución de movimientos coordinados basados en la librería Oscillator, para gestionar correctamente
 * las funciones senoidales, asi como su duración y repeticiones.
 * 
 * @param servosMovimiento    Array bidimensional que contiene la información (TIPO y POS) de cada servo del movimiento
 * @param ajustesMovimiento   Array bidimensional cuya primera dimensión coincide con el número de servos a usar y cuya 
 *                            segunda dimensión contiene los ajustes de OFFSET, PERIODO, AMPLITUD, FASE y DEFAULT de 
 *                            cada uno de los servos para realizar el movimiento.                     
 * @param numServos           Número de servos que componen el movimiento a realizar para definir el límite de los bucles
 * @param repeticiones        Número de veces que se repetirá el movimiento. Admite valores decimales. Ej.: 1/4 de movimiento serían 0.25 repeticiones.
 */
void ejecutar_movimiento(byte servosMovimiento[][2], short ajustesMovimiento[][5], byte numServos, float repeticiones) {
  // Crea e inicia los osciladores según los ajustes de cada servo.
  Oscillator oscillatorMovimiento[numServos];
  for (byte servo = 0; servo < numServos; servo++) {
    oscillatorMovimiento[servo].setOffset(ajustesMovimiento[servo][OFFSET]);
    oscillatorMovimiento[servo].setPeriod(ajustesMovimiento[servo][PERIODO]);
    oscillatorMovimiento[servo].setAmplitude(ajustesMovimiento[servo][AMPLITUD]);
    oscillatorMovimiento[servo].setPhase(ajustesMovimiento[servo][FASE]);
    oscillatorMovimiento[servo].start();
    oscillatorMovimiento[servo].setTime(millis());
  }

  // Inicia el contador de servos parados e inicia el bucle del movimiento mientras haya servos en movimiento.
  byte countStopped = 0;
  do {
    for (byte servo = 0; servo < numServos; servo++) {
      // Serial.println(oscillatorMovimiento[servo].refresh());
      set_servo_position(servosMovimiento[servo][TIPO_SERVO], servosMovimiento[servo][POS_SERVO], oscillatorMovimiento[servo].refresh());
      if (repeticiones > 0 && oscillatorMovimiento[servo].getLoops() >= repeticiones && oscillatorMovimiento[servo].isRunning()) {
        oscillatorMovimiento[servo].stop();
        countStopped++;
        if (ajustesMovimiento[servo][DEFAULT]) {
          set_servo_position(servosMovimiento[servo][TIPO_SERVO], servosMovimiento[servo][POS_SERVO], ajustesMovimiento[servo][OFFSET]);
        }
      }
    }
  } while (countStopped < numServos);
}
