#include <bits/stdc++.h>
using namespace std;

void findpos(vector<int>&last_len,int element){
    int n = last_len.size();
    if(n==0){
        last_len.push_back(element);
        return ;
    }
    if(element>=last_len[n-1]){
        last_len.push_back(element);
        return ;
    }
    if(element<last_len[0]){
        last_len[0]=element;
        return ;
    }
    int i = 0;
    int j = n - 1;
    while(i<=j){
        int mid = (i+j)/2;
        if(element>last_len[mid]){
            i = mid + 1;
        }
        else{
            if(mid>=1 && element>last_len[mid-1]){
                last_len[mid] = element;
                return ;
            }
            else{
                j = mid - 1;
            }
        }
    }
    return ;
    
}

// Complete the longestIncreasingSubsequence function below.
int longestIncreasingSubsequence(vector<int> arr){
    int n = arr.size();
    vector<int>last_len;
    for(int i=0;i<n;i++){
        findpos(last_len,arr[i]);
    }
    return last_len.size();
}

int main()
{
   int n,d;
   cin>>n;
   vector<int>v;
   for(int i=0;i<n;i++){
       cin>>d;
       v.push_back(d);
   }
   cout<<longestIncreasingSubsequence(v);
   return 0;
}
