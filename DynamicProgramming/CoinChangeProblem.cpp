#include<bits/stdc++.h>
using namespace std;
//long long int count = 0;

long long int bottomUP(int *a,int n,int m){
    long long int coins[n+1][m];
    for(int j=0;j<m;j++){
        coins[0][j]=1;
    }
    // i refers to current amt
    //j refers to index of coin being used
    for(int i=1;i<n+1;i++){
        for(int j=0;j<m;j++){
            long long int include_ways=0,exclude_ways=0;
            if(i-a[j]>=0){
                include_ways=coins[i-a[j]][j];
            }
            if(j>0){
                exclude_ways=coins[i][j-1];
            }
            coins[i][j]=include_ways+exclude_ways;
        }
    }
    return coins[n][m-1];
}

int main()
{
  int n,m,i;
  cin>>n>>m;
  int a[m];
  for(i=0;i<m;i++)
   {
       cin>>a[i];
   }
 cout<<bottomUP(a,n,m);
 // cout<<::count;
}
