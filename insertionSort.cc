#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

class insertionSort
{
public:

    int randomNumberWithinRange(int min,int max)
    {
        int randomSize = 0;
        do
        {
            randomSize = rand()%max;
        }
        while( randomSize < min || randomSize > max );
        return randomSize;
    }

    void doSorting(int data[],int length)
    {
        int i=0,temp=0;
        for(int j =1; j < length;j++)
        {
        //insert this into a sorted array
        i = j;
        while (i>0 && data[i]<data[i-1])
        {
            temp = data[i];
            data[i] = data[i-1];
            data[i-1] = temp;
            i--;
        }
        }
    }


};


int main()
{
    srand (time(NULL));             //random number generation which generates new random generator with each pass
    insertionSort iSort;            //Object of class insertion sort
    int arraySize;
    arraySize = iSort.randomNumberWithinRange(50,1000); //assign random array size for each iteration
    //arraySize = 1000;
    int arrayToBeSorted[arraySize];
    int count = 10;
    while (count != 0)
    {

    for(int k=0;k < arraySize; k++)
    {
        arrayToBeSorted[k] = rand()%999101;               // Insert elements randomly
        //cout << arrayToBeSorted[k]<< "  ";
    }

    cout <<endl<< "arraySize is " << arraySize << " ";
    clock_t clk1, clk2;
    clk1 = clock();
//**********************************************************************************************
    LARGE_INTEGER frequency;        // ticks per second
    LARGE_INTEGER t1, t2;           // ticks
    double elapsedTime;

    // get ticks per second
    QueryPerformanceFrequency(&frequency);

    // start timer
    QueryPerformanceCounter(&t1);
    iSort.doSorting(arrayToBeSorted,arraySize);
    QueryPerformanceCounter(&t2);

    // compute and print the elapsed time in millisec
    elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    //cout << "Iteration number : " << count << " and elapsed time is ";
    cout << elapsedTime << " ms." << endl;
    count--;
    }
//************************************************************************************************
//    cout <<endl<<endl<< "Sorted array" << endl;
//    for(int k=0;k < arraySize; k++)
//    {
//        cout << arrayToBeSorted[k]<< "  ";          // print out the array
//    }
//    return 0;
}
