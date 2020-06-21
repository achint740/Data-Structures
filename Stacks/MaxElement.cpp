#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    stack<int>s;
    stack<int>tempstack;
    int q,type,e;
    cin>>q;
    while(q--){
        cin>>type;
        if(type==1){
            cin>>e;
            s.push(e);
            if(tempstack.empty() || e>=tempstack.top())   tempstack.push(e);
        }
        else if(type==2){
            int pop_e = s.top();
            if(pop_e==tempstack.top()){
                tempstack.pop();
            }
            s.pop();
        }
        else{
            cout<<tempstack.top()<<endl;
        }
    }  
    return 0;
}
