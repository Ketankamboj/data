#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

class graph{
    public:
        unordered_map<int,list<int>> adj;

        void addEdge(int u, int v, bool direction){
            //direction is 0 if it is unordered graph
            //direction is 1 if it is ordered graph

            //creating edge from u to v
            adj[u].push_back(v);

            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        //cycle detection using bfs
        bool isCyclicBfs(unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited, int node){
            unordered_map<int,int>parent;
            parent[node] = -1;
            queue<int>q;
            q.push(node);
            visited[node] = 1;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                for(auto i:adj[frontNode]){
                    if(visited[i] == true && i != parent[frontNode]){
                        return true;
                    }
                    else if(!visited[i]){
                        q.push(i);
                        visited[i] = 1;
                        parent[i] = frontNode;
                    }
                }
            }
            return false;
        }

        //cycle detection using dfs
        bool isCyclicDfs(unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited, int parent, int node){
            visited[node] = true;

            for(auto i: adj[node]){
                if(!visited[i]){
                    bool cycleDetected = isCyclicDfs(adj,visited,node, i);
                    if(cycleDetected){
                        return true;
                    }
                }
                else if(i != parent){
                    return true;
                }
            }
            return false;
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

        //creating an undirected graph
        g.addEdge(u,v,0);
    }

    //breadth first search
    unordered_map<int,bool> visited;

    bool res;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            res = g.isCyclicBfs(g.adj,visited,i);
        }
    }

    if(res){
        cout<<"cyclic graph"<<endl;
    }
    else{
        cout<<"not cyclic graph"<<endl;
    }

    //depth first search
    unordered_map<int,bool> visited1;

    bool res1;
    for(int i=0; i<n; i++){
        if(!visited1[i]){
            res1 = g.isCyclicDfs(g.adj,visited1,-1,i);
        }
    }

    if(res1){
        cout<<"cyclic graph"<<endl;
    }
    else{
        cout<<"not cyclic graph"<<endl;
    }
    return 0;
}