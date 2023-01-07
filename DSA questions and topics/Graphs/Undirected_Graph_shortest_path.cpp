#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;

/*
We'll just do BFS Traversal and find out the parent of each node and then just traverse
through that parent vector from terminal to start node and return the reverse of that.
*/

template <typename T>
class Graph{
    private:
    vector<vector<T>> adjList;
    int vertices;

    public:
    Graph(int vertices){
        this->vertices = vertices;
        adjList = vector<vector<T>>(vertices);
    }

    void addEdge(T u, T v, bool directional){
        adjList[u].push_back(v);

        if(!directional){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        cout<<"Below is the adjacency List of the Graph: "<<endl;
        for(int i=0; i<vertices; i++){
            cout<<i<<" -> ";
            for(int j=0; j<adjList[i].size(); j++){
                cout<<adjList[i][j];
                if(j<adjList[i].size()-1) cout<<", ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    vector<vector<int>> adjList(n);
	// Preparation of adjacency list
    for(int i=0; i<m; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    queue<int> q;
    unordered_set<int> visited;
    vector<int> parent(n, 0);

    q.push(s);
    visited.insert(s);
    parent[s] = -1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : adjList[frontNode]){
            if(visited.find(neighbour) == visited.end()){
                q.push(neighbour);
                parent[neighbour] = frontNode;
                visited.insert(neighbour);
            }
        }
    }

    // cout<<"Parent array: "<<endl;
    // for(int i=0; i<parent.size(); i++){
    //     cout<<parent[i]<<" ";
    // }

    vector<int> ans;
    int j = t;
    ans.push_back(j);

    while(j!=s){
        j = parent[j];
        ans.push_back(j);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n, m;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    vector<pair<int, int>> edges(m);
    Graph<int> g(n);

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        edges[i].first = u;
        edges[i].second = v;
        g.addEdge(u, v, 0); // undirected Graph creation
    }

    g.printAdjList();
    int start = 0, end = 3;

    vector<int> ans = shortestPath(edges, n, m, start, end);

    cout<<"\nBelow is the Shortest path: "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}