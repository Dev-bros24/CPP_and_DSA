#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

/*
    In some cases, in BFS the output is required in the sorted order of adjacent nodes then in that 
    case we would use a set instead of a list in adjacency list map.
*/

template <typename T>
class Graph{
    private:
    unordered_map<T, list<T>> adj;
    vector<vector<int>> arr;
    int vertices;

    public:
    Graph(int n){
        vertices = n;
        arr = vector<vector<int>>(vertices, vector<int>(vertices, 0));
    }

    void addEdge(T u, T v, bool directional){
        adj[u].push_back(v);
        arr[u][v] = 1;

        if(!directional){
            adj[v].push_back(u);
            arr[v][u] = 1;
        }
        
    }

    void printAdjList(){
        cout<<"Below is graph's adjacency list"<<endl;
        for(pair<T, list<T>> pa : adj){
            cout<<pa.first<<" -> ";
            for(T val : pa.second){
                cout<<val<<",";
            }
            cout<<endl;
        }
    }

    void printAdjMatrix(){
        cout<<"Below is graph's adjacency matrix"<<endl;
        for(int i=0; i<vertices; i++){
            for(int j=0; j<vertices; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

// BFS traversal

void printTraversal(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printTraversal(vector<vector<int>> &arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prepareAdjList(vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adjList)
{
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(int val : adjList[frontNode]){
            if(visited[val] == false || visited.find(val) == visited.end()){
            // if(!visited[val]){
                q.push(val);
                visited[val] = true;
            }
        }
    }
}

// void printAdjList(unordered_map<int, list<int>> &adjList){
//     cout<<"Below is the adjacency list formed"<<endl;
//     for(pair<int, list<int>> pa : adjList){
//         cout<<pa.first<<" -> ";
//         for(int val : pa.second){
//             cout<<val<<",";
//         }
//         cout<<endl;
//     }
// }

vector<int> BFS(int vertex, vector<pair<int, int>> edges)  // TC and SC --> O(N+E), N nodes and E edges
{
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited; // more suitable for visited is unordered_set

    // Create adjacency list
    prepareAdjList(edges, adjList);

    for(int i=0; i<vertex; i++){ // we have to traverse all vertices in case of disconnected graphs
        if(visited[i] == false || visited.find(i) == visited.end()){
        // if(!visited[i]){
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

// DFS Traversal

void dfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &temp, int node){
    visited[node] = true;
    temp.push_back(node);
    for(int val : adjList[node]){
        if(!visited[val] || visited.find(val) == visited.end()){
            dfs(adjList, visited, temp, val);
        }
    }   
    return;
}

vector<vector<int>> DFS(int V, int E, vector<pair<int, int>> &edges){ // TC & SC --> Linear
    vector<vector<int>> ans;
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    prepareAdjList(edges, adjList);

    for(int i=0; i<V; i++){
        if(!visited[i] || visited.find(i) == visited.end()){
            vector<int> component;
            dfs(adjList, visited, component, i);
            ans.push_back(component);
        }
    }

    return ans;
}


int main(){
    
    int n;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    Graph<int> g(n);

    vector<pair<int, int>> edges(m);

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        edges[i].first = u;
        edges[i].second = v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    g.printAdjMatrix();

    vector<int> bfsarr = BFS(n, edges);
    cout<<"Below is BFS traversal"<<endl;
    printTraversal(bfsarr);

    vector<vector<int>> dfsarr = DFS(n, m, edges); // 2D array to store different components in different 1D arrays
    cout<<"Below is DFS Traversal"<<endl;
    printTraversal(dfsarr);

    return 0;
}