#include <iostream>
#include "String.h"

// I have two main. If I unable this one, then I have to disable the one at the end of test.cpp.
// I do not know how to do it otherwise :S

int main()
{
    String myString(100);

    myString.append("Hello");
    myString.appendLine(", World!");
    myString.append("Alli");
    myString.appendLine("hopa!");
    myString.print(std::cout);
    
    return 0;
}