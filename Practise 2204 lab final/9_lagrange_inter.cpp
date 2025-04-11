#include<bits/stdc++.h>
using namespace std;

double lagrange(vector<pair<double,double>>&f,double val,int n){
    double result=0;
    for(int i=0;i<n;i++){
        double term=f[i].second;

        for(int j=0;j<n;j++){
            if(i!=j){
                term*=(val-f[j].first) / (f[i].first-f[j].first);
            }
        }
        result+=term;
    }

    return result;
}


int main(){
    int n;
    cout<<"Enter the number of data points: ";
    cin>>n;

    vector<pair<double,double>>f(n);
    cout<<"Enter the data points(x and y):"<<endl;
    cout<<"x  y"<<endl;
    for(int i=0;i<n;i++){
        cin>>f[i].first>>f[i].second;
    }

    double val;
    cout<<"Enter the value of x for find f(x):";
    cin>>val;

    cout<<"value of f("<<val<<") is : "<<lagrange(f,val,n)<<endl;
    return 0;
}