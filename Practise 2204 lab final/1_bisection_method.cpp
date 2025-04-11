#include<bits/stdc++.h>
using namespace std;

#define f(x) pow(x,3) -x -1

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

    cout<<endl<<"*****Bisection Method*****<<endl;";
    do{
        x=(x0+x1)/2;
        f=f(x);

        cout<<"Iteration-"<<step<<":\t x="<<setw(10)<<x<<" and f(x) = "<<setw(10)<<f(x)<<endl;

        if(f0*f < 0){
            x1=x;
        }else{
            x0=x;
        }

        step++;
    }while(fabs(f)>e);

    cout<<"\nRoot is : "<<x;

    return 0;

}