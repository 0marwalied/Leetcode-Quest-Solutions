class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        while (b) {
            c = (a & b);
            a = a ^ b;
            b = c << 1;
        }
        return a;
    }
};