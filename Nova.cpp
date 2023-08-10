//Aaron Shrestha
//Started 4-11-2023
//Revised 4-12-2023

#include<iostream>
#include "Nova.h"
#include "Lumen.h"

//Precondition = Brightness, Power,and number of lumen values must be entered
//Postconditon = A nova object will be made which will have an array of lumen objects entered
// with the brightness and power value increasing as from one object to the next
Nova::Nova(int brightness, int power, int numLumen) 
{
    if(numLumen > 0)//guard clause
    {
        size = numLumen;
   
        LumenArray = new Lumen[numLumen];
        checker = new int[numLumen];
        
        minG = -1;
        maxG = -1;
        for(int i = 0; i < numLumen; i++)
            {
                LumenArray[i] = Lumen(brightness+i, power +i, 100);
                checker[i] = 0;
            }
    } 
    //if negative numbers are put in
     if (brightness < 0 || power < 0 || numLumen < 0)
        {   brightness = 200;
            power = 150;
            size = 10;
        }
   
}

//copy constructor
//Precondition = Called upon by complier when a copy of an object need to be made
//Postcondition = A copy of the Nova object will made with matching values 
Nova::Nova(const Nova& copy) 
{
    size = copy.size;
    LumenArray = new Lumen[size]; // allocate memory for new lumen object
    checker = new int[size];
    for(int i = 0; i < size; i ++)
    {
        LumenArray[i] = copy.LumenArray[i]; //deep copy
        checker[i] = copy.checker[i];
    }
    maxG = copy.maxG;
    minG = copy.minG;
}

// Overloade operator
//Precondition = 2 Nova objects are already created
//Postcondition = the left hand side object will hold  the exact same values as the right hand side object
Nova& Nova::operator=(const Nova& copy)
{ 
    if (this == &copy) //guard clause
    {
        return *this;
    } 
    delete[] LumenArray;
    size = copy.size;
    LumenArray = new Lumen[size];
    for (int i = 0; i < size; i++)
        {
            LumenArray[i] = copy.LumenArray[i];
        }
    return *this;
}

//Move Constructor
//Precondition = Must have a assigned space in memory to hold object
//Postcondition = Nova object being moved will hold the exact same memory as the copy
Nova::Nova(Nova&& copy)
{
    LumenArray = copy.LumenArray;
    size = copy.size;
   
    minG = copy.minG;
    maxG = copy.maxG;

    copy.size = 0;
    copy.minG = 0;
    copy.maxG = 0;



    copy.LumenArray = nullptr;
}

//Move Assigment Operator
//Precondition = Must have a assigned space in memory to hold object
//Postcondtion = Nova object being moved will hold the exact same memory as the copy and will have 
//the original pointer point to null
Nova& Nova:: operator=(Nova&& copy) 
{
        
    for (int i = 0; i < size; i++) {//guard clause
       Lumen temp = LumenArray[i];
       LumenArray[i] = copy.LumenArray[i];
       copy.LumenArray[i] = temp;
    }
    LumenArray = nullptr;
    return *this;
}

//Destructor
//Precondition = LumenArray and checker arrays have been alloacted to the heap
//Postcondition = LumenArray and checker will be destroyed and free from memory
Nova::~Nova()
{
    delete[] LumenArray;
    delete[] checker;
}

//Min
int Nova::getMin()
{
    return minG;
}

//Max
int Nova::getMax()
{
    return maxG;
}

//Glow
//Precondition = Nova object has be instantiated and ran through the checks
//Postcondition = Each lumen object up to int a in the array will have a glow called on them
// max and min g values will be recored. Recharge will be called on Lumen objects that meet requirements
void Nova::glow(int a)
{
    //if user inputs too high of a number it replaces with the max size array can handle
    if (a > size) {
        a = size;
    }
    
    for(int i = 0; i < a; i++){
        int g = LumenArray[i].Glow();
        cout << "g value is " << g <<endl;
        if(g > maxG){
            maxG = g; // Update maxG value
        }
        if(g < minG || minG == -1)
        {
            minG = g; // Update minG value
        }
        
        if(!LumenArray[i].IsOn()) //Lumen object is unstable
        {
            LumenArray[i].recharge();
            checker[i] += 1;
        }
    }
    //recharge check on whole of Lumen array
    reChargeAll();
    //replace check
    replace();
}


//Recharge All
//Precondition = Nova Object has been instantiaed and is valid
//Postcondition = If conditions are met all Lumen objects will be recharged
//Recharge All
//Precondition = Nova Object has been instantiated and is valid
//Postcondition = If conditions are met all Lumen objects will be recharged
void Nova::reChargeAll()
{
    int count = 0; //holds number of lumen objects that are inactive
    
    for(int i = 0; i < size; i++)
    {
        if(!LumenArray[i].IsOn()) //Lumen object is inactive
        {
            count++;
        }
    }
    if(count > (size/2))
    {
        for(int i = 0; i <size; i++)
        {
            LumenArray[i].recharge();
            checker[i] += 1;
        }
    }
    
    
}

//Precondition = Nova Object has been instantiaed and is valid. Glow recharge amount
// in the checkers array must also be met
//Postcodition = All lumen objects who meet requriment of recharge requests will be replaced with defalt values
void Nova::replace()
{
    for(int i = 0; i <= size; i++)
    {
        if(checker[i] >= 7) //if the glow count of lumen object is greater then 2 the lumen is replaced
        {
            LumenArray[i] = Lumen();
            checker[i] = 0;
            
        }
        
    }
}