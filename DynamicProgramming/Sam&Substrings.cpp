#include <bits/stdc++.h>

using namespace std;

// Complete the substrings function below.
int substrings(string s) 
{
   long long n = s.length();
   long long a[n];
   long long b[n];
   a[0]=1;
   b[0]=1;
   for(long long i=1;i<n;i++){
       a[i] = (a[i-1]*10)%1000000007;
       b[i] = (a[i]+b[i-1])%1000000007;
   }
 long long sum=0;
   for(long long i=0;i<n;i++){
       sum+=((s[i]-'0')*b[n-1-i]*(i+1))%1000000007;
       sum%=1000000007;
   }
return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
