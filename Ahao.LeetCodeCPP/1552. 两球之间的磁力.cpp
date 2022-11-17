#include<vector>
#include <algorithm>

using namespace std;


/*
1552. ����֮��Ĵ���
�ڴ���Ϊ C-137 �ĵ����ϣ�Rick �����������������������·��������������֮����γ�������ʽ�Ĵ�����Rick �� n ���յ����ӣ��� i �����ӵ�λ���� position[i] ��Morty ��� m ����ŵ���Щ�����ʹ����������� ��С���� ���

��֪����������ֱ�λ�� x �� y ����ô����֮��Ĵ���Ϊ |x - y| ��

����һ���������� position ��һ������ m �����㷵����󻯵���С������
*/
class Solution {
public:
	int maxDistance(vector<int>& position, int m) {
		sort(position.begin(), position.end());
		int left = 0, right = 1e9;
		while (left < right)
		{
			int mid = left + right + 1 >> 1;
			int cnt = 1, last = position[0];
			for (int i = 1; i < position.size(); i++)
			{
				if (position[i] - last >= mid)
				{
					last = position[i];
					cnt++;
				}
			}
			if (cnt >= m) left = mid;
			else right = mid - 1;
		}
		return right;
	}
};