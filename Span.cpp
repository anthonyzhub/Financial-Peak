//
//  Span.cpp
//  Quadratic Algorithm
//
//  Created by Anthony Zamora on 10/15/18.
//  Copyright © 2018 Anthony Zamora. All rights reserved.
//

#include "Span.hpp"

void Span::textReader()
{
    // Declare variables to hold line and open files
    string line;
    ifstream inFile ("AAPL.txt"); // <- Add directory here.
    
    // Check if file can be opened
    if (inFile.is_open())
    {
        
        int index = 0;
        
        // Go through each line in text
        while (getline(inFile, line))
        {
            istringstream ss(line);
            string date, price;
            
            // Get date
            getline(ss, date, ',');
            stockDate.push_back(date);
            cout<<"Date: "<<stockDate[index];
            
            // Get price
            getline(ss, price, ',');
            stockPrice.push_back(stod(price));
            cout<<"\tPrice: "<<stockPrice[index]<<endl;
            
            // Increment index
            index++;
        }
        
        // Close file when finished
        inFile.close();
        
    } else {
        cout<<"File unopened"<<endl;
    }
}

// The astrik will help to return a pointer of an array
double * Span::spans1(double *oldArray, int n)
{
    // This is a pointer to an array that'll hold "n" digits
    double *newArray = new double[n];
    
    // Current/Starting column of the graph
    int s;
    
    // Identify the span for each column
    for (int i = 0; i <= n - 1; i++)
    {
        // Start at 1
        s = 1;
        
        // While "S" less than or equal to "i" AND previous elements are less than or equal to current element, increase "S"
        // fyi: "While loop" must check from current element to its left side.
        while (s <= i && oldArray[i - s] <= oldArray[i])
        {
            s = s + 1;
        }
        
        // Add "how many spans existed with associated stock price" to array
        newArray[i] = s;
    }
    
    // Return the number of spans.
    return newArray;
}

double * Span::spans2()
{
    // Create an array with "n" size
    double* spanArrayHolder = new double[100];
    
    // Create a stack
    stack<double> sStack;
    
    for (int i = 0; i <= sizeof(stockPrice); i++)
    {
        
        // While stack isn't empty AND top of stack is less than or equal to current price.
        while ((!sStack.empty()) && stockPrice[int(sStack.top())] <= stockPrice[i])
        {
            // Remove first element
            sStack.pop();
            stockDate.pop_back();
        }
        
        // If stack is empty, then add span of current stock price to returnable array
        if (sStack.empty())
        {
            spanArrayHolder[i] = i + 1;
        } else {
            
            // If not, go from current element ("stock price") to the far-left until another element
            // with greater value ("higher stock price") is reached.
            // Subtract difference between current element and higher-valued element
            spanArrayHolder[i] = i - sStack.top();
        }
        
        // Add current stock price to stack.
        sStack.push(i);
    }
    return spanArrayHolder;
}

void Span::printArray(double* spanArray)
{
    cout<<"\nSpans: ";
    
    // Get the span of each price in list
    for (int i = 0; i < sizeof(spanArray); ++i)
    {
        if (spanArray[i - 1] == 1 && spanArray[i] > 1)
        {
            cout<<"\n$"<<stockPrice[i]<<" on "<<stockDate[i];
        }
    }
    cout<<endl;
}
