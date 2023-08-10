//Aaron Shrestha
//Started 4-10-2023
//Revised 4-12-2023

#include<iostream>
#include "Lumen.h"


Lumen::Lumen()
{
       
    brightness = DEFALUT_BRIGHTNESS;
    power = DEFALUT_BRIGHTNESS;
    size = DEFALUT_BRIGHTNESS;
        
}

 Lumen::Lumen(int Brightness, int Power, int Size):brightness(Brightness),power(Power),size(Size)
    {   
      

        orignialBrightness = Brightness;
        orignialPower = Power;

        brightness = Brightness;
        power = Power;
        size = Size;

        active = true;
        original = true;
        stable = true;

        glowRequest = DEFALUT_GLOW_REQUEST;
        //error handling for negative numbers
        if (Brightness < 0 || Power < 0 || Size < 0)
        {   brightness = DEFALUT_BRIGHTNESS;
            power = DEFALUT_BRIGHTNESS;
            size = DEFALUT_BRIGHTNESS;
        }

    }
  
    
    //Assigment Operator
    Lumen& Lumen::operator=(const Lumen& copy) {
    if (this != &copy) {
        this->brightness = copy.brightness;
        this->size = copy.size;
        this->power = copy.power;
        this->glowRequest = copy.glowRequest;
        this->original = copy.original;
    }
    return *this;
}
 //Post Condition = Returns if object is active
    bool Lumen:: IsOn() 
    {
        return active;
    }

  //Post Condition = Changes state of object if MINPOWER level not met
    void Lumen:: checkPower()
    {
        if (power < MINPOWER)
        {
            active = false;
        }

    }

//Post Condition = Decrements the power of the object by POWER_DRECEMENT
    void Lumen::lowerPower()
    {
        power -= POWER_DRECEMENT;
    }
//Post Condition = Return bool if original values of objects are set
    //currently
    bool Lumen::IsOriginal()
    {
        return original; 
    }

//Post Condition = Changes the state of the objects orginal bool value when
    //brightness and power of object is not the orginals
    void Lumen::changeOriginal()
    {
        if (brightness != orignialBrightness || power != orignialPower)
        {
            original = false;
        }

    }

 //Post Condition = Decrements the brightness value of an object by
    //BRIGHTNESS_DECREMENT
    void Lumen::dim()
    {
        brightness -= BRIGHTNESS_DECREMENT;
    }

//Pre Condition = Glow function must be ran
//Post Condition = glowRequest value of object increments by 1
    void Lumen::incrementCounter()
    { glowRequest++; }

//Post Condition = state change of object to unstable when brightness value
//is below STABLE_BRIGHTNESS amount
    void Lumen::isStable()
    {
        if (brightness < STABLE_BRIGHTNESS)
        {
            stable = false;
        }

    }
 //Post Condition = g value is returned depending on if object is stable and active
    //glowRequest is incremented, power is checked to be above minimum amount,
    //stability of object is checked, if brightness is above minimum amount,
    //power is lowered.
    //Before g value is returned, orginal bool is set to false.
    int Lumen::Glow()
    {
        incrementCounter();
        int g = 0;
        checkPower();
        isStable();
        lowerPower();
       

        if (!active)
        {
            g = brightness * 20;

        }
        else if (stable)
        {
            g = brightness * power;

        }
        else
        {

            g = size * brightness + size + power;


        }
        changeOriginal();
        return g;

    }

//Pre Condition = Must reach min amount of glow requests
//Post Condition = If glow condtion reached and power is positive objects 
//values will be returned to the orginal values that it started out in
//if 1 condtion is not met, objects brighness will be dimmed. 
    void Lumen::Reset()
    {
        if (glowRequest > COUNTER_MAX && power > 0)
        {
            brightness = orignialBrightness;
            power = orignialPower;
            active = true;
            stable = true;
            glowRequest = DEFALUT_GLOW_REQUEST;
            original = true;
        }
        else if (glowRequest <= COUNTER_MAX && power > 0)
        {
            dim();
            changeOriginal();
            // throw new InvalidOperationException("Glow Requests not met");
        }
    }
    void Lumen::recharge()
    {
        power += 1; //increses power on each recharge.
    }
    