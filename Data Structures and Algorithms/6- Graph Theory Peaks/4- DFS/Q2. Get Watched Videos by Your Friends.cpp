#define all(v)    v.begin(),v.end()

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        const int n = friends.size();
        vector<int>dist(n, INT_MAX);
        vector<vector<int>>graph(n);
        for (int node = 0; node < n; node++) {
            for (auto &f : friends[node]) {
                graph[node].push_back(f);
                graph[f].push_back(node);
            }
        }
        queue<int>q;
        dist[id] = 0;
        q.push(id);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &it : graph[cur]) {
                if (dist[it] > dist[cur] + 1) {
                    dist[it] = dist[cur] + 1;
                    q.push(it);
                }
            }
        }
        vector<pair<int, string>>cnt;
        map<string, int>mp;
        for (int node = 0; node < n; node++) {
            if (dist[node] == level) {
                for (auto &it : watchedVideos[node]) {
                    mp[it]++;
                }
            }
        }
        for (auto &it : mp) {
            cnt.push_back({it.second, it.first});
        }
        sort(all(cnt));
        vector<string>ans;
        for (auto &it : cnt)
            ans.push_back(it.second);
        return ans;

    }
};