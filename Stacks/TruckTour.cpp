#include<iostream>
using namespace std;
int main()
{
    int n,i,j,p;
    cin>>n;
    int petrol[n],dis[n],x[n];
    for(i=0;i<n;i++)
    {
        cin>>petrol[i];
        cin>>dis[i];
    }

    int start = 0;
    int sum = 0;
    int deficit = 0;

    for(int i=0;i<n;i++){
        sum = sum + petrol[i] - dis[i];
        if(sum<0){
            start = i + 1;
            deficit+=sum;
            sum=0;
        }
    }

    if(sum+deficit<0){
        cout<<"-1";
    }
    else{
        cout<<start;
    }
    return 0;
}

