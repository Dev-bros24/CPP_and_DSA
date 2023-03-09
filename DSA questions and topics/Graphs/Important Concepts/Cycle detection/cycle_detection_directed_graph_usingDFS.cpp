#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<vector>
using namespace std;

template <typename T>
class Graph{
    private:
    unordered_map<T, list<T>> adjList;
    int vertices;
    vector<vector<int>> adjMatrix;

    public:
        Graph(int vertices){
            this->vertices = vertices;
            adjMatrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));
        }

        void addEdge(int u, int v, bool directional){
            adjList[u].push_back(v);
            adjMatrix[u][v] = 1;

            if(!directional){
                adjList[v].push_back(u);
                adjMatrix[v][u] = 1;
            }
        }

        void printAdjMatrix(){
            cout<<"Below is the adjacency matrix of the graph: "<<endl;
            for(int i=0; i<vertices; i++){
                for(int j=0; j<vertices; j++){
                    cout<<adjMatrix[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }

        void printAdjList(){
            cout<<"Below is the adjacency list of the Graph: "<<endl;
            for(auto pa : adjList){
                cout<<pa.first<<" -> ";
                for(auto val : pa.second){
                    cout<<val<<", ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};

void prepareAdjList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }
}

// Parent is not required in this
bool detectCycleDFS(unordered_map<int, list<int>> &adjList, unordered_set<int> &visited, unordered_set<int> &visitedDFS, int node){
    visited.insert(node);
    visitedDFS.insert(node);

    for(auto neighbour : adjList[node]){
        if(visited.find(neighbour) == visited.end()){
            if(detectCycleDFS(adjList, visited, visitedDFS, neighbour)) return true;
        }
        else if(visitedDFS.find(neighbour) != visitedDFS.end()){
            return true;
        }
    }
    visitedDFS.erase(node);
    return false;
}

bool detectCycle(vector<vector<int>> &edges, int n){
    unordered_map<int, list<int>> adjList;
    unordered_set<int> visited;
    unordered_set<int> visitedDFS;

    // Prepare adjacency list
    prepareAdjList(edges, adjList);

    for(int i=0; i<n; i++){
        if(visited.find(i) == visited.end()){
            bool ans = detectCycleDFS(adjList, visited, visitedDFS, i);
            if(ans) return true;
        }
    }

    return false;
}

int main(){
    int n, m;
    cout<<"Enter the number of nodes in the Graph: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges in the Graph: "<<endl;
    cin>>m;

    Graph<int> g(n);

    vector<vector<int>> edges(m, vector<int>(2));

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
        g.addEdge(u, v, 1);
    }

    g.printAdjList();
    g.printAdjMatrix();

    bool ans = detectCycle(edges, n);

    if(ans) cout<<"This Directed Graph is Cyclic"<<endl;
    else cout<<"This Directed Graph is Acyclic"<<endl;
    
    return 0;
}