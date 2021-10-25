//210. 课程表 II
//https://leetcode-cn.com/problems/course-schedule-ii/

/*class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses, vector<int>());
        inDegree = vector<int>(numCourses, 0);

        for (vector<int>& pre : prerequisites) {
            int ai = pre[0];
            int bi = pre[1];

            graph[bi].push_back(ai);
            inDegree[ai]++;
        }

        queue<int> q;
        vector<int> lessons;

        //拓扑排序第一步，从0入度点开始，即无先修需求的课程
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            lessons.push_back(x); //x可以选修了，处理以x为先修前提的课程

            //第二步，扩展x周围的点，看其是否可以选修了
            for (int y : graph[x]) {
                inDegree[y]--;
                if (inDegree[y] == 0) { //入度为0了，表示所有的先修课程都完成了
                    q.push(y);
                }
            }
        }

        return lessons.size() == numCourses ? lessons : vector<int>();
    }

private:
    vector<vector<int>> graph;
    vector<int> inDegree;
};*/

//dfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses, vector<int>());
        visited = vector<int>(numCourses, 0);
        valid = true;

        for (vector<int>& pre : prerequisites) {
            int ai = pre[0];
            int bi = pre[1];

            graph[bi].push_back(ai);
        }

        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }

        if (!valid) return {};
        reverse(res.begin(), res.end());
        return res;
    }

private:
    void dfs(int i) {
        visited[i] = 1;
        for (int j : graph[i]) {
            if (visited[j] == 1) {
                valid = false;
                return;
            } else if (visited[j] == 0) {
                dfs(j);
                if (!valid)
                    return;
            }
        }

        visited[i] = 2;
        res.push_back(i);
    }
    vector<vector<int>> graph; 
    vector<int> visited;
    vector<int> res;
    bool valid;
};
