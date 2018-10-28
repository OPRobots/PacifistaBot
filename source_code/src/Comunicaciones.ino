/**
 * Fichero con las funciones de detección de comandos enviados por BT y ejecución de acciones.
 * 
 * @file Comunicaciones.ino
 * @author Álex Santos
 * @date 2018-09-23
 */

/**
* Función que se debería llamar en tiempo de ejecución para comprobar si hay órdenes pendientes
* en el Buffer de comunicación Serial.
* Comprueba si la letra recibida está dentro de la lista de comandos aceptados al inicio de Main.ino y
* efectua la operación pertinente.
*/
void update_tasks() {
  if (Serial.available()) {
    // Si hay algo pendiente en el Buffer, lo lee y guarda el tiempo en el que lo leyo.
    last_update = millis();
    byte readByte = Serial.read();

    if ((isDigit((char)readByte) || (char)readByte == '.' || (char)readByte == '-')) {
      // Si es un dígito, signo decimal o signo negativo, lo guarda como un valor.
      valor += (char)readByte;
    } else {
      if (letra != ' ') {
        // Si es una letra y ya hay otra letra ya leída, ejecuta la acción correspondiente a esa letra.
        execute_task(letra, (valor != "") ? valor.toInt() : 0);
      }
      // Llega una nueva letra; limpia el valor anterior y lee la nueva letra.
      valor = "";
      letra = (char)readByte;
    }
  } else if ((millis() - last_update) > 5 && letra != ' ') {
    // Si no se ha recibido nada en los últimos 5ms y hay alguna letra pendiente, ejecuta su acción correspondiente.
    execute_task(letra, (valor != "") ? valor.toInt() : 0);
    letra = ' ';
    valor = "";
  }
}

/**
* Ejecuta el comando enviado mediante BT
* @param comando Letra de la lista de comandos listados al principio del fichero Main.ino
* @param valor   Valor opcional que se usaría para realizar la acción. Pej.: Mover un servo a una determinada posición.
*/
void execute_task(char comando, int valor) {
  switch (comando) {
  case PUNO_DERECHO:
    movimiento_puno_derecho();
    break;
  case PUNO_IZQUIERDO:
    movimiento_puno_izquierdo();
    break;
  case POS_INICIAL:
    posicion_estandar();
    break;
  case DESPL_IZQUIERDA:
    movimiento_lateral_izquierda(1);
    break;
  case DESPL_DERECHA:
    movimiento_lateral_derecha(1);
    break;
  case AGACHARSE:
    posicion_agachado();
    break;
  case HOMBROS_MOD:
    MODO_HOMBROS = MODO_HOMBROS == MODO_HOMBROS_ADELANTE ? MODO_HOMBROS_ATRAS : MODO_HOMBROS_ADELANTE;
    posicion_hombros();
    break;
  }
}
