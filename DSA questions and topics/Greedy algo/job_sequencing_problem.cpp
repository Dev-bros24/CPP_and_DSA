#include <bits/stdc++.h> 
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
        return p1.second > p2.second; 
}

int jobScheduling(vector<vector<int>> &jobs)
{
    vector<pair<int, int>> vec;
    for(int i=0; i<jobs.size(); i++)
    {
        pair<int, int> pa = make_pair(jobs[i][0], jobs[i][1]);
        vec.push_back(pa);
    }

    cout<<"Abhishek: "<<endl;
    for(auto val : vec)
    {
        cout<<val.first<<" "<<val.second<<endl;
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    cout<<"Abhishek sort: "<<endl;
    for(auto val : vec)
    {
        cout<<val.first<<" "<<val.second<<endl;
    }

    int max = 0;
    for(int i=0 ; i<vec.size(); i++)
    {
        if(vec[i].first > max)
        {
            max = vec[i].first;
        }
    }
    
    cout<<"Max: "<<max<<endl;
    int n = max;
    vector<int> jobt(n+1,-1);
    int profit = 0;
    
    for(int i=0; i<vec.size(); i++)
    {
        int deadline = vec[i].first;
        int ti = deadline;
        while(ti != 0 && jobt[ti] != -1)
        {
            ti--;
        }
        if(ti != 0)
        {
            profit = profit + vec[i].second;
            jobt[ti] = 1;
        }
    }
    
    return profit;
}

int main()
{
    vector<vector<int>> jobs = {{1,23},{2,22}, {1,90},{1,80},{2,50}};
    cout<<"Jobs vector below: "<<endl;

    for(int i=0; i<jobs.size(); i++)
    {
        for(int j=0; j<jobs[i].size(); j++)
        {
            cout<<jobs[i][j]<<" ";
        }
        cout<<endl;
    }
    

    int answer = jobScheduling(jobs);

    cout<<"Answer: "<<answer;

//     1  2  1  1  2
//     23 22 90 80 50
    return 0;
}
