#include <Arduino.h>
bool ioBlink = false;
unsigned long milold;
int rndTemp =0;
//Parpadeo para alarmas 
void blinkSingle(int speed, int pin){
    if ((milold + speed) < millis())
    {
        milold = millis();
        if (ioBlink ==false)
        {
            digitalWrite(pin,HIGH);
            ioBlink = true;
        }
        else
        {
            digitalWrite(pin,LOW);
            ioBlink = false;
        }
    } 
}
//Parpadeo asincronico Tiempo On y Tiempo Off tiempo variable 
void blinkSingleAsy(int timeHigh, int timelow, int pin){
    if (ioBlink == false)
    {
        if ((milold + timeHigh) < millis())
        {
            milold = millis();
            digitalWrite(pin,LOW);
            ioBlink = true;
        }
    }else
    {
        if ((milold + timelow) < millis())
        {
            milold = millis();
            digitalWrite(pin,HIGH);
            ioBlink = false;
        }       
    }
}
//Parpadeo de los led al compartir informacion en TX y RX
void  blinkRandomSingle(int minTime, int maxTime, int  pin){
    if ((milold + rndTemp) <millis())
    {   milold = millis();
        rndTemp = random(minTime,maxTime);
        if (ioBlink == false)
        {
            digitalWrite(pin,HIGH);
            ioBlink = true;
        }
        else{
            digitalWrite(pin,LOW);
            ioBlink = false;
        }   
    }
}
//Led encendido
void ledEncendido(int pin){
    digitalWrite(pin,HIGH);
}
//Led Apagado
void ledApagado(int pin){
    digitalWrite(pin,LOW);
}