class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if (n == 1) return cost[0];
        if (n == 2) return (cost[0] + cost[1]);
        sort(cost.begin(), cost.end());
        long long int sum = 0;
        int cnt = 1;
        for (int i=n-1; i>=0; i--) {
            if (cnt % 3) sum = sum + cost[i];
            cnt++;
        }
        return sum;
    }
};