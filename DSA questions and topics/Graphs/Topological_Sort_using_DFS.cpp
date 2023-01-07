#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<stack>
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

void dfs_topo(int node, unordered_map<int, list<int>> &adjList, unordered_set<int> &visited, stack<int> &st){
    visited.insert(node);

    for(int neighbour : adjList[node]){
        if(visited.find(neighbour) == visited.end()){
            dfs_topo(neighbour, adjList, visited, st);
        }
    }
    st.push(node);
    return;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adjList;
    unordered_set<int> visited; // in place of this we can use vector for better TC

    // prepare Adjacency list
    prepareAdjList(edges, adjList);

    vector<int> ans;
    stack<int> st;

    for(int i=0; i<v; i++){
        if(visited.find(i) == visited.end()){
            dfs_topo(i, adjList, visited, st);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main(){
    int n, m;

    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;

    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    Graph<int> g(n);

    vector<vector<int>> edges(m, vector<int>(2));

    cout<<"Enter the edges:"<<endl;
    for(int i=0 ;i<m; i++){
        int u, v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
        g.addEdge(u, v, 1);
    }

    g.printAdjList();
    g.printAdjMatrix();

    vector<int> toposort = topologicalSort(edges, n, m);

    cout<<"Below is the valid topo sort of the array: "<<endl;
    for(int i=0; i<toposort.size(); i++){
        cout<<toposort[i]<<" ";
    }
    cout<<endl;

    return 0;
}