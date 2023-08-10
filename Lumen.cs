//Aaron Shrestha
//Started 4-1-2023
//Revised 4-4-2023
//Lumen.cs
using System;


public class Lumen
{
    //Class invariant
    // - Power must be above 0 and if not inputed it will be set to Defaut value
    // -Brightness must be above 0 and if not inputed it will be set to Defaut value
    // -Size must be above 0 and if not inputed it will be set to Defaut value
    // -Have 5 glow request before reseting object, if not error code will appear
    // -Can check if Lumen object is back to orignal values
    // -Can check if Lumen object is active

    private const int DEFALUT_POWER = 200;
    private const int DEFALUT_BRIGHTNESS = 100;
    private const int DEFALUT_SIZE = 150;
    private const int DEFALUT_GLOW_REQUEST = 0;
    private const int BRIGHTNESS_DECREMENT = 10;
    private const int MINPOWER = 10;
    private const int POWER_DRECEMENT = 1;
    private const int STABLE_BRIGHTNESS = 80;
    private const int COUNTER_MAX = 5;
    private const int BRIGHTNESS_DRECMENT = 20;
   

    readonly int orignialBrightness;
    readonly int orignialPower;

    private int brightness;
    private readonly int size;
    private int power;

    private bool original;
    public bool active;
    public bool stable;
    private int glowRequest;


    //constructor
    //Post Condidtion = A lumen object will be made with default values or
    //given values
    public Lumen(int Brightness = DEFALUT_BRIGHTNESS, int Power = DEFALUT_POWER,
        int Size =  DEFALUT_SIZE)
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
        if (Brightness < 0 || Power < 0 || Size < 0)
        { throw new InvalidOperationException("Violation of Invariant"); }

    }

    //Post Condition = Returns if object is active
    public bool IsOn
    {
        get { return active; }
    }

    //Post Condition = Changes state of object if MINPOWER level not met
    public void checkPower()
    {
        if (power < MINPOWER)
        {
            active = false;
        }

    }

    //Post Condition = Decrements the power of the object by POWER_DRECEMENT
    private void LowerPower()
    {
        power -= POWER_DRECEMENT;
    }

    //Post Condition = Return bool if original values of objects are set
    //currently
    public bool IsOriginal
    {
        get { return original; }
    }

    //Post Condition = Changes the state of the objects orginal bool value when
    //brightness and power of object is not the orginals
    private void changeOriginal()
    {
        if (brightness != orignialBrightness || power != orignialPower)
        {
            original = false;
        }

    }

    //Post Condition = Decrements the brightness value of an object by
    //BRIGHTNESS_DECREMENT
    private void Dim()
    {
        brightness -= BRIGHTNESS_DECREMENT;
    }

    //Pre Condition = Glow function must be ran
    //Post Condition = glowRequest value of object increments by 1
    private void IncrementCounter()
    { glowRequest++; }

    //Post Condition = state change of object to unstable when brightness value
    //is below STABLE_BRIGHTNESS amount
    private void isStable()
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
    public int Glow()
    {
        IncrementCounter();
        int g = 0;
        checkPower();
        isStable();
        LowerPower();


        if (!active)
        {
            g = brightness - BRIGHTNESS_DRECMENT;

        }
        else if (stable)
        {
            g = brightness * power;

        }
        else
        {

            g = size * brightness - size + power;


        }
        changeOriginal();
        return g;

    }
    //Pre Condition = Must reach min amount of glow requests
    //Post Condition = If glow condtion reached and power is positive objects 
    //values will be returned to the orginal values that it started out in
    //if 1 condtion is not met, objects brighness will be dimmed. 
    public void Reset()
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
            Dim();
            changeOriginal();
            throw new InvalidOperationException("Glow Requests not met");
        }
    }
    //Impllementation Invariants
    // 
    // -Have 5 glow request before reseting object, as 5 is the COUNTERMAX for Reset
    // -Client doesn't have acess to Lumen values of Brightness,Power, or Size,
    // but client can check if lumen is back to orginal values and if object is active.

    // -Original bool is used to check if Reset is done, true when its orginal values
    // -changeOrginal changes bool after each Dim or Glow to make sure object is not
    //  in inital state state

    // -Active and Stable also bools to check objects state
    // -Client can enter values for power,size and brightness, or defalut values will be added
    // client doesn't have the responsibilty of always initializing

    // -checkPower function made for testing reasons and to change state if necessay.
    // -Only throws errors on Constructor and Reset when contract is broken as those are the 2 biggest invariats
    // - In glow, does checks on activity bool, then stable bool, and if none match then it return a erratic g value
    // -OrginalBrightness and OriginalPower is set in contructor so it maybe be always held for reset of object.
    // -Size is a readonly int as it will not change in the lifetime of the program.

}

