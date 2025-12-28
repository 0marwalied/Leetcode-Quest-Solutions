#define all(v)    v.begin(),v.end()

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // dist[node][bus]
        const int n = routes.size();
        if (source == target)return 0;
        vector<int>sourceBusPos;
        int mx = 0;
        for (auto &it : routes)mx = max(mx, *max_element(all(it)));
        vector<vector<vector<int>>>graph(mx + 1);
        for (int bus = 0; bus < n; bus++) {
            int sz = routes[bus].size();
            for (int r = 0; r < sz; r++) {
                int next = (r + 1) % sz;
                graph[routes[bus][r]].push_back({routes[bus][next], bus});
                if (source == routes[bus][r])sourceBusPos.push_back(bus);
            }

        }
        queue<vector<int>>q;
        vector<vector<int>>dist(mx + 1, vector<int>(n, 1e9));
        for (auto &it : sourceBusPos) {
            dist[source][it] = source != target;
            q.push({source, it});
        }

        int ans = INT_MAX;

        while (!q.empty()) {
            vector<int>cur = q.front();
            q.pop();
            int node = cur[0], bus = cur[1];
            if (node == target)
                ans = min(ans, dist[node][bus]);
            for (auto &it : graph[node]) {
                int nNode = it[0], nBus = it[1];
                if (dist[nNode][nBus] > dist[node][bus] + (nBus != bus)) {
                    dist[nNode][nBus] = dist[node][bus] + (nBus != bus);
                    q.push({nNode, nBus});
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};