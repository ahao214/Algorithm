#include<vector>

using namespace std;



/*
1732. �ҵ���ߺ���
��һ�����г��ִ������һ����·���У�����·���ܹ��� n + 1 ����ͬ���εĵ���ɡ����г��ִӺ���Ϊ 0 �ĵ� 0 ��ʼ���С�

����һ������Ϊ n ���������� gain ������ gain[i] �ǵ� i �͵� i + 1 �� �����θ߶Ȳ0 <= i < n�������㷵�� ��ߵ�ĺ��� ��
*/
class Solution {
public:
	int largestAltitude(vector<int>& gain) {
		int res = 0, h = 0;
		for (auto g : gain)
		{
			h += g;
			res = max(res, h);
		}
		return res;
	}
};