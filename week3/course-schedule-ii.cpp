//210. �γ̱� II
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

        //���������һ������0��ȵ㿪ʼ��������������Ŀγ�
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            lessons.push_back(x); //x����ѡ���ˣ�������xΪ����ǰ��Ŀγ�

            //�ڶ�������չx��Χ�ĵ㣬�����Ƿ����ѡ����
            for (int y : graph[x]) {
                inDegree[y]--;
                if (inDegree[y] == 0) { //���Ϊ0�ˣ���ʾ���е����޿γ̶������
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
