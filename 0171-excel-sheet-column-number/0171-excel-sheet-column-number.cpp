class Solution {
public:
    int titleToNumber(string s) {
        reverse(s.begin(), s.end());
        unordered_map<char, int> m;
        for(int i=1; i<=26; i++){
            m[char(i + 64)] = i;
        }
        long long int N = 26;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            int num = m[ch];
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