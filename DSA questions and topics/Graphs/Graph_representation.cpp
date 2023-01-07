#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    // using adjacency list
    unordered_map<T, list<T>> adj;   
    // map<T, list<T>> adj;   

    public:
        void addEdge(T u, T v, bool directional){
            /*
                0 --> undirected
                1 --> directed
            */
           adj[u].push_back(v);

           if(!directional){
            adj[v].push_back(u);
           }
        }

        void printAdjList(){  // TC -> O(n+m) , where n is no of nodes and m is no of edges
            cout<<"Below is the graph"<<endl;
            for(pair<T, list<T>> pa : adj){
                cout<<pa.first<<" -> ";
                for(T val : pa.second){
                    cout<<val<<", ";
                }
                cout<<endl;
            }
        }
};

int main(){
    int n, m;
    cout<<"Enter the number of nodes: "<<endl;
    cin>>n;
    cout<<"Enter the number of edges: "<<endl;
    cin>>m;

    Graph<int> g;

    cout<<"Enter the edges: "<<endl;
    for(int i=0; i<m; i++){
        int p, q;
        cin>>p>>q;
        // Creating an undirected graph
        g.addEdge(p, q, 0);
    }

    g.printAdjList();

    return 0;
}