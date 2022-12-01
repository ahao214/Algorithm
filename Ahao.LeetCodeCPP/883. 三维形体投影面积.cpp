using namespace std;
#include<vector>

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int xyArea = 0, yzArea = 0, zxArea = 0;
        for (int i = 0; i < n; i++) {
            int yzHeight = 0, zxHeight = 0;
            for (int j = 0; j < n; j++) {
                xyArea += grid[i][j] > 0 ? 1 : 0;
                yzHeight = max(yzHeight, grid[i][j]);
                zxHeight = max(zxHeight, grid[j][i]);
            }
            yzArea += yzHeight;
            zxArea += zxHeight;
        }
        return xyArea + yzArea + zxArea;
    }
};




/*
883. ��ά����ͶӰ���
�� n x n ������ grid �У����Ƿ�����һЩ�� x��y��z �������� 1 x 1 x 1 �����塣

ÿ��ֵ v = grid[i][j] ��ʾ v ������������ڵ�Ԫ�� (i, j) �ϡ�

���ڣ����ǲ鿴��Щ�������� xy ��yz �� zx ƽ���ϵ�ͶӰ��

ͶӰ ����Ӱ�ӣ��� ��ά ����ӳ�䵽һ�� ��ά ƽ���ϡ��Ӷ�����ǰ��Ͳ��濴������ʱ�����ǻῴ����Ӱ�ӡ���

���� ��������ͶӰ������� ��
*/
class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		int res = 0;
		if (grid.empty() || grid[0].empty()) return res;
		int n = grid.size(), m = grid[0].size();
		//�������¿������
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				res += !!grid[i][j];
			}
		}

		//��ǰ���󿴵����
		for (int i = 0; i < n; i++)
		{
			int h = 0;
			for (int j = 0; j < m; j++) h = max(h, grid[i][j]);
			res += h;
		}

		//�������󿴵����
		for (int j = 0; j < m; j++)
		{
			int h = 0;
			for (int i = 0; i < n; i++) h = max(h, grid[i][j]);
			res += h;
		}
		return res;
	}
};
