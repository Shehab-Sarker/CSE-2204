#include<bits/stdc++.h>

/*
Defining equation to be soved.
change this equation to solve another problem.
*/
#define f(x)  3*x-cos(x)-1
/*
Defining derivative of g(x).
As you change f(x), change this function also.
*/
#define g(x)  3+sin(x)
using namespace std;

int main()
{
    double x0,x1,f0,f1,g0,e;
    int step=1, N;

    //Setting precision and writing floating point
    //values in fixed_point notation.
    cout<<setprecision(3)<<fixed;

    //inputs
    cout<<"Enter initial guess: ";
    cin>>x0;
    cout<<"Enter tolerable error: ";
    cin>>e;
    cout<<"Enter maximum iteration: ";
    cin>>N;

    //Implementing Newton Raphson Method
    cout<<"\n********************************\n";
    cout<<"Newton Rapshon Method"<<endl;
    cout<<"********************************"<<endl;

    do{
        f0=f(x0);
        g0=g(x0);

        if(g0==0.0){
            cout<<"Mathmetical Error.";
            break;
        }

        x1=x0-(f0/g0);

        cout<<"Iteration-"<<step<<":\t x = "<<setw(10)<<x1<<" and f(x) = "<<setw(10)<<f(x1)<<endl;
        x0=x1;

        step++;

        if(step>N){
            cout<<"Not Convergent.";
            break;
        }
        f1=f(x1);
    }while(fabs(f1)>e);

    cout<<"\nRoot is: "<<x1;
    return 0;
}

