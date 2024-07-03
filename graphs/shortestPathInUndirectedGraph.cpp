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

        void shortestPath(unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, unordered_map<int,int> &parent, vector<int> &ans, int s, int d){
            //do bfs
            queue<int> q;
            q.push(s);
            visited[s] = 1;
            parent[s] = -1;

            while(!q.empty()){
                int front = q.front();
                q.pop();

                for(auto i: adj[front]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = 1;
                        parent[i] = front;
                    }
                }
            }

            //prepare shortest path
            int currNode = d;
            ans.push_back(d);

            while(currNode != s){
                currNode = parent[currNode];
                ans.push_back(currNode);
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

    int src,dest;
    cout<<"enter source: ";
    cin>>src;
    cout<<"enter destination: ";
    cin>>dest;

    unordered_map<int,int> parent;
    unordered_map<int,bool> visited;
    vector<int> ans;

    g.shortestPath(g.adj, visited, parent, ans, src, dest);

    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
    return 0;
}