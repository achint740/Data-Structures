#include<iostream>
#include<stack>
#include <bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;

vector<int> v;


void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    for (int p=2; p<=n; p++) {
       if (prime[p])
       {
           v.push_back(p);
       }
    }
 return;
}

bool divprime(int e,int i)
{
    int ithprime = v[i-1];;

    return ((e%ithprime)==0);
}

int main()
{
    stack<int>orgn;
    int n,q,d,i;
    cin>>n>>q;

    SieveOfEratosthenes(1000000);

    while(n--)
    {
        cin>>d;
        orgn.push(d);
    }

    queue<int>orgnl;

    while(!orgn.empty())
    {
       int x = orgn.top();
       orgnl.push(x);
       orgn.pop();
    }

  for(i=1;i<=q;i++)
    {
        stack<int>a;
        stack<int>b;

        while(!orgnl.empty())
        {
            int e = orgnl.front();
             if(divprime(e,i))
                b.push(e);
             else
                a.push(e);
          orgnl.pop();
        }

      while(!b.empty())
      {
          cout<<b.top()<<endl;
          b.pop();
      }

     while(!a.empty())
     {
         int y = a.top();
         orgnl.push(y);
         a.pop();
     }

    }

    while(!orgnl.empty())
    {
        cout<<orgnl.front()<<endl;
        orgnl.pop();
    }
}
