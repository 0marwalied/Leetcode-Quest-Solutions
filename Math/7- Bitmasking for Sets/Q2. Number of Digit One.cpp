class Solution {
public:
    int dp[10][10][2];
    int solve(int i, int cnt, bool change, const string& s) {
        if (i == s.size())return cnt;
        int &ret = dp[i][cnt][change];
        if (~ret)return ret;
        ret = 0;
        char last = (change ? '9' : s[i]);
        for (char d = '0'; d <= last; d++) {
            if (d < s[i])
                ret += solve(i + 1, cnt + (d == '1'), 1, s);
            else
                ret += solve(i + 1, cnt + (d == '1'), change, s);
        }
        return ret;
    }
    int countDigitOne(int n) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, 0, to_string(n));
    }
};