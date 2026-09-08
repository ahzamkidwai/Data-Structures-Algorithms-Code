class Solution {
public:
    int trailingZeroes(int n) {
        int numberOfTrailingZeros = 0;
        int twos = 0, fives = 0;
        while (n > 0) {
            int num = n;
            while (num % 2 == 0) {
                twos++;
                num /= 2;
            }
            while (num % 5 == 0) {
                fives++;
                num /= 5;
            }
            n--;
        }
        numberOfTrailingZeros = min(twos, fives);
        return numberOfTrailingZeros;
    }
};