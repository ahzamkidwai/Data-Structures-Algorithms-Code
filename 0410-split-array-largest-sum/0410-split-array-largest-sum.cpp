class Solution {
public:
    int countPartitions(vector<int> &nums, int mid, int k) {
        long long int sum = 0, partitions = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= mid) sum += nums[i];
            else {
                partitions++;
                sum = nums[i];
            }
        }
        return partitions;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            int ans = countPartitions(nums, mid, k);
            if (ans <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};