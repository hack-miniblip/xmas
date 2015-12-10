// miniblip led matrix demo

#include "mbed.h"
#include "neopixel.h"

// Matrix led output pin
#define DATA_PIN P0_9
#define ANALOG_POTENTIOMETER P0_22
AnalogIn   ain(ANALOG_POTENTIOMETER);
DigitalIn pushbutton(P0_23);


void void_matrix(neopixel::Pixel* aux, int tam=25){
    
    for(int i=0;i<tam;i++){
        aux[i].red=0;
        aux[i].green=0;
        aux[i].blue=0;
    }
}

//Si color = 1 --> rojo. Si color = 2 --> azul Si color = 3 --> azul
void encenderLed(neopixel::Pixel* aux,int posicion,int color){
    
    if(color == 1){
        aux[posicion].red = 0x22;
        aux[posicion].blue = 0x00;
        aux[posicion].green = 0x00;
    }else if(color == 2){
        aux[posicion].red = 0x00;
        aux[posicion].blue = 0x22;
        aux[posicion].green = 0x00;
    }else if(color == 3){
        aux[posicion].red = 0x00;
        aux[posicion].blue = 0x00;
        aux[posicion].green = 0x11;        
    }else if(color == 4){
        aux[posicion].red = 0x00;
        aux[posicion].blue = 0x00;
        aux[posicion].green = 0x00; 
    }else if(color == 5){ //morado
        aux[posicion].red = 0x22;
        aux[posicion].blue = 0x33;
        aux[posicion].green = 0x11; 
    }else if(color == 6){ //blanco
        aux[posicion].red = 0x33;
        aux[posicion].blue = 0x33;
        aux[posicion].green = 0x33; 
        
    }
}
//Si color = 1 --> rojo. Si color = 2 --> azul Si color = 3 --> azul
void arbol(neopixel::Pixel* aux,int color, int color2){
    
    void_matrix(aux);
    encenderLed(aux,2,6);
    encenderLed(aux,7,3);    
    encenderLed(aux,13,color2);
    encenderLed(aux,12,3);
    encenderLed(aux,11,color2);
    encenderLed(aux,19,color);
    encenderLed(aux,18,3);
    encenderLed(aux,17,color);
    encenderLed(aux,16,3);
    encenderLed(aux,15,color);
    encenderLed(aux,22,5);    
    
}
void clear(neopixel::Pixel* aux){
    void_matrix(aux);
    encenderLed(aux,0,4);
}


int main() {
    int i;
    DigitalIn(DATA_PIN, PullDown);
    neopixel::Pixel vector[25];
    
    neopixel::PixelArray array(DATA_PIN);
    
    clear(vector);
    array.update(vector,25);
    
    while(true){
        float pot = ain.read() * 100.0f;
        if(pot == 0){
        
            arbol(vector,3,3);
            array.update(vector,25);
		if(pushbutton){
                estrellapaga(vector,3,3);
                array.update(vector,25);
                wait_ms(500);
                arbol(vector,1,2);
                array.update(vector,25);                         
            }
        
             
            
        }else if(pot > 0 && pot <50){
            
            arbol(vector,2,1);
            array.update(vector,25);
            if(pushbutton){
                estrellapaga(vector,2,1);
                array.update(vector,25);
                wait_ms(500);
                arbol(vector,1,2);
                array.update(vector,25);                         
            }
            
                
        }else{
            
            arbol(vector,1,2);
            array.update(vector,25);
            if(pushbutton){
                estrellapaga(vector,1,2);
                array.update(vector,25);
                wait_ms(500);
                arbol(vector,1,2);
                array.update(vector,25);                         
            }
                
            
            }
            
            wait_ms(500);
    
    }
    
    
    
    
    
}
