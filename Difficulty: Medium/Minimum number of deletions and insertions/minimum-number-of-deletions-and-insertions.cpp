//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int ind1, int ind2, string s1, string s2, int n, int m, vector<vector<int>> &dp) {
        if(ind1 >= n || ind2 >= m)
            return 0;
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]) {
            return dp[ind1][ind2] = 1 + solve(ind1 + 1, ind2 + 1, s1, s2, n, m, dp);
        }
        return dp[ind1][ind2] = max(solve(ind1, ind2 + 1, s1, s2, n, m, dp), solve(ind1 + 1, ind2, s1, s2, n, m, dp));
    }

	int minOperations(string str1, string str2) 
	{ 
	   
	    int n = str1.size(), m = str2.size();
	    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
	    string temp = "";
	    int minSub = solve(0, 0, str1, str2, n, m, dp);
	    if(minSub == m){
	        return n-m;
	    }
	    return ((n-minSub)+(m-minSub));
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends