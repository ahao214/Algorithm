#include<vector>
#include <algorithm>

using namespace std;

/*
2500. ɾ��ÿ���е����ֵ

����һ�� m x n ��С�ľ��� grid ����������������ɡ�

ִ������������ֱ�� grid ��Ϊ�վ���

��ÿһ��ɾ��ֵ����Ԫ�ء�������ڶ��������ֵ��ɾ�������κ�һ����
��ɾ��Ԫ���е����ֵ�����ӡ�
ע�� ÿִ��һ�β������������е����ݾͻ�� 1 ��

����ִ������������Ĵ𰸡�
*/


class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            sort(grid[i].begin(), grid[i].end());
        }
        int res = 0;
        for (int j = 0; j < n; j++) {
            int mx = 0;
            for (int i = 0; i < m; i++) {
                mx = max(mx, grid[i][j]);
            }
            res += mx;
        }
        return res;
    }
};
