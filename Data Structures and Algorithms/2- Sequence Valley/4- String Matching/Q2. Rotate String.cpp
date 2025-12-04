#define all(v)    v.begin(),v.end()

class Solution {
public:
    bool rotateString(string s, string goal) {
        deque<int>dq1(all(s)), dq2(all(goal));
        int n = goal.size();
        while (n--) {
            if (dq1 == dq2)return true;
            dq1.push_back(dq1.front());
            dq1.pop_front();
        }
        return false;
    }
};