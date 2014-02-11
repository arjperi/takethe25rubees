/*
Author : Arjun Periasamy Rajagopalan <aperiasa@umass.edu>
Date : 10th Feb 2014
*/
#include <iostream>
#include <stack>

using namespace std;
typedef struct balancedStack
{
    stack<char> charStack;
    int position;
    //balancedStack * next;
};
int main ()
{
    //stack<char> dataStack;
    balancedStack dataStack;
    string inputString = "a*{[(b+c)-alpha]+ g}";       //using string only to find the length of array that will be needed using str.length()
    //cout << inputString.length() << endl;
    char stringArray[] = "a*{[(b+c)-alpha]+ g}";       //C++ allows dynamic char array.
    dataStack.position = 0;         // initial array index
    while( dataStack.position != inputString.length())
    {
        char bracePosistion = dataStack.position;       // cast integer to char to push and pop into the char array
        if(stringArray[dataStack.position] == '{' || stringArray[dataStack.position] == '[' || stringArray[dataStack.position] == '(' )
        {
            dataStack.charStack.push(bracePosistion);
            dataStack.charStack.push(stringArray[dataStack.position]);
        }
        if(stringArray[dataStack.position] == '}')
        {
            if(dataStack.charStack.empty())
            {
                cout << "Stack empty" << endl;
                return false;
            }
            if (dataStack.charStack.top() == '{')
            {
                dataStack.charStack.pop();
                dataStack.charStack.pop();
            }
            else
            {
                cout << "couldn't find a match for } at position" << dataStack.position << endl;
            }
        }
        if(stringArray[dataStack.position] == ']')
        {
            if(dataStack.charStack.empty())
            {
                cout << "Stack empty" << endl;
                return false;
            }
            if (dataStack.charStack.top() == '[')
            {
                dataStack.charStack.pop();
                dataStack.charStack.pop();
            }
            else
            {
                cout << "couldn't find a match for ] at position" << dataStack.position << endl;
            }
        }
        if(stringArray[dataStack.position] == ')')
        {
            if(dataStack.charStack.empty())
            {
                cout << "Stack empty" << endl;
                return false;
            }
            if (dataStack.charStack.top() == '(')
            {
                dataStack.charStack.pop();
                dataStack.charStack.pop();
            }
            else
            {
                cout << "couldn't find a match for ) at position" << dataStack.position << endl;
            }

        }
        dataStack.position++;   // static need to use something like a SP- this works leave untouched
    }
    if (dataStack.charStack.empty())
    {
        cout << "The string is balanced" << endl;
    }
    //char yPos;
    while (!dataStack.charStack.empty())
    {
        char xBrace = dataStack.charStack.top();
        dataStack.charStack.pop();
        char yPos = dataStack.charStack.top();
        int pos = yPos;                         //cast char back to int
        dataStack.charStack.pop();
        cout << "Couldn't find a match for " << xBrace << " at position " << pos << endl;
    }


}
