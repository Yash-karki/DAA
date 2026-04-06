#include<bits/stdc++.h>

using namespace std;

#define INF INT_MAX

void printPath(int parent[], int j) {
    if (j == -1)
        return;
    printPath(parent, parent[j]);
    cout << j << " ";
}

void dijkstra(int V, vector<pair<int,int>> adj[], int source){
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;

            if (currDist + weight < dist[adjNode]) {
                dist[adjNode] = currDist + weight;
                parent[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
     }

     cout << "\nShortest paths" << source<<endl;

     for (int i = 0; i < V; i++) {
        if (i == source) continue;

        cout << "\nFriend at node " << i << ":\n";

        if (dist[i] == INF) {
            cout << "No path exists\n";
            continue;
        }

        cout << "Distance = " << dist[i] << endl;
        cout << "Path = ";
        printPath(parent.data(), i);
        cout << endl;
    }

}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<pair<int,int>> adj[V];

    cout<<"enter u v weight"<<endl;

    for(int i = 0; i<E; i++){
        int u,v,w;
        cin>>u>>v>>w;

    
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
    }

    int source;
    cout<<"enter source";
    cin>>source;

    dijkstra(V, adj, source);
   

    return 0;
}