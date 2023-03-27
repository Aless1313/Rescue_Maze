#include <Arduino.h>


/*Declaración de variables para dirección de motores*/
/*Siguiendo la siguiente estructura*/


            /*----------------SENSOR DELANTERO---------------*/
            /*m1_1/m1_2                             m2_1/m2_2*/
            /**//*Delante Izq                     Delante Der*/  /**/
//SENSOR    /*                                               */  //SENSOR 
//IZQUIERDO /*                                               */  //DERECHO
            /**//*m3_1/m3_2                          m4_1/4_2*/  /**/
            /*Atras Izq                             Atras Der*/
            /*---------------------ATRAS---------------------*/

/*Variables de giro de motor (puente H)*/
#define m1_1 22           //
#define m1_2 23           //
                          // MOTORES DE ADELANTE
#define m2_1 24           //
#define m2_2 25           //

#define m3_1 26           //
#define m3_2 27           //
                          //MOTORES DE ATRAS
#define m4_1 28           //
#define m4_2 29           //

/*Variables para controlar velocidad de motor*/
#define enA 8             //Variable de Velocidad de motor m1
#define enB 9             //Variable de Velocidad de motor m2

#define enC 10            //Variable de Velocidad de motor m3
#define enD 11            //Variable de Velocidad de motor m4

//Variables de sensores ultrasonicos
#define uft 2             //Ultrasonico Frontal Trigger
#define ufe 3             //Ultrasonico Frontal Echo

#define uit 4             //... Izquierdo ...
#define uie 5             //... Izquierdo ...

#define udt 6             //... Derecho ...
#define ude 7             //... Derecho ...

//Variables de pantalla
#define sda 20 
#define scl 21

void adelante();
void atras();
void giroderecha();
void giroizquierda();
void stop();
void lateralderecha();
void lateralizquierda();
void setvelocity();
int ladolibre();
int distanciafrontal();
int distanciaderecha();
int distanciaizquierda();


void setup() {
  pinMode(m1_1, OUTPUT);      //
  pinMode(m1_2, OUTPUT);      //
  pinMode(m2_1, OUTPUT);      //
  pinMode(m2_2, OUTPUT);      // Declaracion de variables de giro de motor como salida
  pinMode(m3_1, OUTPUT);      //
  pinMode(m3_2, OUTPUT);      //
  pinMode(m4_1, OUTPUT);      //
  pinMode(m4_2, OUTPUT);      //

  pinMode(enA, OUTPUT);       //
  pinMode(enB, OUTPUT);       //Declaracion de variables de velocidad de motor como salida
  pinMode(enC, OUTPUT);       //
  pinMode(enD, OUTPUT);       //

  pinMode(uft, OUTPUT);
  pinMode(uit,OUTPUT);        //Declaramos todos los trigger como salida
  pinMode(udt, OUTPUT);

  pinMode(ufe, INPUT);
  pinMode(uie, INPUT);
  pinMode(ude, INPUT);

  digitalWrite(uft, LOW);
  digitalWrite(uit, LOW);     //Iniciamos en Bajo los trigger de los ultrasonicos
  digitalWrite(udt, LOW);

}


void loop() {

  if(distanciafrontal()<10){
    //Si entra aqui es porque se topo una pared frontal
    stop();
    //Poner un tiempo de espera

    //Recibe 1 si hay salida a la derecha
    //Recibe 2 si hay salida a la izquierda
    //Recibe 3 si hay salida para ambos lados
    //Recibe 4 si no hay salida a ningun lado
    switch (ladolibre()){
      case 1:
      break;

      case 2:
      break;

      case 3:
      break;

      case 4:
      break;

    }

  }else{
    //Si no hay pared ir hacia adelante
    setvelocity(150, 150, 150, 150);
    adelante();
  }

}

int distanciafrontal(){
  long time;
  long distanciafrontal;

  digitalWrite(uft, HIGH);
  delayMicroseconds(10);
  digitalWrite(uft, LOW);

  time = pulseIn(ufe, HIGH);
  distanciafrontal = time / 59;

  return distanciafrontal;
}

int distanciaizquierda(){
  long time;
  long distanciaizquierda;

  digitalWrite(uft, HIGH);
  delayMicroseconds(10);
  digitalWrite(uft, LOW);

  time = pulseIn(ufe, HIGH);
  distanciaizquierda = time / 59;

  return distanciaizquierda;
}

