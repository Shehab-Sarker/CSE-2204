#include<bits/stdc++.h>
using namespace std;


int main() {
    float xp, h, sum = 0.0, term, first_derivative;
    int n, index = 0, flag = 0, sign = 1;

    double x[20],y[20][20];
    int i,j;
    
    //cout<<setprecision(7)<<fixed;
    //Input Section
    cout<<"Enter number of data:";
    cin>>n;
    
    cout<<"Enter Data: "<<endl;
    cout<<"x"<<"  "<<"y"<<endl;;
    for(i=0;i<n;i++){
        cin>>x[i]>>y[i][0];
    }

    // Reading the calculation point
    cout << "Enter at what value of x you want to calculate derivative: ";
    cin >> xp;

    // Checking if the calculation point exists in the x data
    for (int i = 0; i < n; i++) {
        if (fabs(xp - x[i]) < 0.0001) {
            index = i; 
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        cout << "Invalid calculation point. Program exiting..." << endl;
        exit(0);
    }

    
    // Generating Forward Difference Table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    h = x[1] - x[0];

    // Applying the formula for forward difference to calculate derivatives
    for (int i = 1; i < n - index; i++) {
        term = y[index][i]/ i;
        sum += sign * term;
        sign = -sign;
    }

    // Dividing by h
    first_derivative = sum / h;

    // Displaying the result
    cout << "First derivative at x = " << xp << " is " << first_derivative << endl;

    return 0;
}
