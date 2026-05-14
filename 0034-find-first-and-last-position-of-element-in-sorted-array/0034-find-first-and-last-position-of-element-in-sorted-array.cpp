class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int firstOccurrence = -1, lastOccurrence = -1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (nums[mid] == target) {
                if (mid - 1 >= 0 && nums[mid - 1] != target) {
                    firstOccurrence = mid;
                    break;
                } else if (mid - 1 >= 0 && nums[mid - 1] == target) {
                    high = mid - 1;
                } else if (mid == 0) {
                    firstOccurrence = mid;
                    break;
                }
            }
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        low = 0, high = n-1;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (nums[mid] == target) {
                if (mid + 1 < n && nums[mid+1] != target) {
                    lastOccurrence = mid;
                    break;
                } else if (mid + 1 < n && nums[mid+1] == target) {
                    low = mid + 1;
                } else if (mid == n-1) {
                    lastOccurrence = n-1;
                    break;
                }
            }
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return {firstOccurrence, lastOccurrence};
    }
};