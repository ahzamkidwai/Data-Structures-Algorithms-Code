class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n-1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if ((arr[mid] < arr[mid + 1]) && (mid + 1 < n)) low = mid + 1;
            else if ((arr[mid] > arr[mid + 1]) && (mid + 1 < n)) high = mid - 1;
        }
        return low;
        return 0;
    }
};