class Solution {
public:
    int countPalindromicSubsequence(std::string s) {
        std::vector<int> first_idx(26, -1);
        std::vector<int> last_idx(26, -1);

        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int char_code = s[i] - 'a';
            if (first_idx[char_code] == -1) {
                first_idx[char_code] = i;
            }
            last_idx[char_code] = i;
        }
        int unique_palindromes_count = 0;
        for (int i = 0; i < 26; ++i) {
            int start = first_idx[i];
            int end = last_idx[i];
            if (start == -1 || start == end) {
                continue;
            }
            std::unordered_set<char> middle_chars;
            for (int j = start + 1; j < end; ++j) {
                middle_chars.insert(s[j]);
            }
            unique_palindromes_count += middle_chars.size();
        }
        return unique_palindromes_count;
    }
};
