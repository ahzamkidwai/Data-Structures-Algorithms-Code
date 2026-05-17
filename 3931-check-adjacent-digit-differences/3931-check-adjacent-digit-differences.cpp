class Solution {
public:
    int convertCharToNum(char ch) {
        return (int(ch) - 48);
    }
    bool isAdjacentDiffAtMostTwo(string s) {
        bool f = true;
        int n = s.size();
        for (int i=0; i<n-1; i++) {
            int num1 = convertCharToNum(s[i]);
            int num2 = convertCharToNum(s[i+1]);
            int diff = abs(num1 - num2);
            cout << "Diff : " << diff << endl;
            if (diff > 2) return false;
        }
        return true;
    }
};