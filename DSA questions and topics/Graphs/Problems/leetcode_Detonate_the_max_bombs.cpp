#include<iostream>
#include<vector>
#include<unordered_set>
#include<cmath>
#include"../../abhi.h"
using namespace std;

void prepareAdjList(vector<vector<int>> &adjList, vector<vector<int>>& bombs, int &n){
        for(int i=0; i<n; i++){
            int xi = bombs[i][0];
            int yi = bombs[i][1];
            int ri = bombs[i][2];
        
            for(int j=0; j<n; j++){
                if(i != j){
                    int xj = bombs[j][0];
                    int yj = bombs[j][1];
                    long double sum = pow(yj-yi, 2) + pow(xj-xi, 2);
                    long double dist = pow(sum, 0.5);

                    if(dist<=ri) adjList[i].push_back(j);
                }
            }
        }
    }

void dfs(int bomb, unordered_set<int> &visited, vector<vector<int>> &adjList, int &count){
        visited.insert(bomb);
        count++;

        for(int neighbour : adjList[bomb]){
            if(visited.find(neighbour) == visited.end()){
                dfs(neighbour, visited, adjList, count);
            }
        }
    }

int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adjList(n);
        int ans = 0;
        prepareAdjList(adjList, bombs, n);

        // cout<<"Adjacency list: "<<endl;
        // printArray2D(adjList);

        for(int i=0; i<n; i++){
            int count = 0;
            unordered_set<int> visited;
            dfs(i, visited, adjList, count);
            // cout<<"i: "<<i<<" count: "<<count<<endl;
            ans = max(count, ans);
        }
        return ans;
    }

int main(){
    
    vector<vector<int>> bombs{{647,457,91},{483,716,37},{426,119,35},{355,588,40},{850,874,49},{232,568,46},{886,1,30},{54,377,3},{933,986,50},{305,790,49},{372,961,67},{671,314,58},{577,221,29},{380,147,91},{600,535,1},{806,329,64},{536,753,18},{906,88,23},{436,783,82},{652,674,45},{449,668,20},{419,13,66},{853,767,60},{169,288,33},{871,608,66},{337,445,35},{388,623,39},{723,503,81},{14,19,19},{98,648,72},{147,565,93},{655,434,1},{407,663,22},{805,947,83},{942,160,70},{959,496,93},{30,988,53},{187,849,60},{980,483,41},{663,150,76},{268,39,50},{513,522,75},{61,450,90},{115,231,12},{346,304,74},{385,540,23},{905,178,19},{336,896,81},{751,811,94},{527,783,78},{635,965,19},{334,290,39},{748,460,77},{414,134,22},{955,485,29},{925,787,43},{243,771,75},{675,223,29},{788,618,82},{462,544,30},{999,259,50},{210,146,12},{789,442,70},{286,36,55},{451,953,6},{719,914,14},{664,452,14},{933,637,29},{206,926,16},{100,422,98},{97,333,4},{505,631,26},{908,287,65},{907,316,86},{949,185,16},{639,735,62},{401,739,18},{605,926,21},{25,391,69},{80,24,9},{435,874,92},{940,381,18},{260,740,87},{727,515,17},{361,152,16},{512,470,67},{189,27,27},{517,439,94},{159,543,76},{373,698,38},{781,836,97},{584,190,23},{383,367,86},{825,141,63},{117,926,85},{169,588,60},{56,981,100},{294,716,100},{781,370,89},{373,44,78}};

    int ans = maximumDetonation(bombs);

    cout<<"Answer: "<<ans;

    return 0;
}