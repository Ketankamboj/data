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

        void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low, unordered_map<int,bool> &vis, vector<vector<int> > &result){
            vis[node] = true;
            disc[node] = low[node] = timer++;

            for(auto nbr : adj[node]){
                if(nbr == parent)
                    continue;
                if(!vis[nbr]){
                    dfs(nbr, node, timer, disc, low, vis, result);
                    low[node] = min(low[node], low[nbr]);

                    //check edge is bridge(condition to check bridge)
                    if(low[nbr] > disc[node]){
                        vector<int> ans;
                        ans.push_back(node);
                        ans.push_back(nbr);
                        result.push_back(ans);
                    }
                }
                else{
                    //back edge
                    low[node] = min(low[node], disc[nbr]);
                }
            }
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
    vector<vector<int> >result;

    for(int i=0; i<n; i++){
        disc[i] = -1;
        low[i] = -1;
    }

    for(int i=0; i<n; i++){
        if(!vis[i]){
           g.dfs(i, parent, timer, disc, low,vis, result);
        }
    }
    return 0;
}