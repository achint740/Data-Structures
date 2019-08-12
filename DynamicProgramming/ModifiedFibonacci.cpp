#include <bits/stdc++.h>
#include<iostream>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;

vector<string> split_string(string);

// Complete the fibonacciModified function below.
mp::cpp_int fibonacciModified(int t1, int t2, int n) 
{
 mp::cpp_int dp[100000];
 dp[0]=t1;
 dp[1]=t2;

 for(int i=2;i<n;i++)
  {
      dp[i] = dp[i-2] + dp[i-1]*dp[i-1];
  }

 mp::cpp_int u = dp[n-1]; 
return u;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t1T2n_temp;
    getline(cin, t1T2n_temp);

    vector<string> t1T2n = split_string(t1T2n_temp);

    int t1 = stoi(t1T2n[0]);

    int t2 = stoi(t1T2n[1]);

    int n = stoi(t1T2n[2]);

    mp::cpp_int result = fibonacciModified(t1, t2, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
