#include<vector>

using namespace std;


/*
1854. �˿��������
����һ����ά�������� logs ������ÿ�� logs[i] = [birthi, deathi] ��ʾ�� i ���˵ĳ�����������ݡ�

��� x �� �˿� ����Ϊ��һ���ڼ���ŵ��˵���Ŀ���� i ���˱�������� x ���˿���Ҫ���㣺x �ڱ����� [birthi, deathi - 1] �ڡ�ע�⣬�˲�Ӧ��������������������˿��С�

���� �˿���� �� ���� ����ݡ�
*/
class Solution {
public:
	int maximumPopulation(vector<vector<int>>& logs) {
		//res��ʾ��� cnt��ʾ����
		int res, cnt = 0;
		for (int i = 1950; i <= 2050; i++)
		{
			int s = 0;
			for (auto& log : logs)
			{
				if (i >= log[0] && i < log[1])
					s++;
			}
			if (s > cnt)
				res = i, cnt = s;
		}
		return res;
	}
};
