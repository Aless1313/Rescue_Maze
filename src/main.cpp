#include <Arduino.h>


/*Declaración de variables para dirección de motores*/
/*Siguiendo la siguiente estructura*/

/*------------------ADELANTE---------------*/
/*m1_1/m1_2                       m2_1/m2_2*/
/*Delante Izq                   Delante Der*/
/*                                         */
/*                                         */
/*m3_1/m3_2                        m4_1/4_2*/
/*Atras Izq                       Atras Der*/
/*---------------------ATRAS---------------*/

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

}

//Función para ir hacia adelante
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

//LA TABLA LÓGICA DE LOS GIROS ESTA EN ESTA CARPETA CON EL NOMBRE "Tabla logica.png"
//Los giros estan en la imagen "Giros de robot.png"



void loop() {

  //Para establecer una velocidad a los motores hacemos
  //una escritura analogica, ponemos el pin de velocidad
  //de motor y la velocidad a asignar donde 255 es la máxima
  analogWrite(enA, 255);    //Velocidad máxima
  analogWrite(enB, 255);    //Velocidad máxima

  analogWrite(enC, 255);    //Velocidad máxima
  analogWrite(enD, 255);    //Velocidad máxima
  
  //Para mover el robot mandamos a llamar a las funciones 
  //declaradas arriba, seguido de un delay de duración y 
  //la siguiente accion

  //Ejemplo si queremos mover hacia adelante 1 segundo
  //luego detenerse 2 segundos
  //luego ir atras 1 segundo

  adelante();
  delay(1000);
  stop();
  delay(2000);
  atras();
  delay(1000);

  //la acción pasada la hizo con la velocidad establecida en las lineas 144-148
  //Si queremos modificar la velocidad volvemos a hacer una escritura analogica con los nuevos valores de velocidad

  analogWrite(enA, 150);    //Velocidad media
  analogWrite(enB, 150);    //Velocidad media

  analogWrite(enC, 150);    //Velocidad media
  analogWrite(enD, 150);    //Velocidad media

  //Volvemos a hacer los movimientos pero con la nueva velocidad 
  adelante();
  delay(1000);
  stop();
  delay(2000);
  atras();
  delay(1000);

  //Debio realizar lo mismo pero a menor velocida

}

//INDICACIONES IMPORTANTES
//Si el robot en la función adelante algún motor va en dirección contraria intercambiar los cables de giro en el puente h 
//de ese motor en especifico 




