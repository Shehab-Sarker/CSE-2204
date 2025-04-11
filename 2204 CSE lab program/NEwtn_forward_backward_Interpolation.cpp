#include<bits/stdc++.h>
using namespace std;

void forward(double x[],double y[][20],int n){

    int i,j;
    //Generating Forward difference Table
    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }

    //Display forward difference table:
    cout<<"\nForward Difference Table"<<endl;
    for(i=0;i<n;i++){
        cout<<x[i];
        for(j=0;j<n-i;j++){
            cout<<"\t"<<y[i][j];
        }
        cout<<endl;
    }

    double X,p;
    cout<<"\nEnter the value of X for forward:";
    cin>>X;
    double h=x[1]-x[0];
    double u=(X-x[0])/h;
    double sum=y[0][0];
    p=1.0;
    for(j=1;j<n;j++){
        p=p*(u-j+1)/j; 
        sum+=p*y[0][j];
    }
    cout<<"The value of Y at X="<<X<<" is : "<<sum<<endl;
}

void backward(double x[],double y[][20],int n){
    int i,j;
    //Generating backward difference Table
    for(j=1;j<n;j++){
        for(i=j;i<n;i++){
            y[i][j]=y[i][j-1]-y[i-1][j-1];
        }
    }

    //Display backward difference table:
    cout<<"\nBackward Difference Table"<<endl;
    for(i=0;i<n;i++){
        cout<<x[i];
        for(j=0;j<=i;j++){
            cout<<"\t"<<y[i][j];
        }
        cout<<endl;
    }

    double X,p;
    cout<<"Enter the value of X for backward:";
    cin>>X;
    double h=x[1]-x[0];
    double u=(X-x[n-1])/h;
    double sum=y[n-1][0];
    p=1.0;
    for(j=1;j<n;j++){
        p*=(u+j-1)/j; 
        sum+=p*y[n-1][j];
    }
    cout<<"\nThe value of Y at X="<<X<<" is : "<<sum<<endl;
}

int main(){
    double x[20],y[20][20];
    int i,j,n;
    
    //cout<<setprecision(7)<<fixed;
    //Input Section
    cout<<"Enter number of data:";
    cin>>n;
    
    cout<<"Enter Data: "<<endl;
    cout<<"x"<<"  "<<"y"<<endl;;
    for(i=0;i<n;i++){
        cin>>x[i]>>y[i][0];
    }


    int choice=-1;
    while(choice!=3){
        cout<<"Choose Newton's Interpolation Method:"<<endl;
        cout<<"1. Forward difference formula\n2. Backward difference Formula\n3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                forward(x,y,n);
                break;
            case 2:
                backward(x,y,n);
                break;
            case 3:
                cout<<"Exiting program."<<endl;
                break;
            default:
                cout<<"Invail choice.Please try again."<<endl;
                break;
        }
        if(choice!=3){
            cout<<"\nPress Enter to continue....";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}