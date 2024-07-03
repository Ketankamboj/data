#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
#include<stack>
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

        //topological sort using dfs
        void topolgicalSortDfs(unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, stack<int> &s, int node){
            visited[node] = true;

            for(auto i: adj[node]){
                if(!visited[i]){
                    topolgicalSortDfs(adj, visited, s, i);
                }
            }

            //imp catch
            s.push(node);
        }

        //topological sort using bfs(kahn's algorithm)
        void topolgicalSortBfs(unordered_map<int,list<int>> &adj, vector<int> &indegree, vector<int> &ans, int n){
            //find all indegree
            for(auto i:adj){
                for(auto j: i.second){
                    indegree[j]++;
                }
            }

            //0 in degree vale queue me push krdo
            queue<int> q;
            for(int i=1; i<=n; i++){
                if(indegree[i] == 0)
                    q.push(i);
            }

            //do bfs
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();

                //ans
                ans.push_back(frontNode);

                //neighbour update
                for(auto i: adj[frontNode]){
                    indegree[i]--;

                    if(indegree[i] == 0)
                        q.push(i);
                }
            }
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

    //topological sort using dfs
    unordered_map<int,bool>visited;
    stack<int>s;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            g.topolgicalSortDfs(g.adj, visited, s, i);
        }
    }
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    //topological sort using bfs
    vector<int>ans;
    vector<int>indegree(n);

    g.topolgicalSortBfs(g.adj, indegree, ans, n);

    for(auto i: ans){
        cout<<i<<" ";
    }
    
    return 0;
}