//Aaron Shrestha
//Started 4-11-2023
//Revised 4-12-2023

#ifndef Nova_H
#define Nova_H

#include <iostream>
#include "Lumen.h"
using namespace std;
//Nova class
//Class Invariants
// - Size is the number of lumen objects in the LumenArray
// - LumenArray is a dynamcially allocated array that holds lumens in the Nova class
// - checker is a a dynamcially allocated array that holds each lumens count of recharge requests
// - minG and maxG hold the max and min g values in a Nova objects
// - Lumen objects brightness grows as index increases
// - Glow function updates the minG and maxG values at each glow
// - reChargeAll checks if half of the Lumens are inactive. If so all will recharge
// - Replace, replaces lumen objects when glowrequests are met.
// -Copy constructors and assigment operators are added as both arrays will be dynamically allocated to the heap
class Nova
{
    private:
    
    Lumen * LumenArray;//array to hold all lumens
    int * checker; //checker array to hold all recharge requests for each lumen object
    int size; //size of lumen array
    
    int maxG;
    int minG;

    public:

    Nova(int brightness, int power, int numLumen);//Constructor
    Nova(const Nova& copy); //Copy Constructor
    Nova& operator=(const Nova& copy); //Overload Operator 
    Nova(Nova&& copy);//Move Constructor
    Nova& operator=(Nova&& copy); //Move Assigment Operator
    ~Nova(); //Destructor

    void glow(int a);
    int getMin();
    int getMax();
    void reChargeAll(); //recharages all lumens when condition is met
    void replace();

};
#endif
//Implementation Invariants
// - If a lumen object needs 2 recharges it will be replaced which is done in the replace functions.
// they will be replaced with Lumen objects with defalut values
// - Recharge will check all inactive lumen though a count of in active lumens though the isOn function
// - Glow request will check if maxG and minG will be updated through checks 
// - maxG and minG will start at -1 as G values will not be negative
// - In glow a guard clause as an if stament will proctect the user from trying to put a number higher then
// max size
// -Desctroctor will delete both arrays as both are on the heap. 
// -Glow function will check in the end if all will recharge and if any lumens need to be reset. 
// -Error handling = In the constructor if negative numbers are thrown then defalut values will be put in for 
// the brightness, power,and numLumens
