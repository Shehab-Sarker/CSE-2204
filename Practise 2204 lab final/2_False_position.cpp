#include<bits/stdc++.h>
using namespace std;

#define f(x) pow(x,3) -2*x -5

int main(){
    double x0,x1,x,f0,f1,f,e;
    int step=1;
    cout<<setprecision(4)<<fixed;

    cout<<"Enter first Guess: ";
    cin>>x0;
    cout<<"Enter second Guess: ";
    cin>>x1;
    cout<<"Enter tolerable Error: ";
    cin>>e;

    f0=f(x0);
    f1=f(x1);
    
    if(f0*f1 >0){
        cout <<"Incorrect Initial Guesses.";
        return 0;
    }

    cout<<endl<<"*****False Position Method*****<<endl;";
    do{
        x=x0-(x1-x0)*f0 / (f1-f0);
        f=f(x);

        cout<<"Iteration-"<<step<<":\t x="<<setw(10)<<x<<" and f(x) = "<<setw(10)<<f(x)<<endl;

        if(f0*f < 0){
            x1=x;
            f1=f;
        }else{
            x0=x;
            f0=f;
        }

        step++;
    }while(fabs(f)>e);

    cout<<"\nRoot is : "<<x;

    return 0;

}