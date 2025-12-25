struct DSU {
    map<int, int>par, sz;
    int find(int x) {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y], par[y] = x;
        }
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        DSU dsu;
        for (auto &it : nums)
            dsu.sz[it] = 1, dsu.par[it] = it;
        for (auto &it : nums)
            if (dsu.sz.count(it - 1))dsu.uni(it, it - 1);
        int ans = 0;
        for (auto &it : dsu.sz) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};