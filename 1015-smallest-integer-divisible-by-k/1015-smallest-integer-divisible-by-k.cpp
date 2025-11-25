class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 1) return 1;
        if(k % 2 == 0 || k % 5 == 0) return -1;
        long long num = 1;
        int digits = 1;
        while(digits <= k){
            if(num % k == 0) return digits;
            num = (num * 10) % k;
            num = (num + 1) % k;
            digits++;
        }
        return -1;
    }
};