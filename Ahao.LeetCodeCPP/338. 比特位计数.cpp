#include<vector>

using namespace std;


/*
338. ����λ����
����һ������ n ������ 0 <= i <= n �е�ÿ�� i
����������Ʊ�ʾ�� 1 �ĸ��� ������һ������Ϊ n + 1 ������ ans ��Ϊ�𰸡�
*/
class Solution {
public:
	vector<int> countBits(int n) {
		//���n��������p[n]=p[n-1]+1
		//���n��ż����p[n]=p[n/2]
		vector<int> res(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 1)
			{
				res[i] = res[i - 1] + 1;
			}
			else
			{
				res[i] = res[i / 2];
			}
		}
		return res;
	}
};
