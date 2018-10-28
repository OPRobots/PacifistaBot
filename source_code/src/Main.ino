///////////////
// LIBRERÍAS //
///////////////
#include <Octosnake.h>
#include <Wire.h>
#include <Servo.h>


///////////////////////////////
// DEFINICIÓN DE MOVIMIENTOS //
///////////////////////////////
#define PUNO_DERECHO 'D'
#define PUNO_IZQUIERDO 'I'
#define INVINCIBLE_MOD 'z'
#define DESPL_DERECHA 'q'
#define DESPL_IZQUIERDA 'e'
#define ROTATE_DERECHA 'R'
#define ROTATE_IZQUIERDA 'L'
#define AGACHARSE 'u'
#define POS_INICIAL 'o'
#define POS_CADERA_D 'l'
#define POS_CADERA_I 'r'
#define POS_CADERA_C 'Y'
#define HOMBROS_MOD 'H'

///////////////////////////////////
// LISTA DE POSICIONES ESTÁTICAS //
///////////////////////////////////
#define POSICION_ESTANDAR 0
#define POSICION_AGACHADO 1
int POSICION = -1;

#define MODO_HOMBROS_ADELANTE 1
#define MODO_HOMBROS_ATRAS 2
int MODO_HOMBROS = 1;

//////////////////////////
// DEFINICIÓN DE SERVOS //
//////////////////////////
#define NUM_SERVOS_PIERNA_IZQUIERDA 3
#define NUM_SERVOS_PIERNA_DERECHA 3
#define NUM_SERVOS_CADERA 2
#define NUM_SERVOS_BRAZO_IZQUIERDO 2
#define NUM_SERVOS_BRAZO_DERECHO 2

/////////////////////
// PINES DE SERVOS //
/////////////////////
short pinesServosPiernaIzquierda[] = {A1, A2, A3}; // En orden: PIERNA, TOBILLO, PIE
short pinesServosPiernaDerecha[] = {8,7,6}; // En orden: PIERNA, TOBILLO, PIE
short pinesServosCadera[] = {A0, 9}; // En orden: IZQUIERDA, DERECHA
short pinesServosBrazoIzquierdo[] = {A4,A5}; // En orden: HOMBRO, BRAZO
short pinesServosBrazoDerecho[] = {5, 4}; // En orden: HOMBRO, BRAZO

////////////////////////////////////
// POSICIONES DE ARRAYS DE SERVOS //
///////////////////////////////////
#define TIPO_SERVO 0
#define POS_SERVO 1

#define TIPO_SERVO_PIERNA_IZQUIERDA 0
#define TIPO_SERVO_PIERNA_DERECHA 1
#define TIPO_SERVO_CADERA 2
#define TIPO_SERVO_BRAZO_IZQUIERDO 3
#define TIPO_SERVO_BRAZO_DERECHO 4

#define POS_SERVO_PIERNA 0
#define POS_SERVO_TOBILLO 1
#define POS_SERVO_PIE 2
#define POS_SERVO_CADERA_IZ 0
#define POS_SERVO_CADERA_DE 1
#define POS_SERVO_HOMBRO 0
#define POS_SERVO_BRAZO 1

////////////////////////////////////
// ARRAYS DE POSICIONES INICIALES //
////////////////////////////////////
byte posicionesEstandarPiernaIzquierda[NUM_SERVOS_PIERNA_IZQUIERDA];
byte posicionesEstandarPiernaDerecha[NUM_SERVOS_PIERNA_DERECHA];
byte posicionesEstandarCadera[NUM_SERVOS_CADERA];
byte posicionesEstandarBrazoIzquierdo[NUM_SERVOS_BRAZO_IZQUIERDO];
byte posicionesEstandarBrazoDerecho[NUM_SERVOS_BRAZO_DERECHO];

///////////////////////////////////
// ARRAYS DE POSICIONES ACTUALES //
///////////////////////////////////
byte posicionesActualesPiernaIzquierda[NUM_SERVOS_PIERNA_IZQUIERDA];
byte posicionesActualesPiernaDerecha[NUM_SERVOS_PIERNA_DERECHA];
byte posicionesActualesCadera[NUM_SERVOS_CADERA];
byte posicionesActualesBrazoIzquierdo[NUM_SERVOS_BRAZO_IZQUIERDO];
byte posicionesActualesBrazoDerecho[NUM_SERVOS_BRAZO_DERECHO];

///////////////////
// OBJETOS SERVO //
///////////////////
Servo servosPiernaIzquierda[NUM_SERVOS_PIERNA_IZQUIERDA];
Servo servosPiernaDerecha[NUM_SERVOS_PIERNA_DERECHA];
Servo servosCadera[NUM_SERVOS_CADERA];
Servo servosBrazoIzquierdo[NUM_SERVOS_BRAZO_IZQUIERDO];
Servo servosBrazoDerecho[NUM_SERVOS_BRAZO_DERECHO];

///////////////////////////////
// POSICIONES DE ARRAYS      //
// POSICIONES DE MOVIMIENTOS //
///////////////////////////////
#define OFFSET 0
#define PERIODO 1
#define AMPLITUD 2
#define FASE 3
#define DEFAULT 4

/////////////////////
// VARIABLES PARA  //
// COMUNICACIÓN BT //
/////////////////////
long last_update;
char letra = ' ';
String valor = "";


void setup() {
  init_all(); 
  delay(2000); 
}

void loop() {
  update_tasks();
}
