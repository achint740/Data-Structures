#include <bits/stdc++.h>
using namespace std;

// Complete the unboundedKnapsack function below.
int unboundedKnapsack(int n, vector<int>a) {
    int m=a.size();
    long long int coins[n+1][m];
    for(int j=0;j<m;j++){
        coins[0][j]=1;
    }
    // i refers to current amt
    //j refers to index of coin being used
    int loc=0;
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
        if(coins[i][m-1]>0){
            loc=i;
        }
    }
    return loc;
}

int main(){
   int t,n,m,d;
   cin>>t;
   while(t--){
       cin>>m>>n;
       vector<int>arr;
       for(int i=0;i<m;i++){
           cin>>d;
           arr.push_back(d);
       }
       cout<<unboundedKnapsack(n,arr)<<endl;
   }  
return 0;
}
