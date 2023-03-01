#include<vector>

using namespace std;

/*
2373. �����еľֲ����ֵ

����һ����СΪ n x n ���������� grid ��

����һ����СΪ (n - 2) x (n - 2) ����������  maxLocal �������㣺

maxLocal[i][j] ���� grid ���� i + 1 �к� j + 1 ��Ϊ���ĵ� 3 x 3 �����е� ���ֵ ��
���仰˵������ϣ���ҳ� grid ��ÿ�� 3 x 3 �����е����ֵ��

�������ɵľ���
*/


class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        res[i][j] = max(res[i][j], grid[x][y]);
                    }
                }
            }
        }
        return res;
    }
};
