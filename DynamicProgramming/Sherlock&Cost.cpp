#include<bits/stdc++.h>
using namespace std;

int BuildA(int* b,int n){
    
    int dp[n][2];
    dp[0][0]=dp[0][1]=0;
    for(int i=1;i<n;i++){
       // First Evaluate for dp[i][0]...Current element as 1
       int val1 = dp[i-1][0]+abs(1-1);
       int val2 = dp[i-1][1]+abs(1-b[i-1]);
       dp[i][0]=max(val1,val2);
       // Then Evaluate for dp[i][1]...Current element as b[i]
       int op1 = dp[i-1][0]+abs(b[i]-1);
       int op2 = dp[i-1][1]+abs(b[i]-b[i-1]);
       dp[i][1]=max(op1,op2);
    }
return max(dp[n-1][1],dp[n-1][0]);
} 

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int* b = new int[n];
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        //int* a = new int[n];
        cout<<BuildA(b,n)<<endl;
    }
}
