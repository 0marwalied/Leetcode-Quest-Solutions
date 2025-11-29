class Solution {
public:
    int trailingZeroes(int n) {
        int cntFor2(0), cntFor5(0), cur;
        for (int i = 1; i <= n; i++) {
            cur = i; while (cur % 2 == 0)cntFor2++, cur /= 2;
            cur = i; while (cur % 5 == 0)cntFor5++, cur /= 5;
        }
        return min(cntFor2, cntFor5);
    }
};
