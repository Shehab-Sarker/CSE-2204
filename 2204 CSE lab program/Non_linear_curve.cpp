#include<bits/stdc++.h>
using namespace std;
#define lli long long int
 
int main(){
    double x[20],y[20];
    double sumX=0,sumX2=0,sumY=0,sumXY=0,a,b,A;
    
    int n;
    cout<<"Enter number of data:";
    cin>>n;
    
    cout<<"Enter Data: "<<endl;
    cout<<"x"<<"  "<<"y"<<endl;;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }

    for(int i=0;i<n;i++){
        sumX+=log(x[i]);
        sumX2+=log(x[i])*log(x[i]);
        sumY+=log(y[i]);
        sumXY+=log(x[i])*log(y[i]);

    }

    b=(n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
    A=(sumY-b*sumX)/n;
     
    a=exp(A);
    cout<<"a0 = "<<a<<" and a1 = "<<b<<endl;
    cout<<"Y="<<a<<" *x^"<<b<<endl;
    return 0;
}