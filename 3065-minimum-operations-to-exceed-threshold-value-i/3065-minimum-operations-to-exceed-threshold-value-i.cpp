class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (auto itr : nums) {
            if (k > itr) count++;
        }
        return count;
    }
};