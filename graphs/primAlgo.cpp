//for finding minimum spanning tree
#include<iostream>
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

            pair<int,int> q = make_pair(u,weight);
            adj[v].push_back(q);
        }

        void findMst(vector<int> &key, vector<bool> &mst, vector<int> &parent, int n, vector<pair<pair<int, int>, int> > &result){
            key[1] = 0;
            parent[1] = -1;

            for(int i=1; i<n; i++){
                int mini = INT_MAX;
                int u;

                //finding min vale node
                for(int v=1; v<=n; v++){
                    if(mst[v] == false && key[v] < mini){
                        u = v;
                        mini = key[v];
                    }
                }

                //mark min node as true
                mst[u] = true;

                //check its adjacent nodes
                for(auto it : adj[u]){
                    int v = it.first;
                    int w = it.second;
                    if(mst[v] == false && w < key[v]){
                        parent[v] = u;
                        key[v] = w;
                    }
                }

                for(int i=2; i<=n; i++){
                    result.push_back(make_pair(make_pair(parent[i], i), key[i]));
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

    graph g;

    int u,v,w;
    for(int i=0; i<m; i++){
        cin>>u >>v >>w;
        g.addEdge(u,v,w);
    }

    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);

    for(int i=0; i<=n; i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    vector<pair<pair<int, int>, int> > result;

    g.findMst(key, mst, parent, n, result);

    return 0;
}