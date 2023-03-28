#ifndef COLORSTRUCT
#define COLORSTRUCT
#include <Wire.h>
#include "Adafruit_TCS34725.h"


struct Color{
    float color_values[3];

    Adafruit_TCS34725* m_tcs;
    Color(Adafruit_TCS34725* tcs)
    :m_tcs(tcs)
    {}
    int colorSegment(){
        update();
        int color_index = -1;
        float max_value = 0.0f;
        for(int i=0;i<3;i++){
            if (color_values[i]>=max_value){
                color_index = i;
                max_value =color_values[i];
            }
        
        }
        // Serial.println(color_index);
        return color_index;
    }
    void update(){
        float r,  g,  b;
        m_tcs->getRGB(&r,&g,&b);

        color_values[0] =r;
        color_values[1] =g;
        color_values[2] = b;
    }
    void print_color_values(){
        Serial.print(color_values[0]);
        Serial.print(" ");
        Serial.print(color_values[1]);
        Serial.print(" ");
        Serial.println(color_values[2]);
    }
};



#endif