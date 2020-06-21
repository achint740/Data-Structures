#include <bits/stdc++.h>
using namespace std;

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3,int n1,int n2,int n3) {
   stack<long long int> s1,s2,s3;
   int i;
   int ht1 = 0;
   int ht2 = 0;
  int ht3 = 0;
   for(i=n1-1;i>=0;i--)
   {
       s1.push(h1[i]);
       ht1+=h1[i];
   }
   for(i=n2-1;i>=0;i--)
   {
       s2.push(h2[i]);
       ht2+=h2[i];
   }
   for(i=n3-1;i>=0;i--)
   {
       s3.push(h3[i]);
       ht3+=h3[i];
   }
 // cout<<ht1<<ht2<<ht3;
   while(!(ht1==ht2 && ht2==ht3))
   {
       if(ht1==0 || ht2==0 || ht3==0){
           return 0;
       }
       int x=5;
       if(ht1>=ht2 && ht1>=ht3 && !s1.empty())
         {
             ht1-=s1.top();
             s1.pop();
         }
        else if(ht2>=ht3 && ht2>=ht1 && !s2.empty())
        {
            ht2-=s2.top();
            s2.pop();
        }
        else if(!s3.empty())
        {
            ht3-=s3.top();
            s3.pop();
        }
   } 
  // cout<<ht1;
 return ht1;
}

int main()
{
   int n1,n2,n3;
   cin>>n1>>n2>>n3;
   int d,i;
   vector<int>h1;
   vector<int>h2;
   vector<int>h3;
   for(i=1;i<=n1;i++)
    {
        cin>>d;
        h1.push_back(d);
    }
    for(i=1;i<=n2;i++)
    {
        cin>>d;
        h2.push_back(d);
    }
    for(i=1;i<=n3;i++)
    {
        cin>>d;
        h3.push_back(d);
    }

  cout<<equalStacks(h1,h2,h3,n1,n2,n3);

}
