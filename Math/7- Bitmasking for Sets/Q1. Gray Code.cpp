class Solution {
public:
    vector<int> grayCode(int n) {
        int cur = 0;
        vector<int>vis(1 << n);
        vis[0] = true;
        vector<int>ans = {0};
        for (int i = 0; i < (1 << n); i++) {
            for (int b = 0; b < n; b++) {
                if (!vis[cur ^ (1 << b)]) {
                    vis[cur ^ (1 << b)] = true;
                    cur ^= (1 << b);
                    ans.push_back(cur);
                    break;
                }
            }
        }
        return ans;
    }
};