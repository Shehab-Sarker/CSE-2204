#include<bits/stdc++.h>
using namespace std;

// To represent a data point corresponding to x and y = f(x)
struct Data
{
    double x, y;
};

// Function to interpolate the given data points using Lagrange's formula
// xi corresponds to the new data point whose value is to be obtained
// n represents the number of known data points
double interpolate(Data f[], int xi, int n)
{
    double result = 0; // Initialize result

    for (int i = 0; i < n; i++)
    {
        // Compute individual terms of above formula
        double term = f[i].y;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
                term = term * (xi - f[j].x) / double(f[i].x - f[j].x);
        }

        // Add current term to result
        result += term;
    }

    return result;
}

// Driver function to check the program
int main()
{
    int n;

    // Asking user for the number of data points
    cout << "Enter the number of data points: ";
    cin >> n;

    Data f[n]; // Creating an array of n data points

    // Inputting the data points from the user
    cout << "Enter the data points (x and y) one by one:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Data point " << i + 1 << ":\n";
        cout << "x = ";
        cin >> f[i].x;
        cout << "y = ";
        cin >> f[i].y;
    }

    // Input the value of x to find f(x)
    int xi;
    cout << "Enter the value of x for which you want to find f(x): ";
    cin >> xi;

    // Using the interpolate function to obtain a data point
    cout << "Value of f(" << xi << ") is: " << interpolate(f, xi, n) << endl;

    return 0;
}
