class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ans;
        int rem = 0;
        for(int i = 0; i < n; i++){
            rem = (rem * 2) + nums[i];
            rem = rem % 5;
            if(rem == 0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};