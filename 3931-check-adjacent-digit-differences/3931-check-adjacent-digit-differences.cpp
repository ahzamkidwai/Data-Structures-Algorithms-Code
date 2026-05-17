class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        for (int i=0; i < n-1; i++) {
            if (abs((s[i]-'48')-(s[i+1]-'48')) > 2) return false;
        }
        return true;
    }
};