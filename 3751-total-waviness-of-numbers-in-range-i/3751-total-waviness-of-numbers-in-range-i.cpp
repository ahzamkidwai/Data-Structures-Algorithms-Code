class Solution {
public:
    int findTotalCount(int num) {
        vector<int> digits;
        while (num != 0) {
            int rem = num % 10;
            digits.push_back(rem);
            num = num / 10;
        }
        if (digits.size() <= 2) return 0;
        reverse(digits.begin(), digits.end());
        long long int count = 0;
        for (int i = 1; i < digits.size()-1; i++) {
            if ((digits[i-1] < digits[i]) && (digits[i] > digits[i+1])) count++;
            else if ((digits[i-1] > digits[i]) && (digits[i] < digits[i+1])) count++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        long long int sum = 0;
        for (int i=num1; i<=num2; i++) {
            sum += findTotalCount(i);
        }
        return sum;
    }
};