class Solution {
public:
    long long mod = 1e9 + 7;
    int numSub(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; ){
            int countOne = 0, j = i;
            if(s[j] == '1'){
                while(j < n && s[j] == '1'){
                    countOne++;
                    j++;
                }
                long long count = (countOne % mod) * ((countOne + 1) % mod) % mod;
                count = count / 2;
                ans = ans + count;
                i = j;
            }
            else i++;
        }
        return ans;
    }
};