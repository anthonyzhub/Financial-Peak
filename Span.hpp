//
//  Span.hpp
//  Quadratic Algorithm
//
//  Created by Anthony Zamora on 10/15/18.
//  Copyright © 2018 Anthony Zamora. All rights reserved.
//

#ifndef Span_hpp
#define Span_hpp

#include <stdio.h>

// string librairies
#include <iostream>
#include <sstream>
#include <fstream>

// Data librairies
#include <stack>
#include <vector>

using namespace std;

class Span
{
private:
    
    // These vectors will import raw data
    vector<double> stockPrice;
    vector<string> stockDate;
    
    // This vector will hold stock's peak
    vector<double> stockPeak;
    
public:
    
    // Import data from text file
    void textReader();
    
    // Simple, but inefficient method
    double * spans1(double *oldArray, int n);
    
    // Complex, but most efficient method
    //double * spans2(double *oldArray, int n);
    double * spans2();
    
    // Print elements in array
    void printArray(double *span);
};

#endif /* Span_hpp */
