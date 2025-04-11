#include<bits/stdc++.h>
using namespace std;

#define f(x) cos(x)-2*x+3

#define g(x) (cos(x) +3)/2

int main(){
    int step=1,N;
    double x0,x1,e;

    cout<<setprecision(5)<<fixed;

    cout<<"Enter initial Guess: ";
    cin>>x0;

    cout<<"Enter tolerable error: ";
    cin>>e;

    cout<<"Enter maximum iteration: ";
    cin>>N;

    cout<<"\n******Fixed Point Iteration Method******"<<endl;

    do{
        x1=g(x0);
        cout<<"Iteration-"<<step<<":\t x1 = "<<setw(10)<<x1<<" and f(x1) = "<<setw(10)<<f(x1)<<endl;

        step++;
        if(step > N){
            cout<<"Not Convergent."<<endl;
            exit(0);
        }
        x0=x1;

    }while(fabs(f(x1))>e);

    cout<<"\nRoot is : "<<x1;

    return 0;

}