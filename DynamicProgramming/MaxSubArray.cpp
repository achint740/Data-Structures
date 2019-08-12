#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n,t,i;
    cin>>t;
    while(t--){
        cin>>n;
        int *a = new int[n];
        int s=0;
        int maxval=INT_MIN;
        bool res=true;
        for(i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>=0){
                res=false;
                s+=a[i];
            }
            if(a[i]>maxval){
                maxval=a[i];
            }
        }
        int max_here=0;
        int maxans = 0;
        for(i=0;i<n;i++){
          max_here+=a[i];
          if(max_here<0){
              max_here=0;
          }
          if(max_here>maxans){
              maxans=max_here;
          }
        }
        if(res==true){
            maxans=s=maxval;
        }
    cout<<maxans<<" "<<s<<endl;
    }
return 0;
}
