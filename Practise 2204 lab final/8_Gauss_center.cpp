#include<bits/stdc++.h>
using namespace std;

double p_cal(double p,int n){
    double temp=p;
    for(int i=1;i<n;i++){
        if(i%2==1){
            temp*=(p-i);
        }else{
            temp*=(p+i);
        }
    }
    return temp;
}

int fact(int n){
    int f=1;
    for(int i=2;i<=n;i++){
        f*=i;
    }  
    return f;
}

void gauss_forward(double x[],double y[][20],int n){
    int i,j;
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++)
        y[j][i]=y[j+1][i-1]-y[j][i-1];
    }

    double val;
    cout<<"Enter the value: ";
    cin>>val;

    double p=(val-x[n/2])/(x[1]-x[0]);
    double sum=y[n/2][0];

    for(i=1;i<n;i++){
        sum+=(p_cal(p,i)*y[(n-i)/2][i]) / fact(i);
    }

    cout<<"\nValue at "<<val<<" is "<<fixed<<setprecision(5)<<sum;
}


int main(){
    double x[20],y[20][20];
    int i,j,n;

    cout<<"Enter number of data: ";
    cin>>n;

    cout<<"Enter Data: "<<endl;
    cout<<"x  y"<<endl;
    for(i=0;i<n;i++){
        cin>>x[i]>>y[i][0];
    }

    gauss_forward(x,y,n);
    return 0;
}