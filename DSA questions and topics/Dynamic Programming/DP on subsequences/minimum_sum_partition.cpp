//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0; i<n; i++) sum += arr[i];
	    
	    vector<int> prev(sum+1, -1);
	    
	    for(int i=0; i<=sum; i++) prev[i] = false;
	    prev[0] = true;
	    
	    for(int i=1; i<=n; i++){
	        vector<int> curr(sum+1);
	        for(int j=0; j<=sum; j++){
	            if(arr[i-1] <= j) curr[j] = prev[j] || prev[j - arr[i-1]];
	            else curr[j] = prev[j];
	        }
	        prev = curr;
	    }
	    
	    int mini = INT_MAX;
	    for(int i=0; i<=sum/2; i++){
	        if(prev[i]) mini = min(mini, sum-2*i);
	    }
	    
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends