class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int>pos(1e4 + 1), neg(1e4 + 1);
        for (auto &it : nums) {
            if (it >= 0) pos[it]++;
            else neg[-it]++;
        }
        for (int i = 1e4; i >= 0; i--) {
            k -= pos[i];
            if (k <= 0)return i;
        }
        for (int i = -1; i >= -1e4; i--) {
            k -= neg[-i];
            if (k <= 0)return i;
        }
        return 0;
    }
};