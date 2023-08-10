//Aaron Shrestha
//Started 4-10-2023
//Revised 4-12-2023

#ifndef Lumen_h
#define Lumen_h
//Lumen class
//Class invariant
    // - Power must be above 0 and if not inputed it will be set to Defaut value
    // -Brightness must be above 0 and if not inputed it will be set to Defaut value
    // -Size must be above 0 and if not inputed it will be set to Defaut value
    // -Have 5 glow request before reseting object, if not error code will appear
    // -Can check if Lumen object is back to orignal values
    // -Can check if Lumen object is active
class Lumen
{
    private:
        void lowerPower();
        void changeOriginal();
        void dim();
        void incrementCounter();
        void isStable();
        const int DEFALUT_POWER = 200;
        const int DEFALUT_BRIGHTNESS = 100;
        const int DEFALUT_SIZE = 150;
        const int DEFALUT_GLOW_REQUEST = 0;
        const int BRIGHTNESS_DECREMENT = 10;
        const int MINPOWER = 10;
        const int POWER_DRECEMENT = 20;
        const int STABLE_BRIGHTNESS = 80;
        const int COUNTER_MAX = 5;
        const int BRIGHTNESS_DRECMENT = 20;
        int brightness;
        int power;
        int size;
        int glowRequest;
        bool original;
    public:
        int orignialBrightness;
        int orignialPower;
        bool active;
        bool stable;
        
        Lumen();//
        Lumen(int brightness,int power,int size);//constructor //
        bool IsOn(); //
        bool IsOriginal(); //
        int Glow();//
        void checkPower();//
        void Reset();//
        void recharge();//
        Lumen& operator=(const Lumen& other);//Assigment Operator
};
#endif
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