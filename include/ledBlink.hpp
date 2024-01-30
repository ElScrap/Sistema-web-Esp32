#include <Arduino.h>
bool ioBlink = false;
unsigned long milold;
int rndTemp =0;
//Parpadeo para alarmas 
void blinkSingle(int speed, int _ping){
    if ((milold + speed) < millis())
    {
        milold = millis();
        if (ioBlink ==false)
        {
            digitalWrite(_ping,HIGH);
            ioBlink = true;
        }
        else
        {
            digitalWrite(_ping,LOW);
            ioBlink = false;
        }
    } 
}
//Parpadeo asincronico Tiempo On y Tiempo Off tiempo variable 
void blinkSingleAsy(int timeHigh, int timelow, int _ping){
    if (ioBlink == false)
    {
        if ((milold + timeHigh) < millis())
        {
            milold = millis();
            digitalWrite(_ping,LOW);
            ioBlink = true;
        }
    }else
    {
        if ((milold + timelow) < millis())
        {
            milold = millis();
            digitalWrite(_ping,HIGH);
            ioBlink = false;
        }       
    }
}
//Parpadeo de los led al compartir informacion en TX y RX
void  blinkRandomSingle(int minTime, int maxTime, int  _ping){
    if ((milold + rndTemp) <millis())
    {   milold = millis();
        rndTemp = random(minTime,maxTime);
        if (ioBlink == false)
        {
            digitalWrite(_ping,HIGH);
            ioBlink = true;
        }
        else{
            digitalWrite(_ping,LOW);
            ioBlink = false;
        }   
    }
}
//Led encendido Led/Relay/Actuador 
void ledEncendido(int _pin){
    digitalWrite(_pin,HIGH);
}
//Led Apagado Led/Relay/Actuador 
void ledApagado(int _ping){
    digitalWrite(_ping,LOW);
}
// Encendido/Agadado un Led/Relay/Actuador segun Estados
void ledEncendidoApagado(int _pin, bool status){
    if(status){
        digitalWrite(_pin, HIGH); 
    }else{
        digitalWrite(_pin, LOW);
    }          
}