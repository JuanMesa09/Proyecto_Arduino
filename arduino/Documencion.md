Segundo Parcial SPD  
 Tema: Exposicion de sistema de incendio con arduino


![Imagen del proyecto]()
## Alumno: Juan Mesa


## Consigna:
El objetivo de este proyecto es diseñar un sistema de incendio utilizando Arduino que sea iniciado por un control remoto, que pueda
detectar cambios de temperatura y activar un servo motor en caso de detectar un incendio.
Además, se mostrará la temperatura actual y la estación del año en un display LCD.

Componentes necesarios:
Arduino UNO
Sensor de temperatura
Control remoto IR (Infrarrojo)
Display LCD (16x2 caracteres)
Servo motor
Cables y resistencias según sea necesario
Protoboard para realizar las conexiones
Dos leds.


Funcionalidad requerida:
Conexiones:
Conecta el sensor de temperatura al pin analógico A0 de Arduino.
Conecta el control remoto IR al pin digital 11 de Arduino.
Conecta el display LCD utilizando los pines correspondientes de Arduino.
Conecta el servo motor a uno de los pines PWM de Arduino (por ejemplo, pin 9).

Control remoto:
Configura el control remoto IR para recibir señales.
Define los comandos necesarios para activar y desactivar el sistema de incendio.
Utiliza un algoritmo para determinar la estación del año (por ejemplo, rangos de temperatura
para cada estación).
Detección de temperatura:
Configura el sensor de temperatura y realiza la lectura de la temperatura ambiente.
Muestra la temperatura actual en el display LCD.

Sistema de Procesamiento de Datos

Sistema de alarma:
Define un umbral de temperatura a partir del cual se considera que hay un incendio (por
ejemplo, temperatura superior a 60 grados Celsius).
Cuando se detecta un incendio (temperatura por encima del umbral), se activa el servo
motor para simular una respuesta del sistema de incendio.
Mensajes en el display LCD:
Muestra la temperatura actual y la estación del año en el display LCD.
Cuando se detecta un incendio, muestra un mensaje de alarma en el display LCD.

Punto libre:
Se deberá agregar dos leds y darle una funcionalidad de su elección, acorde al
proyecto previamente detallado.

Recuerda proporcionar un diagrama de conexiones y el código necesario para implementar
cada una de las funcionalidades requeridas. Esto ayudará a comprender y construir el
sistema de incendio con Arduino.




## Descripcion:
Implemente un código en Arduino que tiene la función de controlar un sistema de visualización y control de temperatura utilizando un sensor y una pantalla LCD, además de controlar luces y un servo motor en respuesta a la lectura de temperatura.
    en el mismo utilice 3 funciones las cuales llamo:
-mostrarLcd: es una funcion para mostrarme grados en el led, recibe como parametro un float.
-leerGrado: es una funcion que  lee grados con el sensor de calor, donde vinculo el pin y retorno la lectura.
-giroServo: es una funcion en la que desplazo el motor  don dos movimientos.


## Funcion Principal:

esta es mi funcion pricipal:
float leerGrado(){//funcion que me lea grados
	
	int lecGrado = analogRead(A0);
	float grado = map(lecGrado, 0, 1023, -50, 450);
	
	return grado;
	 
 
 }




```
void setup(){
  
  pinMode(LuzRoja, OUTPUT);
  pinMode(LuzAzul, OUTPUT);
  lcd_1.begin(16, 2);// inicializo lcd
  servo1.attach(9);//inicializo Servo
  servo1.write(0);//defino posicion motor
  IrReceiver.begin(senial, DISABLE_LED_FEEDBACK);//defino senial
 }

void loop(){
if (IrReceiver.decode()) 
{
  Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
  IrReceiver.resume();
}
  if(IrReceiver.decodedIRData.decodedRawData == tecla_encender){
     float grado = leerGrado();//guardo el valor de la funcion
  	 mostrarLcd(grado);//lo muestro
     Serial.println(grado);
    }
  else if(IrReceiver.decodedIRData.decodedRawData == tecla_apagar){
 
  }
 Serial.println(irResults.value, HEX);
}
```

## Link al proyecto en Tinkercad
[Link](https://www.tinkercad.com/things/6L8wfthj6qS-circuito-incendio/editel?sharecode=hdagmvsJg7U1wxT6Bjse5QpBrSktIE2XZYXX1r91DWM)

## Link al codigo completo en GDB Online
[Link](https://onlinegdb.com/O42iY9vEe)

