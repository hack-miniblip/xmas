// miniblip led matrix demo

#include "mbed.h"
#include "neopixel.h"

// Matrix led output pin
#define DATA_PIN P0_9
#define ANALOG_POTENTIOMETER P0_22
//AnalogIn   ain(ANALOG_POTENTIOMETER);
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

        if(color == 1){ //blanco
        aux[posicion].red = 0x11;
        aux[posicion].blue = 0x11;
        aux[posicion].green = 0x11; 
        
    }
}
//Si color = 1 --> rojo. Si color = 2 --> azul Si color = 3 --> azul
void copos(neopixel::Pixel* aux, int des){ //desplazamiento
    
    void_matrix(aux);
    encenderLed(aux,2+des,1);
    encenderLed(aux,0+des,1);    
    encenderLed(aux,4+des,1);
    encenderLed(aux,6+des,1);
    encenderLed(aux,8+des,1);
    encenderLed(aux,12+des,1);
    encenderLed(aux,10+des,1);
    encenderLed(aux,14+des,1);
    encenderLed(aux,16+des,1);   
    encenderLed(aux,20+des,1);
    encenderLed(aux,18+des,1);
    encenderLed(aux,24+des,1);
    encenderLed(aux,22+des,1);   
    if(des!=0){
        encenderLed(aux,1,1);
        }  
    
}



int main() {
    int i;
    DigitalIn(DATA_PIN, PullDown);
    neopixel::Pixel vector[25];
    
    neopixel::PixelArray array(DATA_PIN);
    
    
    
    while(true){
        
        
        copos(vector,0);
        array.update(vector,25);
        wait_ms(500);    
        copos(vector,3);
        array.update(vector,25);
        wait_ms(500);  
   
    }
    
    
    
    
    
}
