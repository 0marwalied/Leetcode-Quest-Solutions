class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s;
        int low = 1, high = max(3, 2 * (int)b.size() / (int)a.size()), mid, ans = -1;
        while (low <= high) {
            mid = (low + high) >> 1;

            bool valied = false;
            string s;
            {
                for (int i = 0; i < mid; i++)s += a;
                for (int i = 0; i + b.size() <= s.size(); i++)
                    valied |= (s.substr(i, b.size()) == b);
            }

            if (valied)high = mid - 1, ans = mid;
            else low = mid + 1;
        }
        return ans;
    }
};