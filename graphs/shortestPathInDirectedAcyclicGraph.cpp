#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
#include<list>
#include<limits>
using namespace std;

class graph{
    public:
        unordered_map<int,list<pair<int,int>> > adj;

        void addEdge(int u, int v, int weight){
            pair<int,int> p = make_pair(v,weight);
            adj[u].push_back(p);
        }

        void topoSort(unordered_map<int,list<pair<int,int>> > &adj, stack<int> &s, unordered_map<int,bool> &visited, int node){
            visited[node] = true;

            for(auto i: adj[node]){
                if(!visited[i.first]){
                    topoSort(adj, s, visited, i.first);
                }
            }
            s.push(node);
        }

        void shortestPath(int src, vector<int> &dist, stack<int> &s){
            dist[src] = 0;

            while(!s.empty()){
                int top = s.top();
                s.pop();

                if(dist[top] != INT_MAX){
                    for(auto i: adj[top]){
                        if(dist[top] + i.second < dist[i.first]){
                            dist[i.first] = dist[top] + i.second;
                        }     
                    }
                }
            }
        }
};

int main(){
    int n,m;
    cout<<"enter number of nodes: ";
    cin>>n;
    cout<<"number of edges: ";
    cin>>m;

    int src;
    cout<<"enter source: ";
    cin>>src;

    graph g;

    int u,v,w;
    for(int i=0; i<m; i++){
        cin>>u >>v >>w;
        g.addEdge(u,v,w);
    }

    stack<int> s;
    unordered_map<int,bool> visited;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.topoSort(g.adj,s, visited, i);
        }
    }

    vector<int>dist(n);
    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
    }

    g.shortestPath(src,dist, s);

    for(auto i: dist){
        cout<<i<<" ";
    }
    return 0;
}