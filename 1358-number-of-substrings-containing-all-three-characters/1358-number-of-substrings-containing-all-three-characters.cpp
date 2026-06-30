class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int a = -1, b = -1, c = -1, ans = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'a') a = i;
            else if (s[i] == 'b') b = i;
            else if (s[i] == 'c') c = i;
            
            if (a != -1 && b != -1 && c != -1) {
                ans = ans + min({ a, b, c }) + 1;
            }
        }
        return ans;
    }
};