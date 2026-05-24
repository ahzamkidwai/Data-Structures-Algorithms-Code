class Solution {
public:
    bool checkEatingSpeed(vector<int> &piles, int speed, int h) {
        long long int totalTime = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalTime += piles[i] / speed;
            if (piles[i] % speed != 0) totalTime += 1;
        }
        if (totalTime <= h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxEle = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxEle;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (checkEatingSpeed(piles, mid, h)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};