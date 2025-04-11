#include<bits/stdc++.h>
using namespace std;

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

    double v,p=1;
    cout<<"\nEnter the value of X for forward:";
    cin>>v;
    double h=x[1]-x[0];
    double u=(v-x[0])/h;
    double sum=y[0][0];

    for(j=1;j<n;j++){
        p=p*(u-j+1)/j;
        sum+=p*y[0][j];
    }

    cout<<"The value of Y at X = "<<v<<" is : "<<sum<<endl;
    return 0;
}