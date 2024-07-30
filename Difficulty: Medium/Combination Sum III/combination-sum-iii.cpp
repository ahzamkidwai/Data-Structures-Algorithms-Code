//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int ind, std::vector<int> &arr, int k, int sum, std::vector<std::vector<int>> &ans, std::vector<int> &temp) {
        // Base cases
        if (k == 0 && sum == 0) {
            ans.push_back(temp);
            return;
        }
        if (ind >= arr.size() || k == 0 || sum < 0) {
            return;
        }
        temp.push_back(arr[ind]);
        solve(ind + 1, arr, k - 1, sum - arr[ind], ans, temp);
        temp.pop_back(); // backtrack
        solve(ind + 1, arr, k, sum, ans, temp);
    }
    vector<vector<int>> combinationSum(int k, int sum) {
        vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int n = arr.size();
        vector<int> dp(n+1, -1);
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, arr, k, sum,  ans, temp);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends