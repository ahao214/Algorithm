#include<vector>

using namespace std;


/*
1893. ����Ƿ�����������������������
����һ����ά�������� ranges ���������� left �� right ��ÿ�� ranges[i] = [starti, endi] ��ʾһ���� starti �� endi �� ������ ��

��������� [left, right] ��ÿ���������� ranges �� ����һ�� ���串�ǣ���ô���㷵�� true �����򷵻� false ��

��֪���� ranges[i] = [starti, endi] ��������� x ���� starti <= x <= endi ����ô���ǳ�����x �������ˡ�
*/
class Solution {
public:
	bool isCovered(vector<vector<int>>& ranges, int left, int right) {
		for (int i = left; i <= right; i++)
		{
			bool flag = false;
			for (auto& r : ranges)
			{
				if (r[0] <= i && i <= r[1])
				{
					flag = true;
					break;
				}
			}
			if (!flag) return false;
		}
		return true;
	}
};