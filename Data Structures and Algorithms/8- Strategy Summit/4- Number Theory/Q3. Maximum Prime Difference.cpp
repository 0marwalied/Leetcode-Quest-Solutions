bool is_prime(int n) {
    if (n == 2)return 1;
    if (n < 2 || n % 2 == 0)return 0;
    for (int i = 3; i <= n / i; i += 2)if (n % i == 0)return 0;
    return 1;
}

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int start = -1, end = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (is_prime(nums[i])) {
                if (start == -1)start = i;
                end = i;
            }
        }
        return end - start;
    }
};