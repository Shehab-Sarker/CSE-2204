#include<bits/stdc++.h>
using namespace std;
#define lli long long int
 
int main(){
    double x[20],y[20];
    double sumX=0,sumX2=0,sumY=0,sumXY=0,a,b;
    
    int n;
    cout<<"Enter number of data:";
    cin>>n;
    
    cout<<"Enter Data: "<<endl;
    cout<<"x"<<"  "<<"y"<<endl;;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }

    for(int i=0;i<n;i++){
        sumX+=x[i];
        sumX2+=x[i]*x[i];
        sumY+=y[i];
        sumXY+=x[i]*y[i];

    }

    b=(n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);
    a=(sumY-b*sumX)/n;

    cout<<"a0 = "<<a<<" and a1 = "<<b<<endl;
    cout<<"curve fitting is: y = "<<a<<" + "<<b<<"X";
    return 0;
}