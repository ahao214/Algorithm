#include<vector>

using namespace std;


/*
2319. �жϾ����Ƿ���һ�� X ����

���һ�������ξ����������� ȫ�� ���������֮Ϊһ�� X ���� ��

����Խ����ϵ�����Ԫ�ض� ���� 0
��������������Ԫ�ض��� 0
����һ����СΪ n x n �Ķ�ά�������� grid ����ʾһ�������ξ������ grid ��һ�� X ���� ������ true �����򣬷��� false ��
*/

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j || (i + j) == (n - 1)) {
                    if (grid[i][j] == 0) {
                        return false;
                    }
                }
                else if (grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};


