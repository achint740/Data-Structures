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

    int f = 0;
    int r = 1;
    int res=1;
    int currentp = petrol[f] - dis[f];

    while(f!=r || currentp<0)
    {
        while(currentp<0 && f!=r)
        {
            currentp-=petrol[f]-dis[f];
            f = (f+1)%n;

          if(f==0){
              res=-1;
            break;
          }
        }
      if(res==-1 && f==0)
        break;

      currentp+=petrol[r]-dis[r];
      r = (r+1)%n;
    }
    if(f==0)
    cout<<f-1;   
    else
     cout<<f;
}

