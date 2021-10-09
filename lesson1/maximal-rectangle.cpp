#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ret = 0;
        int rows = matrix.size();

        if (rows == 0) return 0;

        int cols = matrix[0].size();
        vector<int> heights(cols, 0);

        for (int i = 0; i < rows; i++) {      
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j] += 1;
            }

            ret = max(ret, largestRectangleArea(heights));
        }

        return ret;
    }

private:
    //84Ìâ
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        stack<Rect> s;

        heights.push_back(0);
        for (int h : heights) {
            int width = 0;

            while (!s.empty() && s.top().height >= h) {
                width += s.top().width;
                ret = max(ret, s.top().height * width);
                s.pop();
            }

            s.push({h, width + 1});
        }

        return ret;
    }

    struct Rect {
        int height;
        int width;
    };
};

void test1() {
	Solution solu;
	char param[4][5] = {{'1','0','1','0','0'},
						{'1','0','1','1','1'},
						{'1','1','1','1','1'},
						{'1','0','0','1','0'}};
	vector<vector<char>> matrix(4, vector<char>(5, '0'));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			matrix[i][j] = param[i][j];
		}
	} 
	
	int ret = solu.maximalRectangle(matrix);
	cout << ret << endl;
}

int main(void) {
	test1();
	
	return 0;
}