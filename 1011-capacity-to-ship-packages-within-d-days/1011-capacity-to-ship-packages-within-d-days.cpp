class Solution {
public:
    int findNumberOfDays(vector<int> &weights, int mid, int days) {
        long long int sum = 0, countDays = 0;
        for (auto itr : weights) {
            if (sum + itr <= mid) sum = sum + itr;
            else {
                sum = itr; 
                countDays++;
            }
        }
        if (sum != 0) countDays++;
        return countDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxEle = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int low = maxEle, high = sum;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            int ans = findNumberOfDays(weights, mid, days);
            if (ans <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};