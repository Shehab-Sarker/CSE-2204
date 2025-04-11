#include<bits/stdc++.h>
using namespace std;
#define lli long long int


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

void guass_forward_central_difference(double x[],double y[][20],int n){
    int i,j;
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }

    cout<<"\nForward Difference Table"<<endl;
    for(i=0;i<n;i++){
        cout<<x[i];
        for(j=0;j<n-i;j++){
            cout<<"\t"<<y[i][j];
        }
        cout<<endl;
    }

    double val;
    cout<<"Enter the value:"<<endl;
    cin>>val;

    
    double p = (val - x[n / 2]) / (x[1] - x[0]);
    
    // Calculating the result using the formula
    double sum = y[n / 2][0];
    for (int i = 1; i < n; i++) {
        sum += (p_cal(p, i) * y[(n - i) / 2][i]) / fact(i);
    }

    cout << "\nValue at " << val << " is " << fixed << setprecision(4) << sum << endl;
}

int main(){
    double x[20],y[20][20];
    int i,j,n;
    
    cout<<"Enter number of data:";
    cin>>n;
    
    cout<<"Enter Data: "<<endl;
    cout<<"x"<<"  "<<"y"<<endl;;
    for(i=0;i<n;i++){
        cin>>x[i]>>y[i][0];
    }

    guass_forward_central_difference(x ,y,n);


    return 0;
}