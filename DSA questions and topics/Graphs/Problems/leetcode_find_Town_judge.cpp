#include<iostream>
#include<vector>
using namespace std;

    int findJudge(int n, vector<vector<int>>& trust) {
        // adjacency list
        // unordered_map<int, list<int>> adjList;
        vector<vector<int>> adjList(n+1);
        for(int i=0; i<trust.size(); i++){
            int u = trust[i][0];
            int v = trust[i][1];

            adjList[u].push_back(v);
        } 

        vector<int> indegree(n+1, 0);

        // for(pair<int, list<int>> pa : adjList){
        //     for(int neigh : pa.second){
        //         indegree[neigh]++;
        //     }
        // }
        for(int i=1; i<=n; i++){
            for(int j=0; j<adjList[i].size(); j++){
                indegree[adjList[i][j]]++;
            }
        }

        int townjudge = -1;
        for(int i=1; i<=n; i++){
            if(indegree[i] == n-1) townjudge = i;
        }
        
        // if(adjList.find(townjudge) != adjList.end()) townjudge = -1;
        if(townjudge == -1) return townjudge;
        if(adjList[townjudge].size() != 0) townjudge = -1;
        return townjudge;
    }


int main(){
    int n = 3;
    vector<vector<int>> trust{
        {1, 2},
        {2, 3}
    };
    
    int ans = findJudge(n, trust);

    cout<<ans<<endl;

    return 0;
}