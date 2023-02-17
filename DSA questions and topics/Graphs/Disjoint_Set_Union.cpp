#include<iostream>
#include<vector>
using namespace std;

/*
 Time Complexity of both Union by rank and size is O(4*alpha).
 and alpha is close to 1, hence it's almost constant time.
*/

class DisjointSet{
    private:
        vector<int> parent, rank, size;

    public:
        DisjointSet(int n){
            parent.resize(n+1);
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }

        int findUPar(int node){
            if(parent[node] == node) return node;

            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }

        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

int main(){
    DisjointSet dj(7);

    dj.unionByRank(1, 2); 
    dj.unionByRank(2, 3); 
    dj.unionByRank(4, 5); 
    dj.unionByRank(6, 7); 
    dj.unionByRank(5, 6);

    if(dj.findUPar(3) == dj.findUPar(7)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;
    
    dj.unionByRank(3, 7);

    if(dj.findUPar(3) == dj.findUPar(7)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;

    return 0;
}