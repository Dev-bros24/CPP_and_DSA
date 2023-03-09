#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
#include<unordered_set>
#include<stack>
using namespace std;

template <typename T>
class Graph{
    private:
        unordered_map<T, list<pair<T, int>>> adjList;

    public:
        void addEdge(T u, T v, int weight, bool directional){
            adjList[u].push_back(make_pair(v, weight));

            if(!directional){
                adjList[v].push_back(make_pair(u, weight));
            }
        }

        void printAdjList(){
            cout<<"Below is the adjacency list of the graph: "<<endl;
            for(pair<T, list<pair<T, int>>> ele : adjList){
                cout<<ele.first<<" -> ";
                for(pair<T, int> pa : ele.second){
                    cout<<"("<<pa.first<<", "<<pa.second<<"), ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};
// Class end

void dfs(unordered_map<int, list<pair<int, int>>> &adjList, unordered_set<int> &visited, int node, stack<int> &topo){
    visited.insert(node);
    // cout<<"dfs called for node: "<<node<<endl;

    for(pair<int, int> neighbour : adjList[node]){
        if(visited.find(neighbour.first) == visited.end()){
            dfs(adjList, visited, neighbour.first, topo);
        }
    }
    // cout<<"Pushing in stack: "<<node<<endl;
    topo.push(node);
}

vector<int> shortestPathDAG(vector<vector<int>> edges, int v, int e, int src){
    // prepare adjList
    unordered_map<int, list<pair<int, int>>> adjList;

    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wei = edges[i][2];

        adjList[u].push_back(make_pair(v, wei));
    }

    unordered_set<int> visited;

    // Find topoSort
    stack<int> topo;
    for(int i=0; i<v; i++){
        if(visited.find(i) == visited.end()){
            dfs(adjList, visited, i, topo);
        }
    }

    vector<int> distance(v, INT_MAX);
    distance[src] = 0;

    while(!topo.empty()){
        int topNode = topo.top();
        topo.pop();

        if(distance[topNode] != INT_MAX){
            for(pair<int, int> neighbour : adjList[topNode]){
                if(distance[neighbour.first] > distance[topNode] + neighbour.second){
                    distance[neighbour.first] = distance[topNode] + neighbour.second;
                }
            }
        }
    }
    return distance;
}

int main(){
    int n, m;
    cout<<"Enter the number of vertices in the Graph: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges in the Graph: "<<endl;
    cin>>m;

    Graph<int> g;
    vector<vector<int>> edges(m, vector<int>(3, 0));

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v, weight;
        cin>>u>>v>>weight;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = weight;
        g.addEdge(u, v, weight, 1);
    }

    g.printAdjList();

    // To find the shortest path to every node from a Given Node in a DAG, firstly we need
    // to find any valid Topological sort of the graph

    int src = 1;

    // cout<<"Printing the edges array: "<<endl;
    // for(int i=0; i<edges.size(); i++){
    //     for(int j=0; j<3; j++){
    //         cout<<edges[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    vector<int> ans = shortestPathDAG(edges, n, m, src);

    cout<<"Below is the shortest distance of all nodes from the src node: "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}