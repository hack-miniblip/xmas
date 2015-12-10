// miniblip led matrix demo

#include "mbed.h"
#include "neopixel.h"

// Matrix led output pin
#define DATA_PIN P0_9
#define ANALOG_POTENTIOMETER P0_22
AnalogIn   ain(ANALOG_POTENTIOMETER);
//DigitalIn pushbutton(P0_23);

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
        aux[posicion].red = 0xff;
        aux[posicion].blue = 0x00;
        aux[posicion].green = 0x00;
    }else if(color == 2){
        aux[posicion].red = 0x00;
        aux[posicion].blue = 0xff;
        aux[posicion].green = 0x00;
    }else if(color == 3){
        aux[posicion].red = 0x00;
        aux[posicion].blue = 0x00;
        aux[posicion].green = 0xff;        
    }else if(color == 4){
        aux[posicion].red = 0x00;
        aux[posicion].blue = 0x00;
        aux[posicion].green = 0x00; 
    }else if(color == 5){ //morado
        aux[posicion].red = 0x22;
        aux[posicion].blue = 0x33;
        aux[posicion].green = 0x11; 
    }else if(color == 6){ //blanco
        aux[posicion].red = 0x11;
        aux[posicion].blue = 0x11;
        aux[posicion].green = 0x11; 
        
    }
}
//Si color = 1 --> rojo. Si color = 2 --> azul Si color = 3 --> azul
void copo(neopixel::Pixel* aux){
    
    void_matrix(aux);
    encenderLed(aux,2,6);
    encenderLed(aux,7,6);    
    //encenderLed(aux,12,6);
    encenderLed(aux,13,6);
    encenderLed(aux,17,6);
    encenderLed(aux,22,6);
    encenderLed(aux,14,6);
    encenderLed(aux,11,6);
    encenderLed(aux,10,6);
    //diagonal
    encenderLed(aux,4,6);
    encenderLed(aux,8,6);
    encenderLed(aux,16,6);   
    encenderLed(aux,20,6);
    encenderLed(aux,18,6);
    encenderLed(aux,24,6);
    encenderLed(aux,6,6);
    encenderLed(aux,0,6);      
    
}

void copo2(neopixel::Pixel* aux){
    void_matrix(aux);
    encenderLed(aux,2,6);
    encenderLed(aux,7,6);    
    //encenderLed(aux,12,6);
    encenderLed(aux,13,6);
    encenderLed(aux,17,6);
    encenderLed(aux,22,6);
    encenderLed(aux,14,6);
    encenderLed(aux,11,6);
    encenderLed(aux,10,6);;
    //diagonal
    encenderLed(aux,8,6);
    encenderLed(aux,16,6);   
    encenderLed(aux,18,6);
    encenderLed(aux,6,6); 
}


int main() {
    int i;
    DigitalIn(DATA_PIN, PullDown);
    neopixel::Pixel vector[25];
    
    neopixel::PixelArray array(DATA_PIN);
    
    
    while(true){
        float pot = ain.read() * 100.0f;
        if(pot == 0){
        
            copo(vector);
            array.update(vector,25);
           // if(pushbutton){
                //musica
             //}
             
            
        }else if(pot > 0 && pot <50){
            
            copo2(vector);
            array.update(vector,25);
                
        }else{
            
            copo(vector);
            array.update(vector,25);
            
        }
       wait_ms(500);
    }
    
    
    
    
    
}
