#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
#include<queue>
using namespace std;


int main() {
    queue<int>q;
    int n,type,num;
    cin>>n;
    while(n--)
    {
      cin>>type;
      if(type==1)
      {
          cin>>num;
            q.push(num);
      }
      else if(type==2)
      {
          q.pop();
      }
      else
      {
        cout<<q.front()<<endl;
      }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
