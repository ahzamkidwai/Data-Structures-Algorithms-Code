//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solveEditDistance(string s1, string s2, int i, int j, vector<vector<int>> &dp) {
        if(i >= s1.size()) {
            return s2.size() - j;
        }
        if(j >= s2.size()) {
            return s1.size() - i;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s1[i] == s2[j]) {
            dp[i][j] = solveEditDistance(s1, s2, i+1, j+1, dp);
        } else {
            int insertion = 1 + solveEditDistance(s1, s2, i, j+1, dp);
            int deletion = 1 + solveEditDistance(s1, s2, i+1, j, dp);
            int replace = 1 + solveEditDistance(s1, s2, i+1, j+1, dp);
            dp[i][j] = min({insertion, deletion, replace});
        }
        return dp[i][j];
    }

    int editDistance(string str1, string str2) {
        if(str1 == str2) 
            return 0;
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); // Initializing the DP table with dimensions n x m
        return solveEditDistance(str1, str2, 0, 0, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends