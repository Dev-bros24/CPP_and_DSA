#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
Steps for Kahn's Algorithm:
1. Find out indegree of all the nodes.
2. Push all the nodes with 0 indegree into the queue.
3. take the frontNode and pop it out of the queue and push it into the
answer array.
4. For all the neighbours reduce the indegree by 1 and now check all 0
indegree nodes and push them into the queue.
5. Repeat above until queue becomes empty.
*/

// Adjacency list using 2D matrix
template <typename T>
class Graph{
    private:
    int vertices;
    vector<vector<T>> adjList;

    public:
    Graph(int vertices){
        this->vertices = vertices;
        adjList = vector<vector<T>>(vertices);
    }

    void addEdge(T u, T v, bool directional){
        adjList[u].push_back(v);

        if(!directional){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        cout<<"Below is the adjacency list of the graph:"<<endl;
        for(int i=0; i<vertices; i++){
            cout<<i<<" -> ";
            for(int j=0; j<adjList[i].size(); j++){
                cout<<adjList[i][j];
                if(j!=adjList[i].size()-1) cout<<", ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

vector<int> toposortKahn(vector<vector<int>> &edges, int v, int e){
    // preparation of Adjacency list
    vector<vector<int>> adjList(v);
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }

    // Find indegree of all nodes
    vector<int> indegree(v, 0);

    for(int i=0; i<adjList.size(); i++){
        for(int j=0; j<adjList[i].size(); j++){
            indegree[adjList[i][j]]++;
        }
    }

    queue<int> q;
    // push nodes with 0 indegree into the queue
    for(int i=0; i<v; i++){
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(int neighbour : adjList[frontNode]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) q.push(neighbour);
        }
    }
    return ans;
}

int main(){
    int n, m;
    cout<<"Enter the number of nodes in the Graph: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges in the Graph: "<<endl;
    cin>>m;

    Graph<int> g(n);

    vector<vector<int>> edges(m, vector<int>(2));

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        edges[i][0] = u;
        edges[i][1] = v;
        g.addEdge(u, v, 1);
    }

    g.printAdjList();

    vector<int> ans = toposortKahn(edges, n, m);

    cout<<"The Topological sort of the Graph is: "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}