class Solution {
public:
    long long countVowels(string word) {
        int n = word.size();
        long long int ans = 0;
        for (int i=0; i < n; i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                long long int start = i + 1;
                long long int end = n - i;
                ans += (start * end);
            }
        }
        return ans;
    }
};