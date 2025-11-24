class Solution {
public:
    int titleToNumber(string s) {
        reverse(s.begin(), s.end());
        long long int N = 26;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            int num = int(s[i]) - 64;
            if(i == 0) ans = ans + num;
            else if(i == 1) ans = ans + (num * N);
            else {
                N = N * 26;
                ans = ans + (num * N);
            }
        }
        return ans;
    }
};