#define all(v)    v.begin(),v.end()

struct DSU {
    vector<int>par, sz;
    DSU(int n) {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++)
            par[i] = i, sz[i] = 1;
    }
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
    int largestComponentSize(vector<int>& nums) {
        DSU dsu(1e5);
        dsu.sz.assign(1e5, 0);
        for (auto &it : nums)
            dsu.sz[it] = 1;
        for (auto &it : nums) {
            for (int i = 2; i * i <= it; i++) {
                if (it % i == 0) {
                    dsu.uni(i, it);
                    if (i != it) {
                        dsu.uni(i, it / i);
                    }
                }
            }
        }
        return *max_element(all(dsu.sz));
    }
};