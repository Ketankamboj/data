//for shortest path
#include<iostream>
#include<set>
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

        void shortestPath(int src, vector<int> &dist, set<pair<int,int> > &s){
            dist[src] = 0;
            s.insert(make_pair(0,src));

            while(!s.empty()){
                //fetch top record
                auto top = *(s.begin());

                int nodeDistance = top.first;
                int topNode = top.second;

                //erase top record
                s.erase(s.begin());

                //traverse on neighbours
                for(auto i: adj[topNode]){
                    if(nodeDistance + i.second < dist[i.first]){
                        auto record = s.find(make_pair(dist[i.first], i.first));

                        //if record find in set
                        if(record != s.end()){
                            s.erase(record);
                        }

                        //distance update
                        dist[i.first] = nodeDistance + i.second;

                        //record push in set
                        s.insert(make_pair(dist[i.first], i.first));
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

    set<pair<int,int> > s;

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