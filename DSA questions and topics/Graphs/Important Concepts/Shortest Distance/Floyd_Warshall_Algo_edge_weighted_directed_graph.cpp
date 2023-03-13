#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include"../../../abhi.h"

using namespace std;

/*
    If we want to find the shortest path from multiple source nodes to every other 
    node then we use Floyd Warshall Algorithm.
    It is a Multi source shortest path algorithm.
    It can detect negative cycles.
    It is implemented for Directed Graphs.

    It just states go via. every node/vertex and compute.

    We just run three for loops, outer one for via and the inner two for just 
    traversing through the matrix.
    We just assign the minimum values to the matrix block from the via distance
    and the distance which was already there.

    For detecting negative cycle, we just iterate once more and find out that if there
    is any node having distance to itself as negative then we say there has to be
    a negative cycle in the given Graph.
    for(int i=0; i<n; i++) if(matrix[i][i] < 0) // contains Negative cycle
*/

template<typename T>
class Graph{
    private:
        vector<vector<pair<T, int>>> adjList;
        int vertices;

    public:
        Graph(int vertices){
            this -> vertices = vertices;
            adjList = vector<vector<pair<T, int>>>(vertices);
        }

        void addEdge(T u, T v, int w, bool directional){
            adjList[u].push_back(make_pair(v, w));

            if(!directional) adjList[v].push_back(make_pair(u, w));
        }

        void printadjList(){
            cout<<"Below is the Adjacency list of the Graph: "<<endl;
            for(int i=0; i<vertices; i++){
                cout<<i<<" -> ";
                for(int j=0; j<adjList[i].size(); j++){
                    cout<<"("<<adjList[i][j].first<<", "<<adjList[i][j].second<<"), ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};

vector<vector<int>> floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> adjMatrix(n, vector<int>(n, 1e9));

    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjMatrix[u][v] = w;
    }

    for(int i=0; i<n; i++){
        adjMatrix[i][i] = 0;
    }

    for(int via = 0; via < n; via++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
            }
        }
    }

    return adjMatrix;
}

// 1 based indexing
// vector<vector<int>> floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
//     vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, 1000000000));

//     for(int i=0; i<m; i++){
//         int u = edges[i][0];
//         int v = edges[i][1];
//         int w = edges[i][2];

//         adjMatrix[u][v] = w;
//     }

//     for(int i=1; i<=n; i++){
//         adjMatrix[i][i] = 0;
//     }

//     for(int via = 1; via <= n; via++){
//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=n; j++){
//                 if(adjMatrix[i][via] == 1e9 || adjMatrix[via][j] == 1e9) continue;
//                 adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][via] + adjMatrix[via][j]);
//             }
//         }
//     }

//     return adjMatrix;
// }

int main(){
    int m, n;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;

    cout<<"Enter the number of Edges: "<<endl;
    cin>>m;

    vector<vector<int>> edges(m, vector<int>(3));
    Graph<int> g(n);

    cout<<"Enter the Edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
        g.addEdge(u, v, w, 1);
    }

    int src = 1, dest = 7;

    g.printadjList();

    vector<vector<int>> ans = floydWarshall(n, m, src, dest, edges);
    cout<<"Answer: "<<endl;
    printArray2D(ans);

    return 0;
}