class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        sum = sum + nums[0];
        for(int i=1; i<n; i++) sum = sum + nums[i];
        int sum1 = 0, ans = 0;
        for(int i=0; i<n-1; i++){
            sum1 = sum1 + nums[i];
            int sum2 = sum - sum1;
            int diff = abs(sum2 - sum1);
            cout << sum1 << " " << sum2 << " " << sum << endl;
            if(diff % 2 == 0) ans++; 
        }
        return ans;
    }
};