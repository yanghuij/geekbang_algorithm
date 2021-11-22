//279. ��ȫƽ����
//https://leetcode-cn.com/problems/perfect-squares/
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 0; i <= n; i++) {
            if (i * i <= n) {
                squares.push_back(i * i);
            }
        }
        int m = squares.size() - 1;

        //��ȫƽ����������Ʒ�����Ϊn����ֵΪ1���ñ���DP
        //f[i,j]��ʾ��ǰi����ȫƽ������ѡ����Ϊj����ȫƽ��������ȫƽ���������ٸ�����
        //f[i,j] = min( f[i - 1,j],            f[i - 1,j - squares[i]] + 1 )            
        //           ��ѡ��i����ȫƽ����       j>=squares[i]��ѡ��i����ȫƽ����
        //��ֵ f[0,0] = 0������Ϊ������
        //Ŀ�� f[i,n]

        vector<int> f(n + 1, 1e9);
        f[0] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = squares[i]; j <= n; j++) {
                f[j] = min(f[j], f[j - squares[i]] + 1);
            }
        }

        return f[n];
    }
};