class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return abs(nums[1]-nums[0]);
        int maxEle = *max_element(nums.begin(), nums.end());
        int minEle = *min_element(nums.begin(), nums.end());
        if(maxEle == minEle) return 0;
        int sum = 0;
        for(int i=0; i<n; i++) sum = sum + nums[i];
        return (sum - (n * minEle));
    }
};