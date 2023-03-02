#include<vector>

using namespace std;


/*
835. ͼ���ص�

��������ͼ�� img1 �� img2 ������ͼ��Ĵ�С���� n x n ���ô�С��ͬ�Ķ����������ξ����ʾ�������ƾ���������� 0 ������ 1 ��ɡ�

ת�� ����һ��ͼ�񣬽����е� 1 �����ң��ϣ����»����κ������ĵ�λ��Ȼ�����������һ��ͼ������档��ת���� �ص� ��ָ����ͼ�� �� ���� 1 ��λ�õ���Ŀ��

��ע�⣬ת�� ������ ���κη�����ת��Խ������߽�� 1 �����������

�����ܵ��ص������Ƕ��٣�



ʾ�� 1��


���룺img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
�����3
���ͣ��� img1 �����ƶ� 1 ����λ���������ƶ� 1 ����λ��

����ͼ�񶼾��� 1 ��λ�õ���Ŀ�� 3���ú�ɫ��ʶ����

ʾ�� 2��

���룺img1 = [[1]], img2 = [[1]]
�����1
ʾ�� 3��

���룺img1 = [[0]], img2 = [[0]]
�����0


��ʾ��

n == img1.length == img1[i].length
n == img2.length == img2[i].length
1 <= n <= 30
img1[i][j] Ϊ 0 �� 1
img2[i][j] Ϊ 0 �� 1
*/
class Solution {
public:
	int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
		int n = img1.size();
		int res = 0;
		for (int i = -n; i < n; i++)
		{
			for (int j = -n; j < n; j++)
			{
				int cnt = 0;
				for (int x = max(0, -i); x < min(n, n - i); x++)
				{
					for (int y = max(0, -j); y < min(n, n - j); y++)
						if (img1[x][y] && img2[i + x][j + y])
							cnt++;
				}
				res = max(res, cnt);
			}
		}
		return res;
	}
};
