#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

template <typename T>
class Graph{
    unordered_map<T, list<T>> adjList;
    vector<vector<int>> adjMatrix;
    int vertices;

    public:

    Graph(int vertices){
        this->vertices = vertices;
        adjMatrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));
    }

    void addEdge(T u, T v, bool directional){
        adjList[u].push_back(v);
        adjMatrix[u][v] = 1;

        if(!directional){
            adjList[v].push_back(u);
            adjMatrix[v][u] = 1;
        }
    }

    void printAdjMatrix(){
        cout<<"Below is adjacency matrix of the Graph: "<<endl;
        for(int i=0; i<adjMatrix.size(); i++){
            for(int j=0; j<adjMatrix[i].size(); j++){
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void printAdjList(){
        cout<<"Below is adjacency list of the Graph: "<<endl;
        for(auto pa : adjList){
            cout<<pa.first<<" -> ";
            for(auto val : pa.second){
                cout<<val<<" ,";
            }
            cout<<endl;
        }
    }

};

void prepareAdjList(vector<vector<int>>& edges, unordered_map<int, list<int>> &adjList){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

// Using BFS
bool isCyclic(unordered_map<int, list<int>> &adjList, unordered_set<int> &visited, int node){
    unordered_map<int, int> parent;

    queue<int> q;
    q.push(node);
    parent[node] = -1;
    visited.insert(node);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : adjList[frontNode]){
            if(visited.find(neighbour) != visited.end() && parent[frontNode] != neighbour){
                return true;
            }
            else if(visited.find(neighbour) == visited.end()){
                q.push(neighbour);
                visited.insert(neighbour);
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

// Using DFS
bool isCyclicDFS(unordered_map<int, list<int>> &adjList, unordered_set<int> &visited, int node, int parent){
    visited.insert(node);

    for(auto neighbour : adjList[node]){
        if(visited.find(neighbour) == visited.end()){
            if(isCyclicDFS(adjList, visited, neighbour, node)) return true;
        }
        else if(neighbour != parent) return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    unordered_map<int, list<int>> adjList;
    unordered_set<int> visited;
    string ans = "";

    // Prepare adjacency list
    prepareAdjList(edges, adjList);

// Using BFS
    // for(int i=0; i<n; i++){
    //     if(visited.find(i) == visited.end()){
    //         bool flag = isCyclic(adjList, visited, i);
    //         if(flag) return "Yes";
    //     }
    // }

    // return "No";

//Using DFS

    for(int i=0; i<n; i++){
        if(visited.find(i) == visited.end()){
            bool flag = isCyclicDFS(adjList, visited, i, -1);
            if(flag) return "Yes";
        }
    }

    return "No";
}

int main(){
    int n, m;

    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    vector<vector<int>> edges(m, vector<int>(2));

    Graph<int> g(n);

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();
    g.printAdjMatrix();

    string ans =  cycleDetection(edges, n, m);
    cout<<ans<<endl;

    return 0;
}