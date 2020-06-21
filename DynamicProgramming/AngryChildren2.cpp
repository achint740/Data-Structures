#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

ll cum_diff(vector<ll>packets,ll x){
    ll ans = 0;
    for(ll i=0;i<x;i++){
        // cout<<"Packet  "<<i<<" "<<packets[i]<<endl;
        ans = ans + i*packets[i];
        ans = ans - (x-1-i)*packets[i];
        // cout<<ans<<endl;
    }
    // cout<<"Check "<<ans<<endl;
    return ans;
}

// Complete the angryChildren function below.
ll angryChildren(ll k, vector<ll> packets) {
     sort(packets.begin(),packets.end());
     ll n = packets.size();
     ll* cum = new ll[n];
     cum[0]=packets[0];
     for(ll i=1;i<n;i++){
         cum[i] = cum[i-1] + packets[i];
     }

     ll ans = cum_diff(packets,k);
     ll curr = ans;

     for(ll i=k;i<n;i++){
         ll y = cum[i-1]-cum[i-k];
         curr = curr - 2*y + (k-1)*(packets[i]+packets[i-k]);
         if(curr<ans)
            ans=curr;
     }
     return ans;

}

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>v;
    ll d;
    for(ll i=0;i<n;i++){
        cin>>d;
        v.push_back(d);
    }
    cout<<angryChildren(k,v);
    return 0;
}
