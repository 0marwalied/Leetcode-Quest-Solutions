class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i < s.size(); i++) {
            if (s.size() % i == 0) {
                string sub = s.substr(0, i);
                string use;
                while (use.size() < s.size())use += sub;
                if (use == s)return true;
            }
        }
        return false;
    }
};