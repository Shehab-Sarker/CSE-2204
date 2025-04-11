#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Function for calculating coefficient of Y
double p_cal(double p, int n) {
    double temp = p;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 1) {
            temp *= (p - i);
        } else {
            temp *= (p + i);
        }
    }
    return temp;
}

// Function for calculating factorial
int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main() {
    // Number of data points
    int n = 7;

    // Storing available x values
    vector<double> x = {1, 1.05, 1.10, 1.15, 1.20, 1.25, 1.30};

    // Storing y values in a 2D vector and initializing the first column with given values
    vector<vector<double>> y(n, vector<double>(n, 0));
    y[0][0] = 2.7183;
    y[1][0] = 2.8577;
    y[2][0] = 3.0042;
    y[3][0] = 3.1582;
    y[4][0] = 3.3201;
    y[5][0] = 3.4903;
    y[6][0] = 3.6693;

    // Generating Gauss's triangle
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]);
        }
    }

    // Printing Gauss's Triangle
    cout << "Gauss's Triangle:\n";
    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
        for (int j = 0; j < n - i; j++) {
            cout << setw(7) << y[i][j] << "\t";
        }
        cout << endl;
    }

    // Value of Y needed to predict at
    double value = 1.17;

    // Calculating p
    double p = (value - x[n / 2]) / (x[1] - x[0]);
    
    // Calculating the result using the formula
    double sum = y[n / 2][0];
    for (int i = 1; i < n; i++) {
        sum += (p_cal(p, i) * y[(n - i) / 2][i]) / fact(i);
    }

    // Displaying the result
    cout << "\nValue at " << value << " is " << fixed << setprecision(4) << sum << endl;

    return 0;
}
