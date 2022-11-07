#include<bits/stdc++.h>
using namespace std; 

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


bool cmp(Job j1, Job j2)
{
    return j1.profit > j2.profit;
}

class Solution{
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, cmp);
        int maxi = 0;
        for(int i=0; i<n; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }

        cout<<"maxi: "<<maxi<<endl;
        
        int jobt[maxi + 1];
        for(int i=0; i<=maxi; i++)
        {
            jobt[i] = -1;
        }
        
        int count = 0;
        int profitmax = 0;
        
        for(int i=0; i<n; i++)
        {
            
            int deadline = arr[i].dead;
            cout<<"deadline: "<<deadline<<endl;
            int ti = deadline;
            while(ti != 0 && jobt[ti] != -1) 
            {
                ti--;
            }
            
            if(ti != 0)
            {
                profitmax = profitmax + arr[i].profit;
                jobt[ti] = arr[i].id;
                count++;
            }
        }
        vector<int> ans = {count, profitmax};
        return ans;
        
    } 
};

// int main() 
// { 
//     Job arr[4];
//     arr[0].id = 1;
//     arr[0].dead = 4;
//     arr[0].profit = 20;

//     arr[1].id = 2;
//     arr[1].dead = 1;
//     arr[1].profit = 10;

//     arr[2].id = 3;
//     arr[2].dead = 1;
//     arr[2].profit = 40;

//     arr[3].id = 4;
//     arr[3].dead = 1;
//     arr[3].profit = 30;

//     vector<int> ans = JobScheduling(arr, 4);

//     cout<<"Ans: "<<endl;
//     cout<<ans[0]<<" "<<ans[1];

// 	return 0; 
// }




/////////////////////=================================


 
int main() 
{ 
    int t;
    //testcases
    cout<<"testcases: "<<endl;
    cin >> t;
    
    while(t--){
        
        int n;
        
        //size of array
        cout<<"size: "<<endl;
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        cout<<"Enter values: "<<endl;
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        cout<<"Abhishek calling func: "<<endl;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<"Answer: "<<endl;
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends




