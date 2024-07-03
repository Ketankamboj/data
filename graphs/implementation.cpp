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
            //direction is 0 if it is undirected graph
            //direction is 1 if it is directed graph

            //creating edge from u to v
            adj[u].push_back(v);

            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void printGraph(){
            for(auto i:adj){
                cout<<i.first<<"-> ";
                for(auto j:i.second){
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }

        void bfs(unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited, vector<int> &ans, int node){
            queue<int> q;
            q.push(node);
            visited[node] = 1;

            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                //store front node
                ans.push_back(frontNode);

                //traverse all neighbour
                for(auto i: adj[frontNode]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = 1;
                    }
                }
            }
        }

        void dfs(unordered_map<int, list<int>> &adj, unordered_map<int,bool> &visited1, vector<int> &ans1, int node){
            ans1.push_back(node);
            visited1[node] = true;

            for(auto i: adj[node]){
                if(!visited1[i]){
                    dfs(adj,visited1, ans1, i);
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

        //creating an undirected graph
        g.addEdge(u,v,0);
    }

    //printing
    g.printGraph();
    cout<<endl;

    //for breadth first search
    cout<<"printing breadth first search"<<endl;
    unordered_map<int,bool> visited;
    vector<int> ans;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.bfs(g.adj,visited,ans,i);
        }
    }

    int j=0;
    while(j<ans.size()){
        cout<<ans[j]<<" ";
        j++;
    }
    cout<<endl;

    //for depth  first search
    cout<<"printing depth first search"<<endl;
    unordered_map<int, bool>visited1;
    vector<int> ans1;

    for(int i=0; i<n; i++){
        if(!visited1[i]){
            g.dfs(g.adj,visited1, ans1, i);
        }
    }

    int k=0;
    while(k<ans1.size()){
        cout<<ans1[k]<<" ";
        k++;
    }
    return 0;
}