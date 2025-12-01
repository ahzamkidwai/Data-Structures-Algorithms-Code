class Solution {
private:
    bool canRun(int n, const vector<int>& batteries, long long targetTime) {
        long long totalEffectiveTime = 0;
        
        for (int b : batteries) {
            // A battery 'b' can contribute its full charge 'b'
            // or just the required 'targetTime' (if b > targetTime).
            // We take the minimum of these two values as its effective contribution.
            totalEffectiveTime += min((long long)b, targetTime);
        }

        // The total time required by 'n' computers is n * targetTime.
        // If our total effective time meets this requirement, the run is possible.
        return totalEffectiveTime >= (long long)n * targetTime;
    }

public:
    long long maxRunTime(int n, vector<int>& batteries) {
        if (batteries.size() < n) {
            return 0; // Not enough batteries for all computers, assuming one battery is needed per computer at any time.
        }

        // 1. Define the search space for the time T
        
        // Lower bound (low): Minimum possible time is 0.
        long long low = 0;
        
        // Upper bound (high): Maximum theoretical time is total energy divided by number of computers.
        // We use 'long long' for the sum to prevent overflow (batteries[i] can be up to 10^9, size up to 10^5).
        long long sumCapacity = 0;
        for (int b : batteries) {
            sumCapacity += b;
        }
        long long high = sumCapacity / n;
        
        long long maxTime = 0;

        // 2. Perform Binary Search
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canRun(n, batteries, mid)) {
                // 'mid' is a possible time. We try to find an even larger time.
                maxTime = mid;
                low = mid + 1;
            } else {
                // 'mid' is too high. We must search in the lower half.
                high = mid - 1;
            }
        }

        return maxTime;
    }
};

// Example usage (optional, for testing):
/*
int main() {
    Solution s;
    vector<int> b1 = {10, 10, 10, 10, 10};
    int n1 = 2; // Should be 25 (50 / 2)
    cout << "Test 1 (n=2, {10,10,10,10,10}): " << s.maxRunTime(n1, b1) << endl; 
    
    vector<int> b2 = {1, 1, 1, 1, 1};
    int n2 = 3; // Should be 1 (5 / 3 = 1)
    cout << "Test 2 (n=3, {1,1,1,1,1}): " << s.maxRunTime(n2, b2) << endl; 

    vector<int> b3 = {3, 3, 3};
    int n3 = 1; // Should be 9
    cout << "Test 3 (n=1, {3,3,3}): " << s.maxRunTime(n3, b3) << endl; 
    
    return 0;
}
*/