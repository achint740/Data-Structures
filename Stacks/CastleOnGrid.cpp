#include<bits/stdc++.h>
#define mypair pair<int,int>
using namespace std;

class Graph{
public:
    map<mypair,list<mypair > >gmap;

    void addEdge(mypair p1,mypair p2){
        gmap[p1].push_back(p2);
        gmap[p2].push_back(p1);
    }

    void print(){
        for(auto node : gmap){
            mypair p = node.first;
            cout<<"("<<p.first<<","<<p.second<<") ->";
            for(auto c : node.second){
                cout<<"("<<c.first<<","<<c.second<<"),";
            }
            cout<<endl;
        }
    }

    void BFS(mypair src,mypair dest){
        queue<mypair>q;
        map<mypair,bool>visited;
        map<mypair,int>dist;

        for(auto node : gmap){
            visited[node.first]=false;
            dist[node.first]=INT_MAX;
        }

        q.push(src);
        visited[src]=true;
        dist[src]=0;

        while(!q.empty()){
            mypair p = q.front();
            q.pop();

            for(auto child : gmap[p]){
                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
                    dist[child]=dist[p]+1;
                }
            }
        }

        if(dist[dest]==INT_MAX)
            cout<<"-1";
        else
            cout<<dist[dest];
    }

};

int main(){
    Graph g;
    int n;
    string str;
    vector<string>grid;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        grid.push_back(str);
    }
    int m = grid[0].length();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mypair p = make_pair(i,j);
            if(grid[i][j]=='X')
                continue;

            int i1 = i+1;
            int j1 = j;
            while(i1<n && grid[i1][j1]=='.'){
                g.addEdge(p,make_pair(i1,j1));
                i1++;
            }
            
            i1=i;  j1=j+1;
            while(j1<m && grid[i1][j1]=='.'){
                g.addEdge(p,make_pair(i1,j1));
                j1++;
            }
        }
    }
    // g.print();
    int sx,sy;
    int dx,dy;
    cin>>sx>>sy>>dx>>dy;
    g.BFS(make_pair(sx,sy),make_pair(dx,dy));
    return 0;
}
