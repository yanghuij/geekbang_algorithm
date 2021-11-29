//200. 岛屿数量
//https://leetcode-cn.com/problems/number-of-islands/
//并查集
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        const int dx[4] = {1, 0, 0, -1};
        const int dy[4] = {0, -1, 1, 0};
        m = grid.size();
        n = grid[0].size();

        fa = vector<int>(m * n, 0);
        for (int i = 0; i < m * n; i++) fa[i] = i;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
                    if (grid[ni][nj] == '1') {
                        unionSet(num(i, j), num(ni, nj));
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && find(num(i, j)) == num(i, j))
                    ans++;               
            }
        }

        return ans;
    }

private:
    int num(int i, int j) {
        return i * n + j;
    }

    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) fa[x] = y;
    }

    int m, n;
    vector<int> fa;
};