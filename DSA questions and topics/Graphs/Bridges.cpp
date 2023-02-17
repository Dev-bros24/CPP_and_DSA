#include<iostream>
#include<utility>
#include<unordered_map>
#include<list>
#include<vector>
#include<map>
#include<climits>
#include"../abhi.h"
using namespace std;

/*
    A Bridge is an edge which if removed increases the number of connected components
    in a Graph.

    Steps to find out Bridges in a Graph: 
    1. Firstly we maintain three DS arrays visited, disc and low. Visited is to check 
    which all vertices are visited already, disc is to store the discovery time of 
    the vertices and low is to store the earliest visited vertex (the vertex with 
    minimum discovery time) that can be reached from the subtree rooted with that node.
    
    2. We maintain two variables parent and timer which have initial values as
    -1(as parent of source node is -1) and 0 respectively. 
    
    3. Now we call dfs for every node.

    4. Inside the dfs function, we first mark the node visited and set it's low and
    disc time as timer and then increment the timer.

    5. Now for every neighbour we follow these steps.
        a. If the neighbour is not visited yet, then we call dfs with this neighbour
        and parent as the node on which we are. After the call returns we mark the 
        low of this node as min(low[node], low[neighbour]), and then we check that
        if this edge b/w this node and the neighbour is a Bridge or not. For this the
        condition is if(low[neighbour] > disc[node]) then this edge is a Bridge.
        b. If the neighbour is already visited but it's not the parent of this node
        then this case is of BACK EDGE. In this case we change low[node] with
        min(low[node], low[neighbour]) or min(low[node], disc[neighbour]).
*/

template <typename T>
class Graph{
    private:
    unordered_map<T, list<T>> adjList;

    public:
    void addEdge(T u, T v, bool directional){
        adjList[u].push_back(v);

        if(!directional) adjList[v].push_back(u);
    }

    void printAdjList(){
        cout<<"Below is the adjacency list of the Graph: "<<endl;
        for(pair<int, list<int>> pa : adjList){
            cout<<pa.first<<" -> ";
            for(int val : pa.second){
                cout<<val<<", ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

};

void dfs(int node, int parent, vector<int> &low, vector<int> &disc, vector<int> &visited, 
    vector<vector<int>> &adjList, vector<vector<int>> &ans, int &timer){
        visited[node] = true;
        disc[node] = low[node] = timer++;

        for(int neighbour : adjList[node]){
            if(!visited[neighbour]){
                dfs(neighbour, node, low, disc, visited, adjList, ans, timer);
                low[node] = min(low[node], low[neighbour]);
                if(low[neighbour] > disc[node]) ans.push_back(vector<int>{node, neighbour});
            }
            else if(parent != neighbour){
                low[node] = min(low[node], disc[neighbour]); // we can interchange disc[neighbour] with low[neighbour]
            }
        }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
        vector<vector<int>> ans;
        vector<vector<int>> adjList(v);

        for(int i=0; i<e; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int parent = -1;
        vector<int> low(v, INT_MIN);
        vector<int> disc(v, INT_MIN);
        vector<int> visited(v, false);
        int timer = 0;

        for(int i=0; i<v; i++){
            if(!visited[i]){
                dfs(i, parent, low, disc, visited, adjList, ans, timer);
            }
        }

        return ans;
}

int main(){
    int n, m;

    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    vector<vector<int>> edges(m, vector<int>(2));
    Graph<int> g;

    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
        g.addEdge(u, v, 0);
    }

    g.printAdjList();

    vector<vector<int>> ans = findBridges(edges, n, m);

    cout<<"Below are the edges that are Bridge: "<<endl;
    printArray2D(ans);

    return 0;
}