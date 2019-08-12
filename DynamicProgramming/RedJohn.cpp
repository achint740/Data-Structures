#include <bits/stdc++.h>
using namespace std;

int redJohn(int n) {
    int* dp = new int[n+1];
    dp[0]=0;
    dp[1]=dp[2]=dp[3]=1;
    dp[4]=2;
    for(int i=5;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-4];
    }
    int m=dp[n];
    return m;
}

int main() {
    int x=300000;
    bool prime[x+1]; 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=x; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=x; i += p) 
                prime[i] = false; 
        } 
    }
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans=redJohn(n);
        //cout<<ans<<endl;
        int c=0;
        for(int i=2;i<=ans;i++){
            if(prime[i])
               c++;
        }
        cout<<c<<endl;
    }
    
}
