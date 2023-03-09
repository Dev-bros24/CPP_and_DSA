#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* 
Steps in Kruskal's Algo:
    1. Firstly we sort the linear DS(edges) in increasing order of the weights.
    2. Now, we take two array, parent and rank and initially we initialize 
    parent DS with the same value as the nodes and the rank DS with 0.
    3. Now we have to write union by rank and path compression logic which
    comprises of two steps:
     a. findParent()
     i. Firstly we need to write findParent algo in which we recursively move
     up to the parent node until we reach a node which is parent of itself and
     we return that node.
     ii. At each recursion call we store the output in parent array's value at
     that particular node's index. This is path compression logic. 

     b. unionSet()
     i. In this we find the parent of the two nodes of which we are trying to take
     a Union. Then we find the rank of the two parent nodes.
     ii. If the ranks are equal we can make any node other's parent and we make sure
     we increment the rank of the node which we are making the parent.
     iii. If the ranks are unequal, then we make that node parent which is having
     more rank.

    4. Now for Kruskal's algo to find the MST we just iterate through the edges
    which are sorted in ascending order of their weights. In every iteration we check
    that the parent of the two nodes are equal or not(basically we are checking
    that they belong to the same component or not). If they are not equal then we
    take the union of those two parent nodes and then we add the weight of the edge
    to the minWeight variable in which we store the minWeight of the Spanning Tree.

    It is a greedy algorithm in graph theory as in each step it adds the next lowest-weight edge that will not form a cycle to the minimum spanning forest.
*/

template <typename T>
class Graph{
    private:
        vector<vector<pair<T, int>>> adjList;
        int vertices;

    public:
        Graph(int vertices){
            this->vertices = vertices;
            adjList = vector<vector<pair<int, int>>>(vertices);
        }

        void addEdge(T u, T v, int weight, bool directional){
            adjList[u].push_back(make_pair(v, weight));

            if(!directional) adjList[v].push_back(make_pair(u, weight));
        }

        void printAdjList(){
            cout<<"Below is the adjacency list of the Graph: "<<endl;
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

bool cmp(const vector<int> &vec1, const vector<int> &vec2){
    return vec1[2] < vec2[2];
}

void makeSet(vector<int> &rank, vector<int> &parent, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node, vector<int> &parent){
    if(parent[node] == node) return node;

    return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    // here in this function we operate on parents of the nodes but since 
  // here we've already passed the parents we don't need to find parents again.
  // otherwise we would have done this u = findParent(u, parent) and same for v.

    if(rank[u] == rank[v]){
        parent[u] = v;
        rank[v]++;
    }
    else if(rank[u] < rank[v]) parent[u] = v;
    else parent[v] = u;
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// in this ALgorithm we need a linear DS(not an adjacency list) in which we store the edges and sort them according to the edge weight.

    sort(graph.begin(), graph.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);

    makeSet(rank, parent, n);
    int minWeight = 0;

    for(int i=0; i<m; i++){
        int u = findParent(graph[i][0], parent);
        int v = findParent(graph[i][1], parent);

        if(u != v){
            minWeight += graph[i][2];
            unionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}

int main(){
    int n, m;
    cout<<"Enter the number of Vertices in the Graph: "<<endl;
    cin>>n;

    cout<<"Enter the number of Edges in the Graph: "<<endl;
    cin>>m;

    Graph<int> g(n);

    vector<vector<int>> edges(m, vector<int>(3));

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
        g.addEdge(u, v, w, 0);
    }

    g.printAdjList();

    int ans = kruskalMST(n, m, edges);

    cout<<"Answer: "<<ans<<endl;

    return 0;
}