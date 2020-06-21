#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sum(ll *a,ll n){
   ll *contri = new ll[n];
   ll i,y=n-2,x=0;
   ll j = ceil(n/2.0);
   for(i=0;i<j;i++){
       if(i==0){
           contri[i] = pow(2,n) - 1;
       }
       else{
           contri[i]=(contri[i-1]%1000000007)+((ll)pow(2,y)%1000000007)
                                             -((ll)pow(2,x)%1000000007);
           y--;
           x++;
       }
   }
   for(i=n-1;i>=j;i--){
       contri[i]=contri[n-1-i];
   }
   ll sum=0;
   for(i=0;i<n;i++){
     //cout<<contri[i]<<" ";
     sum+=a[i]*contri[i];
     sum%=1000000007;
   }
   //cout<<endl;
 sum%=1000000007;
return sum;
}

int main(){
    ll n,i;
    cin>>n;
    ll *a = new ll[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<sum(a,n);
return 0;
}
