#include<iostream>
#include<set>
#include<vector>
#include<queue>
using namespace std;

/*
    Simple Definition of a Bipartite Graph can be, it is a 
    Graph in which we can color the nodes with exactly two colors such that 
    no two adjacent nodes have the same color.

    If the Graph contains a cycle with odd number of nodes in it, it is NOT
    a Bipartite Graph.
    We just need to do Normal BFS/DFS with an extra color array.

    BFS & DFS --> TC = O(N+E)
                  SC = O(N+E) + O(N) + O(N)

NOTE : If we are given the edges of a Graph and we have to find that a Bipartition
    is possible or not, then we have to make an undirected Graph.
    Example in which directed Graph will not work is below:
    n = 4;  // starting from 1
    graph = [[1, 4], [2, 3], [3, 4]]    
*/

template<typename T>
class Graph{
    private:
        vector<vector<int>> adjList;
        int vertices;

    public:
        Graph(int vertices){
            this -> vertices = vertices;
            adjList = vector<vector<int>>(vertices);
        }

        void addEdge(int u, int v, bool directional){
            adjList[u].push_back(v);
            if(!directional) adjList[v].push_back(u);
        }

        void printAdjList(){
            cout<<"Below is the Adjacency list of the Graph: "<<endl;
            for(int i = 0; i<vertices; i++){
                cout<<i<<" -> ";
                for(int j=0; j<adjList[i].size(); j++){
                    cout<<adjList[i][j]<<", ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};

vector<vector<int>> createAdjList(vector<vector<int>> &edges, bool directional, int n){
    vector<vector<int>> graph(n);

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u].push_back(v);
        if(!directional) graph[v].push_back(u);
    }

    return graph;
}

bool isBpBFS(int node, vector<vector<int>> &adjList, vector<int> &color){
    queue<int> q;
    q.push(node);
    color[node] = 1;

    while(!q.empty()){
        int topNode = q.front();
        q.pop();

        for(int nbr : adjList[topNode]){
            if(color[nbr] == -1){
                color[nbr] = 1 - color[topNode];
                q.push(nbr);
            }
            else if(color[nbr] == color[topNode]) return false;
        }
    }

    return true;
}

bool isBpDFS(int node, vector<vector<int>> &adjList, vector<int> &color){
    if(color[node] == -1) color[node] = 1;

    for(int nbr : adjList[node]){
        if(color[nbr] == -1){
            color[nbr] = 1 - color[node];
            if(!isBpDFS(nbr, adjList, color)) return false;
        }
        else if(color[nbr] == color[node]) return false;
    }

    return true;
}

bool isBipartite(vector<vector<int>>& graph) {  // graph is the Adjacency list
    int n = graph.size();
    vector<int> color(n, -1);

    // for(int i=0; i<n; i++){
    //     if(color[i] == -1){
    //         if(!isBpBFS(i, graph, color)) return false;
    //     }
    // }  

    for(int i=0; i<n; i++){
        if(color[i] == -1){
            if(!isBpDFS(i, graph, color)) return false; 
        }
    } 

    return true; 
}

int main(){
    int n, m;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;

    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    Graph<int> g(n);

    vector<vector<int>> edges(m, vector<int>(2));

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();
    vector<vector<int>> graph(n);
    graph = createAdjList(edges, false, n);

    if(isBipartite(graph)) cout<<"Graph is Bipartite"<<endl;
    else cout<<"Graph is Not Bipartite"<<endl;

}