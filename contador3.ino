/**
 * Otro Contador de pulsaciones del boton
 * Utiliza la Sintaxis attachInterrupt(digitalPinToInterrupt(pin),ISR,modo)
 * ISR es la funcion (o sub-rutina) a llamar para Interrumpir, en este caso "BotonPrecionado"
 * Las Interrupciones se hacen mediante hardware. Por ejemplo, un sensor que detecte un Alto o Bajo.
 * Se puede sacar del modo "SLEEP" mediante una interrupcion.
 * CHANGE RISING y FALLING son las sentencias que acepta el NodeMCU como "modo" en la sintaxis "attachInterrupt"
 * Arduino UNO soporta CHANGE RISING FALLING y LOW
 * Los pines 2 y 3 son los que se utilizan para INTERRUPCIONES en la sintaxis "attachInterrupt".
 */


volatile int contador = 0;
int n = contador;
long Tiempo = 0;  //variable global para el tiempo


void setup() 
{
  pinMode(2, INPUT);  //detecta a traves del pin 2 las interrupciones del pulsador del protoboard
  Serial.begin(9600);
  attachInterrupt( digitalPinToInterrupt(2), BotonPrecionado, RISING);
}

void loop() 
{
  if (n != contador)
    {
      Serial.print("Interrupcion N:");
      Serial.println(contador);
      n = contador;
    }
}

/*

void BotonPrecionado()  //las funciones van fuera del "void loop()".
{
  if (millis() > Tiempo + 250)
  {
    contador++;
    Tiempo = millis();
  } 
}

*/

void BotonPrecionado()
{
  if (TiempoCumplido())
  {
    contador = contador + 1;
    Tiempo = millis();
  } 
}

bool TiempoCumplido() /funcion que determina el tiempo entre pulsaciones del boton...
{
    if (millis() > Tiempo + 250)
    {
      return true
    }
    else
    {
      return false;
    }
}
