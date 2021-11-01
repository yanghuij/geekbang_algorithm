//130. 被围绕的区域
//https://leetcode-cn.com/problems/surrounded-regions/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        //左右两边找O
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) bfs(board, i, 0);
            if (board[i][n - 1] == 'O' && !visited[i][n - 1]) bfs(board, i, n - 1);
        }

        //上下两边找O
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !visited[0][j]) bfs(board, 0, j);
            if (board[m - 1][j] == 'O' && !visited[m - 1][j]) bfs(board, m - 1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
    }

private:
    void bfs(vector<vector<char>>& board, int i, int j) {
        const int dx[4] = {-1, 0, 0, 1};
        const int dy[4] = {0, 1, -1, 0};
        queue<pair<int, int>> q;

        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= m || ny < 0 || ny >=n) continue;
                if (board[nx][ny] != 'O' || visited[nx][ny]) continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    int m;
    int n;
    vector<vector<bool>> visited;
};