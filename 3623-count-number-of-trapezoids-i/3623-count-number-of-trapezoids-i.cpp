class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long long mod = 1e9 + 7;
        unordered_map<int, long long> freq;

        for (auto &p : points)
            freq[p[1]]++;

        long long sum = 0;  // Σ C(f,2)
        long long c2  = 0;  // Σ (C(f,2))^2

        // modular inverse of 2
        const long long inv2 = 500000004;

        for (auto &[y, f] : freq) {
            if (f < 2) continue;

            long long c = (f * (f - 1)) % mod;
            c = (c * inv2) % mod;  // C(f,2)

            sum = (sum + c) % mod;
            c2 = (c2 + (c * c) % mod) % mod;
        }

        // compute (sum^2 - c2) / 2
        long long ans = ( (sum * sum) % mod - c2 + mod ) % mod;
        ans = (ans * inv2) % mod;

        return ans;
    }
};
