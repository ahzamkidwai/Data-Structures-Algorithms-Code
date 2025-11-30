class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        // The remainder we want the removed subarray's sum to have
        int target_rem = total_sum % p;

        if (target_rem == 0) return 0;

        // rem_to_index stores: (prefix_sum % p) -> last_seen_index
        unordered_map<int, int> rem_to_index;
        // Base case: prefix sum of 0 (empty prefix before index 0)
        rem_to_index[0] = -1;

        long long current_prefix_sum = 0;
        int min_len = nums.size();
        
        for (int j = 0; j < nums.size(); ++j) {
            current_prefix_sum += nums[j];
            int current_rem = current_prefix_sum % p;

            // We need P[i-1] % p to be 'required_rem' such that:
            // (P[j] - P[i-1]) % p == target_rem
            // Rearranging: P[i-1] % p == (P[j] - target_rem) % p
            int required_rem = (current_rem - target_rem + p) % p;

            if (rem_to_index.count(required_rem)) {
                // Found a valid subarray nums[i..j] where i-1 is the stored index + 1
                int i_minus_1_index = rem_to_index[required_rem];
                int current_len = j - i_minus_1_index;
                min_len = min(min_len, current_len);
            }
            
            // Update the map with the current prefix remainder and index
            rem_to_index[current_rem] = j;
        }

        // If min_len is still the full array size, it means no valid subarray 
        // was found that is NOT the whole array.
        return (min_len == nums.size()) ? -1 : min_len;
    }
};