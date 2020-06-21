#include <iostream>
#include<vector>
#include<stack>
using namespace std;
int main() 
{
    long long int n,d,i;
    cin>>n;
  vector<long long int>v;

  for(i=0;i<n;i++)
  {
      cin>>d;
      v.push_back(d);
  }
  stack<int>s;
 long long int a = 0;
 long long int max = 0;
  int x;
  i=0;
  while(i<n)
  {
      if(s.empty() || v[i]>=v[s.top()])
       {
           s.push(i++);
       }
       else
       {
            x = s.top();
           s.pop();
           if(s.empty())
             a = v[x]*i;
           else
            a = v[x] * (i-s.top()-1);
         if(a>max)
           max = a;
       }
  }
  while(!s.empty())
  {
        x = s.top();
           s.pop();
           if(s.empty())
             a = v[x]*i;
           else
            a = v[x] * (i-s.top()-1);
         if(a>max)
           max = a;
  }
  cout<<max;
}
