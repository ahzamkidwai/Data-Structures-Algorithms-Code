class Solution {
public:
    pair<int, int> findMaxAndMin(vector<int> &bloomDay) {
        int n = bloomDay.size();
        int minEle = INT_MAX, maxEle = INT_MIN;
        for (auto itr : bloomDay) {
            if ( itr > maxEle ) maxEle = itr;
            if ( itr < minEle ) minEle = itr;
        }
        return {minEle, maxEle};
    }
    bool checkForFlowers(vector<int> &bloomDay, int day, int m, int k) {
        long long int bouquet = 0, flowers = 0;
        for (auto itr : bloomDay) {
            if (itr <= day) {
                flowers++;
                if (flowers % k == 0) bouquet++;
            } else {
                flowers = 0;
            }
        }
        cout << "Bouquet = " << bouquet << " and day is : " << day << endl;
        if (bouquet >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // long long int product = m * k;
        // if (product > n) return -1;
        long long int div = n / k;
        if (div < m) return -1;
        pair<int, int> p = findMaxAndMin(bloomDay);
        int minEle = p.first;
        int maxEle = p.second;
        int low = minEle, high = maxEle;
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (checkForFlowers(bloomDay, mid, m, k)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }   
};