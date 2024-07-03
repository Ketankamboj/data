#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
        unordered_map<int,list<int>>adj;

        void addEdge(int u, int v){
            adj[u].push_back(v);
        }

        void printEdge(){
            for(auto i:adj){
                cout<<i.first<<"-> ";
                for(auto j: i.second){
                    cout<<j<<", ";
                }
            }
        }

        bool isCyclicDfs(unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited, int node){
            visited[node] = true;
            dfsVisited[node] = true;

            for(auto i: adj[node]){
                if(!visited[i]){
                    bool cyclic = isCyclicDfs(adj, visited, dfsVisited, i);
                    if(cyclic)
                        return true;
                }
                else if(dfsVisited[i])
                    return true;
            }
            dfsVisited[node] = false;
            return false;
        }
};


int main(){
    int n,m;
    cout<<"enter number of nodes";
    cin>>n;
    cout<<"enter number of edges";
    cin>>m;

    Graph g;

    int u,v;
    for(int i=0; i<m; i++){
        cin>>u >>v;
        g.addEdge(u,v);
    }

    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsVisited;

    bool res;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            res = g.isCyclicDfs(g.adj, visited, dfsVisited, i);
        }
    }
    
    if(res){
        cout<<"cycle present";
    }
    else{
        cout<<"cycle not present";
    }
    return 0;
}