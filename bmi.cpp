// Write a program that prompts the user to enter a weight in pounds and height in inches and
// then displays the BMI. Note that one pound is 0.45359237 kilograms and one inch is
// 0.0254 meters. Listing 4.6 gives the program.

// Conditions
// Below 18.5 Underweight
// 18.5–24.9 Normal
// 25.0–29.9 Overweight
// Above 30.0 Obese

// Enter weight in pounds:
// Enter your weight in pounds: 146
// Enter height in inches: 70
// BMI is 20.95
// Normal
#include <iostream>
using namespace std;

int main()
{
    // Prompt the user to enter weight in pounds and height in inches
    double weight, height;
    cout << "Enter your weight in pounds: ";
    cin >> weight;
    cout << "Enter your height in inches: ";
    cin >> height;

    // Convert weight to kilograms and height to meters
    double weightKg = weight * 0.45359237;
    double heightM = height * 0.0254;

    // Calculate BMI
    double bmi = weightKg / (heightM * heightM);

    // Display the BMI
    cout << "Your BMI is " << bmi << endl;

    // Determine and display the category
    if (bmi < 18.5)
    {
        cout << "Underweight" << endl;
    }
    else if (bmi < 25.0)
    {
        cout << "Normal" << endl;
    }
    else if (bmi < 30.0)
    {
        cout << "Overweight" << endl;
    }
    else
    {
        cout << "Obese" << endl;
    }

    return 0;
}