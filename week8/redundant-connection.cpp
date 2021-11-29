//684. 冗余连接
//https://leetcode-cn.com/problems/redundant-connection/
//并查集
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        fa = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }

        for (vector<int>& edge : edges) {
            int x = edge[0];
            int y = edge[1];

            //两端已经在同一个集合中，再加上这条边就出现了环
            if (find(x) == find(y)) {
                return edge;
            } else {
                unionSet(x, y);
            }
        }

        return {};
    }

private:
    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) fa[x] = y;
    }

    int n;
    vector<int> fa;
};