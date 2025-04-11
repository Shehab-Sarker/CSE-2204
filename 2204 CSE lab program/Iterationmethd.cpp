#include<bits/stdc++.h>

/*
Define function f(x) which is to be solved
*/
#define f(x)   sin(x)-10*x+10
/*
Rewrite f(x) as x=g(x) and define g(x) here 
*/
#define g(x)   1+(sin(x)/10)
using namespace std;

int main(){
    int step=1,N;
    double x0,x1,e;

    cout<<setprecision(3)<<fixed;
    
    //inputs
    cout<<"Enter inital guess: ";
    cin>>x0;

    cout<<"Enter tolerable error: ";
    cin>>e;

    cout<<"Enter maximum iteration: ";
    cin>>N;

    //Implementing Fixed Point Iteration
    cout<<"\n******************************"<<endl;
    cout<<"Fixed Point Iteration Method"<<endl;
    cout<<"*******************************"<<endl;

    do{
        x1=g(x0);
        cout<<"Iteration-"<<step<<":\t x1 = "<<setw(10)<<x1<<" and f(x1) = "<<setw(10)<<f(x1)<<endl;
        
        step++;
        if(step>N){
            cout<<"Not Convergent.";
            break;
        }
        x0=x1;
    }while(fabs(f(x1))>e);

    cout<<"\nRoot is : "<<x1;

    return 0;
}