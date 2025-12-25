struct DSU {
    vector<int>par, sz;
    vector<vector<int>>blocked;
    DSU(int n) {
        par.resize(n + 1);
        sz.resize(n + 1);
        blocked.resize(n + 1);
        for (int i = 1; i <= n; i++)
            par[i] = i, sz[i] = 1;
    }
    int find(int x) {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    bool uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y], par[y] = x;
        }
        return true;
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DSU friends(n - 1);

        vector<bool>ans;
        for (auto &it : requests) {
            bool valied = true;
            int fir = friends.find(it[0]), sec = friends.find(it[1]);
            for (auto &it : restrictions) {
                int a = friends.find(it[0]), b = friends.find(it[1]);
                if (a == fir && b == sec || b == fir && a == sec) {
                    valied = false; break;
                }
            }
            ans.push_back(valied);
            if (valied)friends.uni(it[0], it[1]);
        }

        return ans;
    }
};