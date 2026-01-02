class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>divs;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
                if (i != n / i)divs.push_back(n / i);
            }
        }
        sort(divs.begin(), divs.end());
        for (auto &it : divs) {
            k--; if (!k)return it;
        }
        return -1;
    }
};