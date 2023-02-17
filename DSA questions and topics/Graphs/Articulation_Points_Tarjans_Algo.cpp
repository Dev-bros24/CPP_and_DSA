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
    An articulation point is a vertex removal of which increases the number of 
    connected components in a Graph.

    Steps to find out Articulation Points in a Graph: 
    1. Every step is similar to the Bridge find algorithm.
    2. There is a slight change in the condition of articulation point.
    There are two cases in it now:
        a. If the node is the source node(root of the DFS tree, parent -1), then we just
        check if this node has atleast two children.
        b. In the second case where this node is not the root of the DFS tree, then
        we check that it has a child v such that no vertex in the subtree rooted with 
        v has a back edge to one of the ancestors in DFS tree of u.
        For this the condition after the DFS call changes to 
        if(low[neighbour] >= disc[node] && parent != -1) then this node is an articulation
        point. 
*/

/*
GFG missed this type of test case in Articulation Point - I problem

8 10 
0 1 
1 2 
2 3 
3 4 
4 5 
1 5 
5 3 
2 6 
6 7 
7 2
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
    vector<vector<int>> &adjList, vector<bool> &ans, int &timer){
        visited[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;

        for(int neighbour : adjList[node]){
            if(!visited[neighbour]){
                child++;
                dfs(neighbour, node, low, disc, visited, adjList, ans, timer);
                low[node] = min(low[node], low[neighbour]);
                if(low[neighbour] >= disc[node] && parent != -1) ans[node] = true;
            }
            else if(neighbour != parent){
                low[node] = min(low[node], disc[neighbour]); // we can't interchange disc[neighbour] with low[neighbour]
            }
        }

        if(parent == -1 && child > 1) ans[node] = true;
}

vector<bool> findArticulationPoints(vector<vector<int>> &edges, int v, int e) {
        vector<bool> ans(v, false);
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

    vector<bool> ans = findArticulationPoints(edges, n, m);

    cout<<"Below are the vertices that are APs: "<<endl;
    for(int i=0; i<ans.size(); i++){
        if(ans[i]) 
        cout<<i<<" ";
    }

    return 0;
}