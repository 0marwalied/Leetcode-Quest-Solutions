class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>>graph(n);
        for (auto &it : redEdges)
            graph[it[0]].push_back({it[1], 1});
        for (auto &it : blueEdges)
            graph[it[0]].push_back({it[1], 0});
        vector<vector<int>>dist(2, vector<int>(n, 1e9));
        auto BFS = [&](int last)->void{
            dist[last][0] = 0;
            queue<vector<int>>q;
            q.push({0, last});
            while (!q.empty()) {
                vector<int>cur = q.front(); q.pop();
                int node = cur[0], Last = cur[1];
                for (auto &it : graph[node]) {
                    if (dist[it[1]][it[0]] > dist[Last][node] + 1 && it[1] != Last) {
                        dist[it[1]][it[0]] = dist[Last][node] + 1;
                        q.push({it[0], it[1]});
                    }
                }
            }
        };
        BFS(0), BFS(1);
        vector<int>ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = min(dist[0][i], dist[1][i]);
            if (ans[i] == 1e9)ans[i] = -1;
        }
        return ans;

    }
};