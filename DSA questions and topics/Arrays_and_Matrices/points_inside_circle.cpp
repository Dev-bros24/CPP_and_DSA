#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int m = points.size(), n = queries.size();

        vector<int> ans;

        for(int i=0; i<n; i++){ // queries
            int count = 0; // point count
            for(int j=0; j<m; j++){ // points
                double diffy = queries[i][1]-points[j][1];
                double diffx = queries[i][0]-points[j][0];
                double sqy = pow(diffy, 2), sqx = pow(diffx, 2);
                double dist = pow(sqx+sqy, 0.5);
                if(dist<=queries[i][2]) count++;
            }
            ans.push_back(count);
        }

        return ans;
    }

int main(){
    vector<vector<int>> queries{{1,2,2},{2,2,2},{4,3,2},{4,3,3}};
    vector<vector<int>> points{{1,1},{2,2},{3,3},{4,4},{5,5}};

    vector<int> ans = countPoints(points, queries);

    cout<<"Answer"<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}