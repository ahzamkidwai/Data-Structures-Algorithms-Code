class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        int g = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1) ones++;
            g = __gcd(g, nums[i]);
        } 
        if(ones) return (n-ones);
        if(g > 1) return -1;
        int minLen = n;
        for(int i=0; i<n; i++){
            int hcf = nums[i];
            for(int j=i; j<n; j++){
                hcf = __gcd(hcf, nums[j]);
                if(hcf == 1){
                    minLen = min(minLen, j-i+1);
                    break;
                }
            }
        }
        return minLen+n-2;
    }
};