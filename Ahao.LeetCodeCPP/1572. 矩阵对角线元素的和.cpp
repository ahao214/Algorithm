#include<vector>
using namespace std;

/*
1572. ����Խ���Ԫ�صĺ�

����һ�������ξ��� mat�����㷵�ؾ���Խ���Ԫ�صĺ͡�

���㷵���ھ������Խ����ϵ�Ԫ�غ͸��Խ������Ҳ������Խ�����Ԫ�صĺ͡�
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || i + j == n - 1) {
                    sum += mat[i][j];
                }
            }
        }
        return sum;
    }
};


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0, mid = n / 2;
        for (int i = 0; i < n; ++i) {
            sum += mat[i][i] + mat[i][n - 1 - i];
        }
        return sum - mat[mid][mid] * (n & 1);
    }
};

