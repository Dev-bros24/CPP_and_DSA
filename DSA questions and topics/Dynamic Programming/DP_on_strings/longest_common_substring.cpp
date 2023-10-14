// slight modification in LCS code, that we just increase in case of a match otherwise not 
// in tabulation method. 

class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        vector<vector<int>> tab(n+1, vector<int>(m+1, 0));
        int maxi = 0;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s1[i-1] == s2[j-1]) tab[i][j] = 1 + tab[i-1][j-1];
			maxi = max(maxi, tab[i][j]);
		}
	}	
	
	return maxi;
    }
};