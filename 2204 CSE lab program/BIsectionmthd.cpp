#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
double a, b, c, d;
double valueCheck(double x)
{
    float ans = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
    return ans;
}	
int main()
{
    cout << "Equation is: ax^3+bx^2+cx+d=0\n";
    cout << "Enter the value of a, b, c and d: ";
    cin >> a >> b >> c >> d;
    int choice = -1;
    while (choice != 3)
    {
        system("cls");
        double i = 0;
        double x = 0;
        double y = 0;
        double prev=0;
        double root;
        int p = 0;
        int q = 0;
        cout << "1.Bisection Method\n2.False Position Method\n3.Exit\n";
        cout << "Enter the method: ";
        cin >> choice;
        while (true)
        {
            if (valueCheck(i) < 0 && p == 0)
            {
                x = i;
                p = 1;
            }
            else if (valueCheck(i) > 0 && q == 0)
            {
                y = i;
                q = 1;
            }
            double j = 0 - i;
            if (valueCheck(j) < 0 && p == 0)
            {
                x = j;
                p = 1;
            }
            else if (valueCheck(j) > 0 && q == 0)
            {
                y = j;
                q = 1;
            }
            if (p != 0 && q != 0)
            {
                break;
            }
            i++;
        }
        double Xr;
        int k = 1;
        while (true)
        {
            if (choice == 1)
            {
                Xr = (x + y) / 2;
            }
            else
            {
                double f = valueCheck(x);
                double g = valueCheck(y);
                Xr = (x * g - y * f) / (g - f);
            }
            if (fabs(Xr-prev) <= 0.0001)
            {
                break;
            }
            if (valueCheck(Xr) < 0)
            {
                x = Xr;
            }
            else if (valueCheck(Xr) > 0)
            {
                y = Xr;
            }
            else
            {
                break;
            }
            prev=Xr;
            cout << k << " | " << x << " | " << y << " | " << Xr << " | " << valueCheck(Xr) << " | " << fabs(valueCheck(Xr)) << endl;
            cout << "___________________________________________________" << endl;
            k++;
        }
        cout << "So root is: " << Xr << endl;
        cout << endl;
        getch();
    }
    return 0;
}
