#include<vector>

using namespace std;





/*
	1861. ��ת����
	����һ�� m x n ���ַ����� box ������ʾһ�����ӵĲ���ͼ�����ӵ�ÿһ�����ӿ���Ϊ��

	'#' ��ʾʯͷ
	'*' ��ʾ�̶����ϰ���
	'.' ��ʾ��λ��
	������ӱ� ˳ʱ����ת 90 �� ����������ԭ�򣬲���ʯͷ��λ�ûᷢ���ı䡣ÿ��ʯͷ�ᴹֱ���䣬ֱ���������ϰ����һ��ʯͷ�������ӵĵײ������� ���� Ӱ���ϰ����λ�ã�ͬʱ������ת����������� ��Ҳ����˵ʯͷ��ˮƽλ�ò��ᷢ���ı䡣

	��Ŀ��֤��ʼʱ box �е�ʯͷҪô��һ���ϰ����ϣ�Ҫô����һ��ʯͷ�ϣ�Ҫô�����ӵĵײ���

	���㷵��һ�� n x m�ľ��󣬱�ʾ����������ת�������ڵĽ����
	*/
class Solution {
public:
	vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
		int n = box.size(), m = box[0].size();
		vector<vector<char>> res(m, vector<char>(n));
		//��ת90��
		for (int i = n - 1, k = 0; i >= 0; i--, k++)
		{
			for (int j = 0; j < m; j++)
			{
				res[j][k] = box[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = m - 1, k = m; j >= 0; j--)
			{
				if (res[j][i] == '*')
					k = j;
				else if (res[j][i] == '#')
				{
					res[j][i] = '.';
					res[--k][i] = '#';
				}
			}
		}
		return res;
	}

};
