class Solution {
private:
    queue<vector<int>>q;
    int n, m, dx[8] = {0, 0, -1, 1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
public:

    bool isValied(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    }

    void BFS(vector<vector<int>>& dist) {
        while (!q.empty()) {
            vector<int>pos = q.front(); q.pop();
            int x = pos[0], y = pos[1];
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (isValied(nx, ny) && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        n = isWater.size(), m = isWater[0].size();
        vector<vector<int>>points;
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j]) {
                    dist[i][j] = 0;
                    points.push_back({i, j});
                }
            }
        }

        for (auto & it : points) {
            int x = it[0], y = it[1];
            q.push({x, y});
        }
        BFS(dist);

        return dist;
    }
};