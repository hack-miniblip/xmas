// miniblip led matrix demo

#include "mbed.h"
#include "neopixel.h"

// Matrix led output pin
#define DATA_PIN P0_9
#define ANALOG_POTENTIOMETER P0_22
AnalogIn   ain(ANALOG_POTENTIOMETER);
DigitalIn pushbutton(P0_23);

#define MUTE  0.0
#define END   1.0



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
        aux[posicion].red = 0x11;
        aux[posicion].blue = 0x00;
        aux[posicion].green = 0x00;
    }else if(color == 2){
        aux[posicion].red = 0x00;
        aux[posicion].blue = 0x11;
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
        aux[posicion].red = 0x11;
        aux[posicion].blue = 0x11;
        aux[posicion].green = 0x11; 
    }
}
//Si color = 1 --> rojo. Si color = 2 --> azul Si color = 3 --> azul
void X(neopixel::Pixel* aux){
    
    void_matrix(aux);
    encenderLed(aux,4,1);
    encenderLed(aux,8,1);    
    encenderLed(aux,16,1);    
    encenderLed(aux,20,1);
    encenderLed(aux,12,1);
    encenderLed(aux,0,1);    
    encenderLed(aux,6,1); 
    encenderLed(aux,18,1);
    encenderLed(aux,24,1);
    
}

void M(neopixel::Pixel* aux){
    
    void_matrix(aux);
    encenderLed(aux,24,1);
    encenderLed(aux,19,1);    
    encenderLed(aux,14,1);    
    encenderLed(aux,9,1);
    encenderLed(aux,4,1);    
    encenderLed(aux,8,1); 
    encenderLed(aux,12,1);
    encenderLed(aux,6,1);
    encenderLed(aux,0,1);
    encenderLed(aux,5,1);
    encenderLed(aux,10,1);
    encenderLed(aux,15,1);
    encenderLed(aux,20,1);
    }
void A(neopixel::Pixel* aux){
    
    void_matrix(aux);
    encenderLed(aux,23,1);
    encenderLed(aux,18,1);    
    encenderLed(aux,13,1);    
    encenderLed(aux,8,1);
    encenderLed(aux,3,1);  
    encenderLed(aux,12,1);  
    encenderLed(aux,2,1); 
    encenderLed(aux,1,1);
    encenderLed(aux,6,1);
    encenderLed(aux,11,1);
    encenderLed(aux,16,1);
    encenderLed(aux,21,1);
    }
void S(neopixel::Pixel* aux){
    void_matrix(aux);
    encenderLed(aux,1,1);
    encenderLed(aux,2,1);    
    encenderLed(aux,3,1);    
    encenderLed(aux,8,1);
    encenderLed(aux,13,1);    
    encenderLed(aux,12,1);  
    encenderLed(aux,11,1);
    encenderLed(aux,16,1);
    encenderLed(aux,21,1);
    encenderLed(aux,22,1);
    encenderLed(aux,23,1);
    }
    
    void arbol(neopixel::Pixel* aux){
    
    void_matrix(aux);
    encenderLed(aux,2,6);
    encenderLed(aux,7,3);    
    encenderLed(aux,13,1);
    encenderLed(aux,12,3);
    encenderLed(aux,11,2);
    encenderLed(aux,19,1);
    encenderLed(aux,18,3);
    encenderLed(aux,17,2);
    encenderLed(aux,16,3);
    encenderLed(aux,15,2);
    encenderLed(aux,22,5);    
    
}

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
    encenderLed(aux,10,6);;
    //diagonal
    encenderLed(aux,8,6);
    encenderLed(aux,16,6);   
    encenderLed(aux,18,6);
    encenderLed(aux,6,6);
    encenderLed(aux,0,6);
    encenderLed(aux,4,6);
    encenderLed(aux,20,6);
    encenderLed(aux,24,6);
}


void acero(neopixel::Pixel* aux){
    void_matrix(aux);
    encenderLed(aux,0,4);
    }


int main() {
    int i;
    neopixel::Pixel vector[25];
    
    neopixel::PixelArray array(DATA_PIN);
    
    //int contador = 0;
        while(true){
        acero(vector);
        array.update(vector,25); 
        float pot = ain.read() * 100.0f;
        int counter=1;
        if(pushbutton)
            {
            counter++;
            }
        while(counter%2==0){
            
            arbol(vector);
            array.update(vector,25);
            wait(1);
            
            copo(vector);
            array.update(vector,25);
            wait(1);
            
            X(vector);
            array.update(vector,25);            
            wait_ms(500);
                 
            M(vector);
            array.update(vector,25);
            wait_ms(500);
            
            A(vector);
            array.update(vector,25);
            wait_ms(500);
            
            S(vector);
            array.update(vector,25);    
            wait_ms(500);
            
            wait(1);
            
            }
        
        
        if(pot == 0){
        
            arbol(vector);
            array.update(vector,25);
            if(pushbutton)
            {
            counter++;
            }
        
             
            
        }else if(pot > 0 && pot <50){
            copo(vector);
            array.update(vector,25);
            
            if(pushbutton)
            {
            counter++;
            }
                
        }else{
            if(pushbutton)
            {
            counter++;
            }
            
            X(vector);
            array.update(vector,25);            
            wait_ms(500);
                 
            M(vector);
            array.update(vector,25);
            wait_ms(500);
            
            A(vector);
            array.update(vector,25);
            wait_ms(500);
            
            S(vector);
            array.update(vector,25);    
            wait_ms(500);
            
                
            
            }
            
            wait_ms(500);
    
    }
 
    
}
