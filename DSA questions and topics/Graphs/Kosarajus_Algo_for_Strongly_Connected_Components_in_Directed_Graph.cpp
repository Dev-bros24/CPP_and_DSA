#include<iostream>
#include<stack>
#include<vector>
#include"../abhi.h"
using namespace std;

/*
A Strongly Connected Component(SCC) in a Directed Graph is a Component/Portion of 
the Graph in which if we start from any node we can reach every other node in that 
Component.

    Steps to find SCCs(Strongly Connected Components) in a Graph using Kosaraju's 
    Algo:

    1. Firstly we find Topological ordering of the Graph. Since the Graph might 
    contain cycles we can't say it as a valid topo Sort, we are just using the 
    idea behind it.
    2. Then we take the transpose of the Graph, i.e. we reverse the direction of
    each edge in the Graph.
    3. We just do DFS traversal using the reverse Graph Adjacency list and store 
    the result in a temp vector, and finally we store the result in a 2D vector 
    in which each vector is a SCC.

*/

template <typename T>
class Graph{
    private:
        int vertices;
        vector<vector<int>> adjList;

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
            for(int i=0; i<vertices; i++){
                cout<<i<<" -> ";
                for(int j = 0; j<adjList[i].size(); j++){
                    cout<<adjList[i][j]<<", ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};


void dfs(int node, stack<int> &st, vector<vector<int>> &adjList, vector<bool> &visited){
    visited[node] = true;

    for(int nbr : adjList[node]){
        if(!visited[nbr]) dfs(nbr, st, adjList, visited);
    }

    st.push(node);
}

void revDfs(vector<vector<int>> &adjList, vector<bool> &visited, int node, vector<int> &temp){
    visited[node] = true;
    temp.push_back(node);

    for(int nbr : adjList[node]){
        if(!visited[nbr]) revDfs(adjList, visited, nbr, temp);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // preparing adjacency list
    vector<vector<int>> adjList(n);
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    stack<int> st;
    vector<bool> visited(n, false);

    for(int i=0; i<n; i++){
        if(!visited[i]) dfs(i, st, adjList, visited);
    }
    

    vector<vector<int>> revAdj(n); // transpose of the Graph

    for(int i=0; i<n; i++){
        for(int val : adjList[i]){
            revAdj[val].push_back(i);
        }
        visited[i] = false;
    }

    vector<vector<int>> ans;

    while(!st.empty()){
        int val = st.top();
        st.pop();
        vector<int> temp;
        if(!visited[val]) revDfs(revAdj, visited, val, temp);
        ans.push_back(temp);
    }
    
    return ans;
}


int main(){
    int n, m;

    cout<<"Enter the number of vertices in the Graph: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges in the Graph: "<<endl;
    cin>>m;

    Graph<int> g(n);

    vector<vector<int>> edges(m, vector<int>(2, 0));

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
        g.addEdge(u, v, true);
    }

    g.printAdjList();
    vector<vector<int>> answer = stronglyConnectedComponents(n, edges);
    cout<<"Below are the Strongly Connected Components: "<<endl;
    printRange2D(answer);

    return 0;
}