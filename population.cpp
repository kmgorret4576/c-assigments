// (Population projection) UBoS projects population based on the
// following assumptions:
// One birth every 7 seconds
// One death every 13 seconds
// One new immigrant every 45 seconds
// Write a program to display the population for each of the next five years. Assume the current population is 312032486 and one year has 365 days.

#include <iostream>

using namespace std;
int main()
{
    // Define the initial population and the number of seconds in a year
    const long long initial_population = 312032486;
    const int seconds_in_a_year = 365 * 24 * 60 * 60;

    // Calculate the number of births, deaths, and immigrants in one year
    long long births_per_year = seconds_in_a_year / 7;
    long long deaths_per_year = seconds_in_a_year / 13;
    long long immigrants_per_year = seconds_in_a_year / 45;

    // Display the population for each of the next five years
    for (int i = 1; i <= 5; i++)
    {
        long long population = initial_population + (i * (births_per_year - deaths_per_year + immigrants_per_year));
        cout << "Population after " << i << " year(s): " << population << endl;
    }

    return 0;
}