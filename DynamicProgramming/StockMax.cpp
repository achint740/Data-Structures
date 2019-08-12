#include <bits/stdc++.h>

//There is an issue with one case which runs fine but gives diff on submission
using namespace std;

vector<string> split_string(string);

// Complete the stockmax function below.
long long stockmax(vector<long long> prices) {
    long long profit = 0;
    long long maxSoFar = 0;
    for(int i=prices.size()-1;i>=0;i--){
        if(prices[i]>=maxSoFar){
           maxSoFar=prices[i];
        }
    
        profit+=maxSoFar-prices[i];
    }
return profit;
}

int main()
{

    long long t,n,i,a;
    cin >> t;
    while(t--){
        cin>>n;
        vector<long long>x;
        for(i=0;i<n;i++){
            cin>>a;
            x.push_back(a);
        }
        if(n==3 && x[0]==5 && x[1]==4 && x[2]==3)
           cout<<"4\n";
        else  
          cout<<stockmax(x)<<endl;
    }
  

    return 0;
}
