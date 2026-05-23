class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;
        if (arr[low] == low + 1 && arr[high] == high + 1) return arr[high] + k;
        int leftMissing = arr[low] - (low + 1);
        if ( leftMissing >= k) return k;
        int rightMissing = arr[high] - (high + 1);
        if (rightMissing < k) return (arr[high] + (k - rightMissing));
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            int missing = arr[mid] - (mid + 1);
            if (missing < k) low = mid + 1;
            else high = mid - 1;
        }
        int mainEle = arr[high];
        int rightMiss = mainEle - (high + 1);
        return mainEle + (k - rightMiss);
        // return arr[high] + (k - (arr[high] - (high + 1)));
    }
};