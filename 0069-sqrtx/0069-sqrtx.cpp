class Solution {
public:
    int mySqrt(int x) {
        long long int low = 0, high = x;
        long long int num = x;
        while (low <= high) {
            long long int mid = ((high - low) / 2) + low;
            if (mid * mid == num) return mid;
            if (mid * mid < num) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};