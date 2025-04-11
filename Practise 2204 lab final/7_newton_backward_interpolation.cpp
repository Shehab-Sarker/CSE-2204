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

    for(j=1;j<n;j++){
        for(i=j;i<n;i++){
            y[i][j]=y[i][j-1]-y[i-1][j-1];
        }
    }

//      /* Generating Backward Difference Table */
//  for(i = 1; i < n; i++)
//  {
//   for(j = n-1; j > i-1; j--)
//   {
//    y[j][i] = y[j][i-1] - y[j-1][i-1];
//   }
//  }

    cout<<"\nBackward Difference Table"<<endl;
    for(i=0;i<n;i++){
        cout<<x[i];
        for(j=0;j<=i;j++){
            cout<<"\t"<<y[i][j];
        }
        cout<<endl;
    }

    double v,p=1;
    cout<<"Enter the value of X for backward:";
    cin>>v;
    double h=x[1]-x[0], u=(v-x[n-1])/h;
    double sum=y[n-1][0];

    for(j=1;j<n;j++){
        p*=(u-j+1)/j;
        sum+=p*y[n-1][j];
    }

    cout<<"\nThe value of Y at X = "<<v<<" is : "<<sum;
    return 0;
}