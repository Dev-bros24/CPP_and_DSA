#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<unordered_set>
#include<set>
#include<climits>
#include"../../../abhi.h"
using namespace std;

/*
    Steps in Djakstra's Algo :
    1. Take two DS, one vector with INT_MAX values to store minimum distances of all nodes from
    source and other set or priority queue to fetch the minimum distance
    node everytime.
    2. Now initially mark distance of source node as 0 in distance vector
    and insert (0, src) entry in set/priority queue.
    3. Now iterate while set is non empty.
    4. Everytime take the topNode, remove it and check the distance of its neighbours
    from this node and check if the distance that is there in the vector 
    is more than the distance that we are getting from this node. If that is 
    true, then remove if there is any previous entry of this node in the
    distance vector with the distance mentioned in the distance vector(coz anyways 
    we're going to create a new entry for exploration with this smaller
    distance).
    5. Now update the distance to this new distance in the distance vector.
    6. Create an entry in the set DS with this new distance and this node.
    7. After the iteration stops return the distance vector.
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
            cout<<"Below is the Adjacency list of the Graph: "<<endl;
            for(pair<T, list<pair<T, int>>> pa : adjList){
                cout<<pa.first<<" -> ";
                for(pair<T, int> neigh : pa.second){
                    cout<<"("<<neigh.first<<", "<<neigh.second<<"), ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};

class Compare{ // This is default behaviour of comparators in case of pairs
    public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first){ // we need to include this equal condition otherwise the set will not include any entries of pairs that contain the first values as equal
            return a.second < b.second;
        }
        else{
            return a.first < b.first;
        }
    }
};

// TC -> O(ElogV), SC -> O(N+E)
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Creating adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;

    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wei = vec[i][2];

        adjList[u].push_back(make_pair(v, wei));
        adjList[v].push_back(make_pair(u, wei));
    }

    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>, Compare> st;
    // set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty()){
        pair<int, int> topNode = *(st.begin());

        int topDistance = topNode.first;
        int topVal = topNode.second;

        st.erase(st.begin());

        if(topDistance > dist[topVal]) continue;

        for(pair<int, int> neighbours : adjList[topVal]){
            if(topDistance + neighbours.second < dist[neighbours.first]){
                // set<pair<int, int>> :: iterator record = st.find(make_pair(dist[neighbours.first], neighbours.first));
                //     if(record != st.end()){
                //         st.erase(record);
                //     }
                    
                dist[neighbours.first] = topDistance + neighbours.second;
                st.insert(make_pair(dist[neighbours.first], neighbours.first));
            }
        }
    }
    return dist;
}

int main(){
    int n, m;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    vector<vector<int>> edges(m, vector<int>(3));
    Graph<int> g;

    cout<<"Enter the edges and weights: "<<endl;
    for(int i=0; i<m; i++){
        int u, v, weight;
        cin>>u>>v>>weight;
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = weight;
        g.addEdge(u, v, weight, 0); // Creation of non directional weighted Graph
    }

    g.printAdjList();

    int src = 0;

    vector<int> ans = dijkstra(edges, n, m, src);

    cout<<"Below is the shortest distance from the src to all vertices: "<<endl;
    printArray(ans);

    return 0;
}