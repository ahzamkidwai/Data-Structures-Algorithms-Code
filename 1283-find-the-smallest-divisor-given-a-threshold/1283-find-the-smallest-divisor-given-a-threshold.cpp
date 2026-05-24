class Solution {
public:
    pair<int, int> findMaxAndMin(vector<int> &nums) {
        int n = nums.size();
        int minEle = INT_MAX, maxEle = INT_MIN;
        for (auto itr : nums) {
            if (itr > maxEle) maxEle = itr;
            if (itr < minEle) minEle = itr;
        }
        return {minEle, maxEle};
    }
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
        pair<int, int> p = findMaxAndMin(nums);
        int minEle, maxEle;
        minEle = p.first;
        maxEle = p.second;
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