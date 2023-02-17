#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<climits>
#include<queue>
#include<set>
using namespace std;

/*
Steps in Prim's Algo;
1. Create adjacency list.
2. Prepare 3 DS so that all the vertices can be indexes in them. Let's say we have 3 
vectors of size n(number of vertices). The three vectors are key(distance tracker), 
mst(to determine which nodes are included in MST) and parent(to track of parent nodes).
3. Initialize the key DS with INT_MAX(infinity) value, MST with false and parent with -1.
4. Take one source node like 0 for example, then set key[src] = 0 and parent[src] = -1.
5. Now we'll repeat next steps(6 & 7) for the n-1(or n) number of times.
6. We'll find lowest key value in key DS with mst of that node as false, and the index 
of the array would be the node(u) and we would add it into MST by marking mst[u] = true.
7. Now for all adjacent nodes of this node we would update the key DS and the parent DS
if there are nodes to which the distance from this node is less than what is there in 
key DS and the MST of those nodes is also false.
8. Now we would give the answer according to what is asked.
*/

template <typename T>
class Graph{
    private:
        vector<vector<pair<T, int>>> adjList;
        int vertices;

    public:
        Graph(int vertices){
            this -> vertices = vertices;
            adjList = vector<vector<pair<T, int>>>(vertices);
        }

    void addEdge(T u, T v, int weight, bool directional){
        adjList[u].push_back(make_pair(v, weight));

        if(!directional) 
        adjList[v].push_back(make_pair(u, weight));
    }

    void printAdjList(){
        cout<<"Below is the adjacency list of the Graph: "<<endl;
        for(int i=0; i<vertices; i++){
            cout<<i<<" -> ";
            for(pair<int, int> ele : adjList[i]){
                cout<<"("<<ele.first<<", "<<ele.second<<"), ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};


/*
// Basic Implementation using key array only
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i=0; i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wei = g[i].second;

        adjList[u].push_back(make_pair(v, wei));
        adjList[v].push_back(make_pair(u, wei));
    }

    vector<int> key(n, INT_MAX); // distance tracker 
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);
    int src = 0;
    key[src] = 0;
    parent[src] = -1;

    for(int i=0; i<n; i++){ // this we can run for number of edges in MST times as well, which is n-1 so we can start the loop from i = 1 as well
        int u = 0;
        int mini = INT_MAX;
        for(int i=0; i<n; i++){ // to find this minimum, we can use priority queue(minheap) as well
            if(key[i]<mini && mst[i] == false){
                mini = key[i];
                u = i;
            }
        }

        mst[u] = true;

        for(pair<int, int> neighbour : adjList[u]){
            int v = neighbour.first;
            int w = neighbour.second;
            if(!mst[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;

    for(int i=1; i<n; i++){
        int u = parent[i];
        int v = i;
        int w = key[v];
        ans.push_back(make_pair(make_pair(u, v), w));
    }
    return ans;
}
*/

/*
*** IMPORTANT --> Implementation using Priority Queue, we can't implement using priority queue because of the reason mentioned below in code on line number 160.
class Compare{
    public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first) return a.second>b.second;
        else return a.first > b.first;
    }
};
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i=0; i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wei = g[i].second;

        adjList[u].push_back(make_pair(v, wei));
        adjList[v].push_back(make_pair(u, wei));
    }

    vector<int> key(n, INT_MAX); // distance tracker 
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);
    int src = 0;
    key[src] = 0;
    parent[src] = -1;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // dist, node
    for(int i=0; i<n; i++){
        pq.push(make_pair(key[i], i));
    }

    for(int i=0; i<n; i++){
        auto topval = pq.top();
        pq.pop();
        int u = topval.second;

        mst[u] = true;

        for(pair<int, int> neighbour : adjList[u]){
            int v = neighbour.first;
            int w = neighbour.second;
            if(!mst[v] && w < key[v]){
                key[v] = w;
// Here before adding the node value true in mst array we can get a smaller distance
of a particular node from some other node and in that case while updating the key array
we will insert another pair of (dist, node) value for that particular node only.
And to add this second value we need to remove the previous stored pair in the priority
queue which we can't do as we don't have iterator in priority_queue. Might work in some
cases where we don't insert more values of a particular node before marking it true
in MST.
                pq.push(make_pair(w, v));
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;

    for(int i=1; i<n; i++){
        int u = parent[i];
        int v = i;
        int w = key[v];
        ans.push_back(make_pair(make_pair(u, v), w));
    }
    return ans;
}
*/

// NOTE: We can use Set instead of Priority queue as below 

class Compare{
    public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
    }
};

// From c++ 17 onwards we have to make this return type const by adding a const keyword like below in the comparator class
// class Compare{
//     public:
//     bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
//         if(a.first == b.first) return a.second < b.second;
//         else return a.first < b.first;
//     }
// };

/*
If you run this comparator in parallel across threads, constness is nice for safety. 
It also prevents weird side-effects and allows the compiler to optimize things more, 
by default. If the stdlib allowed the operator to be non-const, it should also assume
that there is some state there being modified (non-const) and thus that access might
not be thread-safe or that it might not make copies willy-nilly (parallel access).

While the compiler probably can figure this it out on its own (but only if inlined),
the library enforces this to help you write more correct and idiomatic code.
*/

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for(int i=0; i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wei = g[i].second;

        adjList[u].push_back(make_pair(v, wei));
        adjList[v].push_back(make_pair(u, wei));
    }

    vector<int> key(n, INT_MAX); // distance tracker 
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);
    int src = 0;
    key[src] = 0;
    parent[src] = -1;
    
    set<pair<int, int>, Compare> st; // dist, node
    // for(int i=0; i<n; i++){
    //     st.insert(make_pair(key[i], i));
    // }
    // here we don't need to insert all the nodes in the set, instead we can just insert src
    st.insert(make_pair(key[src], src));

    for(int i=0; i<n; i++){
        auto topval = *st.begin();
        st.erase(st.begin());
        int u = topval.second;

        mst[u] = true;

        for(pair<int, int> neighbour : adjList[u]){
            int v = neighbour.first;
            int w = neighbour.second;
            if(!mst[v] && w < key[v]){
                
                set<pair<int, int>> :: iterator record = st.find(make_pair(key[v], v));
                if(record != st.end()) st.erase(record);
                
                key[v] = w;
                st.insert(make_pair(w, v));
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;

    for(int i=1; i<n; i++){
        int u = parent[i];
        int v = i;
        int w = key[v];
        ans.push_back(make_pair(make_pair(u, v), w));
    }
    return ans;
}

int main(){
    int m, n;

    cout<<"Enter the number of vertices in the Graph: "<<endl;
    cin>>n;

    cout<<"Enter the number of edges in the Graph: "<<endl;
    cin>>m;

    vector<pair<pair<int, int>, int>> edges(n);

    Graph<int> g(n);

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v, weight;
        cin>>u>>v>>weight;
        edges[i] = make_pair(make_pair(u, v), weight);
        g.addEdge(u, v, weight, false);  // creating a non directional Graph
    }

    g.printAdjList();

    vector<pair<pair<int, int>, int>> ans = calculatePrimsMST(n, m, edges);

    cout<<"Below are the Graph edges in the minimum spanning Tree: "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
    }
    return 0;
}