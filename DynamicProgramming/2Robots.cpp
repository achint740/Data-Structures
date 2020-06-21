#include<bits/stdc++.h>
using namespace std;

int MinDist(int rb1_pos,int rb2_pos,int a[][2],int i,int n,map<pair<int,pair<int,int> >,int>dp){
    if(i==n){
      return 0;
    }
    pair<int,int>p = make_pair(rb1_pos,rb2_pos);
    if(dp.find(make_pair(i,p))!=dp.end())
        return dp[make_pair(i,p)];
int opt1 = ((rb1_pos==-1) ? abs(a[i][1]-a[i][0]) : abs(rb1_pos-a[i][0])+abs(a[i][0]-a[i][1])) + MinDist(a[i][1],rb2_pos,a,i+1,n,dp);
int opt2 = ((rb2_pos==-1) ? abs(a[i][1]-a[i][0]) : abs(rb2_pos-a[i][0])+(abs(a[i][0]-a[i][1]))) + MinDist(rb1_pos,a[i][1],a,i+1,n,dp);

return dp[make_pair(i,p)]=min(opt1,opt2);
}

int main(){
    int t,m,n,i;
    cin>>t;
    while(t--){
       cin>>m>>n;
       int a[n][2];
       for(i=0;i<n;i++){
           cin>>a[i][0]>>a[i][1];
       }
       map<pair<int,pair<int,int> >,int>dp;
       cout<<MinDist(-1,-1,a,0,n,dp)<<endl;
    }
return 0;
}