int distanciaderecha(){
  long time;
  long distanciaderecha;

  digitalWrite(uft, HIGH);
  delayMicroseconds(10);
  digitalWrite(uft, LOW);

  time = pulseIn(ufe, HIGH);
  distanciaderecha = time / 59;

  return distanciaderecha;
}

void setvelocity(int m1, int m2, int m3, int m4){
  analogWrite(enA, m1);
  analogWrite(enB, m2);
  analogWrite(enC, m3);
  analogWrite(enD, m4);
}

int ladolibre(){

//Devolver 1 si hay salida a la derecha
//Devolver 2 si hay salida a la izquierda
//Devolver 3 si hay salida para ambos lados
//Devolver 4 si no hay salida a ningun lado

  if(distanciaderecha()<10){
    if(distanciaizquierda()<10){
      //Sin salida, devolverse

      return 4;
    }else{
      //Solo salida a la izquierda

      return 2;
    }
  }else{
    if(distanciaizquierda()<10){
      //Solo salida a la derecha

      return 1;
    }else{
      //Salida a ambos lados

      return 3;
    }
  }
}


/************************ FUNCIONES DE MOVIMIENTO DEL ROBOT************************************************/

//Ir adelante
void adelante(){
  digitalWrite(m1_1, HIGH);
  digitalWrite(m1_2, LOW);

  digitalWrite(m2_1, HIGH);
  digitalWrite(m2_2, LOW);

  digitalWrite(m3_1, HIGH);
  digitalWrite(m3_2, LOW);

  digitalWrite(m4_1, HIGH);
  digitalWrite(m4_2, LOW);
}

//Ir atras
void atras(){
  digitalWrite(m1_1, LOW);
  digitalWrite(m1_2, HIGH);

  digitalWrite(m2_1, LOW);
  digitalWrite(m2_2, HIGH);
  
  digitalWrite(m3_1, LOW);
  digitalWrite(m3_2, HIGH);
  
  digitalWrite(m4_1, LOW);
  digitalWrite(m4_2, HIGH);
}

//Giro a la derecha sobre su eje
void giroderecha(){
  digitalWrite(m1_1, HIGH);
  digitalWrite(m1_2, LOW);
  
  digitalWrite(m2_1, LOW);
  digitalWrite(m2_2, HIGH);
  
  digitalWrite(m3_1, HIGH);
  digitalWrite(m3_2, LOW);
  
  digitalWrite(m4_1, LOW);
  digitalWrite(m4_2, HIGH);
}

//Giro a la izquierda sobre su eje
void giroizquierda(){
  digitalWrite(m1_1, LOW);
  digitalWrite(m1_2, HIGH);
  
  digitalWrite(m2_1, HIGH);
  digitalWrite(m2_2, LOW);
  
  digitalWrite(m3_1, LOW);
  digitalWrite(m3_2, HIGH);
  
  digitalWrite(m4_1, HIGH);
  digitalWrite(m4_2, LOW);
}

//Detener el robot
void stop(){
  digitalWrite(m1_1, LOW);
  digitalWrite(m1_2, LOW);
  
  digitalWrite(m2_1, LOW);
  digitalWrite(m2_2, LOW);
  
  digitalWrite(m3_1, LOW);
  digitalWrite(m3_2, LOW);
  
  digitalWrite(m4_1, LOW);
  digitalWrite(m4_2, LOW);
}

//Movimiento lateral a la derecha
void lateralderecha(){
  digitalWrite(m1_1, HIGH);
  digitalWrite(m1_2, LOW);
  
  digitalWrite(m2_1, LOW);
  digitalWrite(m2_2, HIGH);
  
  digitalWrite(m3_1, LOW);
  digitalWrite(m3_2, HIGH);
  
  digitalWrite(m4_1, HIGH);
  digitalWrite(m4_2, LOW);
}

//Movimiento lateral a la izquierda
void lateralizquierda(){
  digitalWrite(m1_1, LOW);
  digitalWrite(m1_2, HIGH);
  
  digitalWrite(m2_1, HIGH);
  digitalWrite(m2_2, LOW);
  
  digitalWrite(m3_1, HIGH);
  digitalWrite(m3_2, LOW);
  
  digitalWrite(m4_1, LOW);
  digitalWrite(m4_2, HIGH);
}
