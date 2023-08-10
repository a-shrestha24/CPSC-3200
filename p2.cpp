//Aaron Shrestha
//Started 4-10-2023
//Revised 4-12-2023

//Driver for P2
#include"Nova.h"
#include"Lumen.h"

#include<iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{ 

    Nova A(10,20,7);
    Nova B(12,15,4);
    Nova C(10,14,5);
    cout << endl <<" [TEST 1]" << endl<< endl;
    //Precondition = Nova objects A, B, C must be instantiated
   //Postcondition =  as 4 glow values will print due to B being passed to C which will pass to A
    C= B;
    A = C;
    //
    //Value above lumen size, but guard clause checks error
    A.glow(15); 
    cout << endl;
    //Preconidtion = Glow must be ran to get a min and max value
    //Postconditon = min and max values will display
    cout << "min G value = " << A.getMin() << endl;
    cout << "max G value = " << A.getMax() << endl;

    cout << endl<<" [TEST 2]" << endl<< endl;
    //Precondition = Nova A must be instantiated
    //Postcondition = Nova D will Nova B values and print 4 glow values and all 4 lumens will be replaced
    //due to going over recharge class. They will set back to deflaut values.
    Nova D(A);

    A.glow(5); 
    cout << endl;
    A.glow(5); 
    cout << endl;
    A.glow(5); 
    cout << endl <<"Default Values due to Replacement" << endl;
    A.glow(5);
   cout << endl;
    return 0;
}



//Constructor
// Will take in a Lumen array 



// Nova::Nova(std::shared_ptr<Lumen[]>& arr, int size) 
// {

//     numLumen = size;
//     lumenArray = new Lumen[numLumen];
//     for(int i = 0; i < numLumen; i++)
//     {
//         lumenArray[i] = arr[i];
//     }
//     // Constructor implementation
//     checker = new int[numLumen];
//     minG = -1;
//     maxG = -1;
//      for(int i = 0; i < numLumen; i++)
//         {
//             checker[i] = 0;
//         }
// }