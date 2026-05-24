class Solution {
public:
    bool checkDivisibility(vector<int> &nums, int divisor, int threshold) {
        long long int sum = 0;
        for (auto it : nums) {
            sum = sum + it / divisor;
            if (it % divisor != 0) sum = sum + 1;
        }
        if (sum <= threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        int low = 1, high = maxEle;
        int ans = 0;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (checkDivisibility(nums, mid, threshold)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};