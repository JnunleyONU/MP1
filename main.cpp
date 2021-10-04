//
//  main.cpp
//  MP1.xcodeproj
//  9/29/2021
//  Jamir Nunley - MP1
//
//  Created by Jamir Nunley on 9/29/21.
//
// Calculates cost of customer's donut purchase in dozens, includes state tax, obtaines amount of payment received and calculates change, executes once per customer

#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <string>
#include <tgmath.h>
using namespace std;

int main() {
    
    // Variable prices of donuts
    double PriceRegular = 0.75;
    double PriceRugularDz = 7.99;
    double PriceFancy = 0.85;
    double PriceFancyDz = 8.49;
    double PriceAppleFritter = 1.50;
    double PriceTax = 0.075;
    
    // Variables of Donut type
    int DonutsR = 0;
    int DonutsF = 0;
    int AppleFritter = 0;
    int DozenR = 0;
    int DozenF = 0;
    
    // Variables of change calculation
    double Change = 0;
    double Pay = 0;
    int UseableChange = 0;
    int Dollar = 0;
    int Quarter = 0;
    int Dime = 0;
    int Nickel = 0;
    int Penny = 0;
    
    // Variables of Donuts W or W/O tax
    double DonutsNoTax = 0;
    double Tax = 0;
    double DonutsTax = 0;
    
    // Order Input
    cout << "Number of Regular donuts ordered: ";
    cin >> DonutsR;            // User input of regular donuts
    cout << "Number of Fancy donuts ordered: ";
    cin >> DonutsF;            // User input of fancy donuts
    cout << "Number of Apple Fritters ordered: ";
    cin >> AppleFritter;       // User input of apple fritter
    
    // Loop Checks for dozen(12) of donuts
    while(DonutsR >=12)
    {
        DonutsR = DonutsR - 12;
        DozenR = DozenR + 1;
    }
    while(DonutsF >=12)
    {
        DonutsF = DonutsF - 12;
        DozenF = DozenF +1;
    }
    
    // Tax calculation of donuts
    DonutsNoTax = (DonutsR * PriceRegular) + (DonutsF * PriceFancy) + (DozenR * PriceRugularDz) + (DozenF * PriceFancyDz) + (AppleFritter * PriceAppleFritter);
    
    // Set tax
    Tax = (DonutsNoTax * PriceTax);
    DonutsTax = (Tax + DonutsNoTax);
    
    // Customer Transaction
    cout << "Customer Owes $" << fixed << setprecision(2) << DonutsTax << endl; // Output amount owed with set decimal
    cout << "Customer Payed $";
    cin >> Pay; // User inputs pay
    
    // Change Calculation
    Change = Pay - DonutsTax; // Set change minus tax
    UseableChange = (Change * 100)+ 0.5;
    Dollar = UseableChange / 100;
    round(UseableChange); // Return integral value of change
    Quarter = (UseableChange - (Dollar * 100)) / 25;
    Dime = (UseableChange - (Dollar * 100) - (Quarter * 25)) / 10;
    Nickel = (UseableChange - (Dollar * 100) - (Quarter * 25) - (Dime * 10)) / 5;
    Penny = (UseableChange - (Dollar * 100) - (Quarter * 25) - (Dime * 10) - (Nickel * 5));
     
    
    // Output Change owed in each currency value
    
    
     if(Change < .001)
     {
         cout << "Exact payment received - no change owed ";
     }
     else
     {
         cout << "Change owed is $ " << Change << " - ";
     }
        
    
    // Output singular or plural
    if (Dollar > 1) {cout << Dollar << " Dollars, ";}
    if (Dollar == 1) {cout << Dollar << " Dollar, ";}
    if (Quarter > 1) {cout << Quarter << " Quarters, ";}
    if (Quarter == 1) {cout << Quarter << " Quarter, ";}
    if (Dime > 1) {cout << Dime << " Dimes, ";}
    if (Dime == 1) {cout << Dime << " Dime, ";}
    if (Nickel > 1) {cout << Nickel << " Nickels, ";}
    if (Nickel == 1) {cout << Nickel << " Nickel, ";}
    if (Penny > 1 ) {cout << Penny << " Pennies. ";}
    if (Penny == 1) {cout << Penny << " Penny. ";}
    
    
    
    return 0;
    

}


