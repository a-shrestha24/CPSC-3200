//Aaron Shrestha
//Started 4-1-2023
//Revised 4-4-2023
//P1.cs
using System;
namespace P1
{
    public class P1
    {
        static void Main(string[] args)
        {
            //Lumen array
            Lumen[] array = new Lumen[10];


            //Filling out array with Lumen objects with default
            //Post condition = 5 values should be the exact same
            for (int i = 0; i < 5; i++)
            {
                array[i] = new Lumen();
                
            }
            //Postcondtion = 5 values will be differnt then ones with default numbers
            array[5] = new Lumen(90, 24,22);
            array[6] = new Lumen(10, 24,87);
            array[7] = new Lumen(820, 30,77);
            array[8] = new Lumen(20, 14,24);
            array[9] = new Lumen(10, 52,32);


            

            //calls glow on each of the lumen objects in array
            //Expected output is 5 should be same g value, other should differ
            for (int i = 0; i < 10; i++)
            {

                int g_value = array[i].Glow();
                Console.Write($"The g value is {g_value} \n");

            }

            //testing reset
            //Only 5 objects will have enough glows for reset
            //Postcondition = Error will be thrown for not enough glows met
            for (int i = 0; i <= 4; i++)
            {
                array[0].Glow();
                array[1].Glow();
                array[2].Glow();
                array[3].Glow();
                array[4].Glow();
            }

            for (int i = 0; i < 10; i++)
            {
                array[i].Reset();
            }

        }
    }
}

