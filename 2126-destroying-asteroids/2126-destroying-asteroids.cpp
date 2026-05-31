class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long int sum = mass;
        sort(asteroids.begin(), asteroids.end());
        for (auto itr : asteroids) {
            if (sum >= itr) {
                sum += itr;
            } else return false;
        } 
        return true;
    }
};