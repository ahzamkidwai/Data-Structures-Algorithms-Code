class Solution {
public:
    int findSubsequence(int index, vector<int> &nums, int rem, vector<vector<int>> &dp){
        int n = nums.size();
        if (index == n)
            return rem == 0 ? 0 : INT_MIN;
        if (dp[index][rem] != -1) return dp[index][rem];

        int take = nums[index] + findSubsequence(index + 1, nums, (rem + nums[index]) % 3, dp);
        int skip = findSubsequence(index + 1, nums, rem, dp);

        return dp[index][rem] = max(take, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int ans = findSubsequence(0, nums, 0, dp);
        return max(0, ans);  
    }
};
