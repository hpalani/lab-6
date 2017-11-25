/*
 NAME: Harish Palani
 CRN: 41600
 ASSIGNMENT: Lab 6
 SOURCES: stackoverflow.com
 */
 
#include <iostream>
#include <string>

using namespace std;

// Functions
void division(int dividend, int divisor);
void reset();

// Variables
int quotient = 0;
int remainder = 0;

int main() {
    int x;
    string in;
    
    /* Accept decimal input */
    cout << "Enter decimal integer below." 
         << endl;
    cin >> in;
    
    try { // Check if x is numeric
        x = stoll(in);
    } catch (exception &e) {
        cout << "\n"
             << "Make sure you're entering a positive integer!"
             << endl;
        cin >> x;
    }
    
    while (x < 1) { // Check if x is negative or zero
        cout << "\n"
             << "Make sure you're entering a positive integer!" 
             << endl;
        cin >> x;
    }
    
    /* Convert decimal to binary */
    int binary[1024];
    int i = 0;
    
    while (x > 0) {
        division(x, 2);
        binary[i] = remainder;
        x = quotient;
        i++;
        reset();
    }
    
    for (int j = i - 1; j >= 0; j--) {
        cout << binary[j];
    }
}

// Iterative implementation of division algorithm
void division(int x, int y) {
    int temp = x;
    
    while (temp >= y) {
        temp = temp - y;
        quotient++; // Total number of y's subtracted is the quotient
    }
    
    // x - yq is equal to the remainder
    remainder = (x) - (y*quotient);
}

// Reset all variables
void reset() {
    quotient = 0;
    remainder = 0;
}