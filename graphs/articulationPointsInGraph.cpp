#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std;

class graph{
    public:
        unordered_map<int,list<int>> adj;

        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low, unordered_map<int,bool> &vis, vector<int> &ap){
            vis[node] = true;
            disc[node] = low[node] = timer++;
            int child = 0;

            for(auto nbr : adj[node]){
                if(nbr == parent)
                    continue;
                if(!vis[nbr]){
                    dfs(nbr, node, timer, disc, low, vis, ap);
                    low[node] = min(low[node], low[nbr]);

                    //condition for articulation point
                    if(low[nbr] >= disc[node] && parent != -1){
                        ap[node] = true;
                    }
                    child++;
                }
                else{
                    //back edge
                    low[node] = min(low[node], disc[nbr]);
                }
            }
            if(parent == -1 && child > 1)
                ap[node] = 1;
        }
};

int main(){
    int m,n;
    cout<<"enter number of edges: ";
    cin>>m;
    cout<<"enter number of nodes: ";
    cin>>n;

    graph g;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    int parent = -1;
    int timer = 0;
    unordered_map<int,bool> vis;
    vector<int> low(n);
    vector<int> disc(n);
    vector<int>ap(n,0);

    for(int i=0; i<n; i++){
        disc[i] = -1;
        low[i] = -1;
    }

    for(int i=0; i<n; i++){
        if(!vis[i]){
           g.dfs(i, parent, timer, disc, low,vis, ap);
        }
    }

    //printing articulation points
    for(int i=0; i<n; i++){
        if(ap[i] != 0){
           cout<< i<< " ";
        }
        cout<<endl;
    }
    return 0;
}