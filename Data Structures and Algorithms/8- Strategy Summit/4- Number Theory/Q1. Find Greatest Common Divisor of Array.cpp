#define all(v)    v.begin(),v.end()

class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(all(nums));
        return __gcd(*nums.begin(), *nums.rbegin());
    }
};