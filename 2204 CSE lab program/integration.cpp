#include<bits/stdc++.h>
using namespace std;

/* Define function here */
#define f(x) 1/(1+x)

using namespace std;
int main()
{
    double lower, upper, integration=0.0, stepSize, k;
    int i, subInterval;
    /* Input */
    
    cout<<"Enter lower limit of integration: ";
    cin>>lower;
    cout<<"Enter upper limit of integration: ";
    cin>>upper;

    int choice=-1;
    while(choice!=4){

        cout<<"Enter the value of h(stepsize()):";
        cin>>stepSize;
        cout<<endl;

        cout<<"Choose Intregration Method:"<<endl;
        cout<<"1. Trapizoidal formula\n2. Simpon's Rule(1/3)\n3.  Simpon's Rule(3/8)\n4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        cout << fixed << setprecision(3);

        switch(choice){
            case 1:
                /* Calculation */
                /* Finding step size */
                subInterval = (upper - lower)/stepSize;
                /* Finding Integration Value */
                integration = f(lower) + f(upper);
            
                for(i=1; i<= subInterval-1; i++)
                {
                 k = lower + i*stepSize;
                 integration = integration + 2 * (f(k));
                }
               
                integration = integration * stepSize/2;
               
                cout<< endl<<"In trapizoidale rule Required value of integration is: "<< integration;
                break;
            case 2:
                /* Calculation */

                /* Finding step size */
                subInterval = (upper - lower)/stepSize;

                /* Finding Integration Value */
                integration = f(lower) + f(upper);

                for(i=1; i<= subInterval-1; i++)
                {
                k = lower + i*stepSize;
                
                if(i%2==0)
                {
                    integration = integration + 2 * (f(k));
                }
                else
                {
                    integration = integration + 4 * (f(k));
                }
                
                }
                
                integration = integration * stepSize/3;
                
                cout<< endl <<"In Simpon's Rule(1/3) value of integration is: "<< integration;
                break;
            case 3:
                /* Calculation */

                /* Finding step size */
                subInterval = (upper - lower)/stepSize;
               
                /* Finding Integration Value */
                integration = f(lower) + f(upper);
               
                for(i=1; i<= subInterval-1; i++)
                {
                 k = lower + i*stepSize;
               
                 if(i%3==0)
                 {
                   integration = integration + 2 * (f(k));
                 }
                 else
                 {
                   integration = integration + 3 * (f(k));
                 }
               
                }
               
                integration = integration * stepSize*3.0/8.0;
               
                cout<< endl <<"In Simpon's Rule(3/8) value of integration is: "<< integration;
                break;
            case 4:
                cout<<"Exiting program."<<endl;
                break;
            default:
                cout<<"Invail choice.Please try again."<<endl;
                break;
        }
        if(choice!=4){
            cout<<"\nPress Enter to continue....";
            cin.ignore();
            cin.get();
        }
    }
   
    return 0;
}