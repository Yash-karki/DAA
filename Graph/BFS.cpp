#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int V, vector<int> adj[]){
    vector<int> vis(V,0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> sol;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        sol.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return sol;
    
}

int main(){

    int n,m;
    cin >> n>>m;
    vector<int> adj[n];
    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> res = BFS(n,adj);
    for(int x : res){
        cout<<x<<" ";

    }
    cout<<endl;


    return 0;
}