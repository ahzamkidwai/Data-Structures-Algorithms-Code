class Solution {
public:
    string convertToTitle(int columnNumber) {
        int num = columnNumber;
        unordered_map<int, char> m;
        for(int i=1; i<=26; i++){
            m[i] = char(i + 64);
        }
        string ans = "";
        if(num <= 26) return (ans + m[num]);
        while(num != 0) {
            if(num <= 26) {
                ans = ans + m[num];
                break;
            }
            int rem = num % 26;
            int quo = num / 26;
            cout << "Num : " << num << " Rem : " << rem << " Quo : " << quo << endl;
            if(rem == 0) {
                ans = ans + "Z";
                num = quo - 1;
            }
            else{
                ans = ans + m[rem];
                num = num / 26;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};