#include<iostream>
#include<math.h>

using namespace std;

int main(){

    int n;
    cout<<"Enter the total no of symbols\n"; //no of symbols
    cin>>n;
    double a[n],sum,b[n];
    int m;

    cout<<"Enter the extension\n"; //No of extension
    cin>>m;

    sum=0;

    cout<<"enter the values\n"; //Enter the symbols
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++){ //Self information

        b[i]=log2(1/a[i]);
        cout<<"The self information of element "<<i+1<<" is\n";
        cout<<b[i]<<endl;
    }


    for (int i=0;i<n;i++)   //Entropy without extension
    {
        sum=sum+a[i]*log2(1/a[i]);
    }

    cout<<"Entropy is "<<sum<<endl;; //entropy

  
    if (m==3){// third order extension
    double c[n][n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {   for(int k=0;k<n;k++){
            c[i][j][k]=a[i]*a[j]*a[k];
        }
        }
    }
    cout<<"The elements after third extension are ";
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            for (int k=0;k<n;k++){
            cout<<c[i][j][k]<<" ";
    }
    }
    cout<<endl;
    sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {   for(int k=0;k<n;k++){
            sum=sum+c[i][j][k]*log2(1/c[i][j][k]);
        }
        }
    }
    cout<<"Entropy after third extension is "<<sum;
    }
    if (m==2){          // second order extension

        double c[n][n];
        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                c[i][j]=a[i]*a[j];
            }
        }
        cout<<"The elements after second extension are ";
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++){
                cout<<c[i][j]<<" ";
            }
        }
        
        cout<<endl;
        sum=0;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++)
                {
                    sum=sum+c[i][j]*log2(1/c[i][j]);
                }
        }
        cout<<"Entropy after 2nd extension is "<<sum;

    }

}