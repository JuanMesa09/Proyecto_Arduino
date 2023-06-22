//importacción librerias
#include <IRremote.h>
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd_1(2, 3, 4, 5, 6, 7);//vinculo el lcd a los pins

Servo servo1;//nombro motor
//defino luces
#define LuzAzul 13
#define LuzRoja 12

#define tecla_encender 0xFF00BF00
#define tecla_apagar 0xFD02BF00
int senial = 11;
IRrecv irrecv(senial);
decode_results irResults;
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
float leerGrado(){//funcion que me lea grados
	
	int lecGrado = analogRead(A0);
	float grado = map(lecGrado, 0, 1023, -50, 450);
	
	return grado;
	 
 
 }
void mostrarLcd(float grado){//funcion para mostrar grados en led

  if(grado >= -5 and grado <= 10){
    digitalWrite(LuzRoja, LOW);
    digitalWrite(LuzAzul, HIGH);//si es mayor a -5 marco
    lcd_1.setCursor(0, 0);		// verano cantidad de grados
    lcd_1.print(grado);
    lcd_1.print("Grados C");
    lcd_1.setCursor(0, 1);
  	lcd_1.print("(INVIERNO)");
    
       
     }
  else if(grado >=11 and grado <= 17){
    digitalWrite(LuzRoja, LOW);
    digitalWrite(LuzAzul, HIGH);
    lcd_1.setCursor(0, 0);
    lcd_1.print(grado);
    lcd_1.print("Grados C");
    lcd_1.setCursor(0, 1);
  	lcd_1.print("(OTONIO)");
    
       
     }
  else if(grado >= 18 and grado <= 24){
    digitalWrite(LuzRoja, LOW);
    digitalWrite(LuzAzul, HIGH);
    lcd_1.setCursor(0, 0);
    lcd_1.print(grado);
    lcd_1.print("Grados C");
    lcd_1.setCursor(0, 1);
  	lcd_1.print("(PRIMAVERA)");
    
       
     }
  else if(grado >= 26 and grado <= 45){
    digitalWrite(LuzRoja, LOW);
    digitalWrite(LuzAzul, HIGH);
    lcd_1.setCursor(0, 0);
    lcd_1.print(grado);
    lcd_1.print("Grados C");
    lcd_1.setCursor(0, 1);
  	lcd_1.print("(VERANO)");
    
       
     }
  else if(grado >= 60){
    digitalWrite(LuzAzul, LOW);
    digitalWrite(LuzRoja, HIGH);
    lcd_1.setCursor(0, 0);
    lcd_1.print(grado);
    lcd_1.print("Grados C");
    lcd_1.setCursor(0, 0);
  	lcd_1.print("(INCENDIOO!!!)");
    giroServo();
       
     }
  
  delay(1000);
  lcd_1.clear();
  	 
  
  }

void giroServo(){
  
  for (int i = 0; i <= 180; i =  i+5){
    // Desplazamos a la posicion correspondiente
    servo1.write(i);
    delay(50);
     
 	}
  for (int i = 180; i > 0; i =  i-5){
    // volvemos a la posicion correspondiente
    servo1.write(i);
    delay(50);
     
 }
  
}






