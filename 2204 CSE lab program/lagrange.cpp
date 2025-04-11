#include<bits/stdc++.h>
using namespace std;

// To represent a data point corresponding to x and y = f(x)
struct Data
{
    int x, y;
};

double interpolate(Data f[], int xi, int n)
{
    double result = 0; 

    for (int i = 0; i < n; i++)
    {
        
        double term = f[i].y;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
                term = term * (xi - f[j].x) / double(f[i].x - f[j].x);
        }

        result += term;
    }

    return result;
}


int main()
{
    int n;

    cout << "Enter the number of data points: ";
    cin >> n;

    Data f[n]; 

    cout << "Enter the data points (x and y) one by one:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Data point " << i + 1 << ":\n";
        cout << "x = ";
        cin >> f[i].x;
        cout << "y = ";
        cin >> f[i].y;
    }

    int xi;
    cout << "Enter the value of x for which you want to find f(x): ";
    cin >> xi;

    cout << "Value of f(" << xi << ") is: " << interpolate(f, xi, n) << endl;

    return 0;
}
