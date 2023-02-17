#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;

/*
    Bellman Ford Algorithm is an algorithm to find the shortest path from one source
    node to all the other nodes in a Graph. It is different from Djakstra's Algo 
    in the sense that here negative weights are also allowed, but not negative cycles. 
    But this algo can be used to find a negative cycle in a Graph. 

    A negative cycle is a cycle whose edges are such that the sum of their 
    weights is a negative value. Therefore, for every cycle we do we'll get even 
    smaller distances of nodes.

    This Algorithm is for directed Graphs only, but we can easily convert an
    undirected Graph to a directed Graph by making each edge bidirectional with
    same weights of the edge.

    Steps in Bellman Ford Algorithm:

    1. Relax all the Edges N-1 times sequentially.
    2. Relaxation:
        a. if(dist[u] + w < dist[v]){
            dist[v] = dist[u] + w;
        }
    3. For detecting a negative cycle, just relax all the Edges one more time and if any of the
    iteration satisfies the above condition of relaxation that means there is a Negative cycle
    present in the Graph.

*/

template <typename T>
class Graph{
    private:
        unordered_map<T, list<pair<T, int>>> adjList;

    public:
        void addEdge(T u, T v, int weight, bool directional){
            adjList[u].push_back(make_pair(v, weight));

            if(!directional) adjList[v].push_back(make_pair(u, weight));
        }

        void printAdjList(){
            cout<<"Below is the adjacency list of the Graph: "<<endl;
            for(pair<T, list<pair<T, int>>> pa : adjList){
                cout<<pa.first<<" -> ";
                    for(pair<T, int> ele : pa.second){
                        cout<<"("<<ele.first<<", "<<ele.second<<"), ";
                    }
                    cout<<endl;
            }
            cout<<endl;
        }
};

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges) { // If no path is possible this will return INT_MAX
    vector<int> distance(n+1, INT_MAX);
    distance[src] = 0;

    for(int i=1; i<n; i++){
        for(int j=0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(distance[u] != INT_MAX && distance[u] + w < distance[v]){
                distance[v] = distance[u] + w;
            }
        }
    }

    bool negativeCycle = false;

    for(int j=0; j<edges.size(); j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(distance[u] != INT_MAX && distance[u] + w < distance[v]){
                negativeCycle = true;
            }
        }

    if(negativeCycle) return -1;
    else return distance[dest];
}

int main(){
    int n, m;
    cout<<"Enter the number of vertices in the Graph: "<<endl;
    cin>>n;

    cout<<"Enter the number of Edges in the Graph: "<<endl;
    cin>>m;

    vector<vector<int>> edges(m, vector<int>(3));
    Graph<int> g;

    cout<<"Enter the Edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
        g.addEdge(u, v, w, 1);
    }

    g.printAdjList();

    int sourceNode, destNode;
    cout<<"Enter the source Node: ";
    cin>>sourceNode;

    cout<<"\nEnter the destination Node: ";
    cin>>destNode;

    int answer = bellmanFord(n, m, sourceNode, destNode, edges);
    cout<<"\nThe shortest distance from source Node to the destination Node is: "<<answer<<endl;

    return 0;
}