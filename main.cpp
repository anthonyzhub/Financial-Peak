//
//  main.cpp
//  Quadratic Algorithm
//
//  Created by Anthony Zamora on 10/11/18.
//  Copyright © 2018 Anthony Zamora. All rights reserved.
//

#include <iostream>
#include "Span.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    // Initialize "Span" class
    Span spanInitial;
    
    // Import data
    spanInitial.textReader();
    
    // Retrieve spans and print it
    double *spanArray = spanInitial.spans2();
    spanInitial.printArray(spanArray);
}
