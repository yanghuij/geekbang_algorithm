//1091. 二进制矩阵中的最短路径
//https://leetcode-cn.com/problems/shortest-path-in-binary-matrix/
class Solution {
public:
    //BFS
    /*int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return -1;

        const int dx[8] = {1,  1,  0, -1, -1, -1, 0, 1};
        const int dy[8] = {0, -1, -1, -1,  0,  1, 1, 1};
        int n = grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> depth = vector(n, vector(n, -1));

        depth[0][0] = 1;
        q.push({0, 0});

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (depth[nx][ny] != -1) continue;
                if (grid[nx][ny] != 0) continue;

                depth[nx][ny] = depth[x][y] + 1;
                if ((nx == n - 1) && (ny == n - 1)) return depth[nx][ny];
                q.push({nx, ny});
            }
        }

        return depth[n - 1][n - 1];
    }*/

    //双向BFS，要逐层处理
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0) return -1;
        if (grid[n - 1][n - 1] != 0) return -1;
        if (n == 1) return 1;

        queue<pair<int, int>> qStart, qEnd;
        vector<vector<int>> depthStart = vector(n, vector(n, 0));
        vector<vector<int>> depthEnd = vector(n, vector(n, 0));

        depthStart[0][0] = 1;
        qStart.push({0, 0});

        depthEnd[n - 1][n - 1] = 1;
        qEnd.push({n - 1, n - 1});

        while (!qStart.empty() && !qEnd.empty()) {
            int res = expand(grid, qStart, depthStart, depthEnd);
            if (res != -1) return res;
            res = expand(grid, qEnd, depthEnd, depthStart);
            if (res != -1) return res;
        }

        return -1;
    }

private:
    int expand(vector<vector<int>>& grid, queue<pair<int, int>>& q, vector<vector<int>>& depth, vector<vector<int>>& depthOther) {
        if (q.empty()) return -1;

        const int dx[8] = {1,  1,  0, -1, -1, -1, 0, 1};
        const int dy[8] = {0, -1, -1, -1,  0,  1, 1, 1};
        int n = grid.size();
        int qSize = q.size();

        while (qSize--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (depth[nx][ny] != 0) continue;
                if (grid[nx][ny] != 0) continue;
                if (depthOther[nx][ny] != 0) {
                    return depth[x][y] + depthOther[nx][ny];
                }

                depth[nx][ny] = depth[x][y] + 1;          
                q.push({nx, ny});
            }
        }

        return -1;
    }
};
