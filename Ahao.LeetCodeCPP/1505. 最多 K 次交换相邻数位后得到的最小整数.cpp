#include<vector>
#include <string>
#include <queue>

using namespace std;


/*
1505. ��� K �ν���������λ��õ�����С����
����һ���ַ��� num ��һ������ k �����У�num ��ʾһ���ܴ���������ַ����е�ÿ���ַ����ζ�Ӧ�����ϵĸ��� ��λ ��

����Խ����������������λ������ ��� k �Ρ�

���㷵�����ܵõ�����С�����������ַ�����ʽ���ء�
*/
class Solution {
public:
	/*
	�õ�һλ������С���ڶ�λ��С������λ�δ�С	����������С�����־����ŵ���ǰ�棬����ͬ�����ֵ�ʱ�򣬾�����߽Ͻ������֣��Ƚ��н����������Ĵ���ҪС�ڵ���K

	��¼����0��9���ֵ�����λ��

	���磺
	1��ʣ��������Ƿ���0���Ҿ�����������0
	2����0�ŵ���һλ�������������ܴ���K
	*/

	int n;
	vector<int> tr;
	int lowbit(int x)
	{
		return x & -x;
	}

	void add(int x, int v)
	{
		for (int i = x; i <= n; i += lowbit(i))
			tr[i] += v;
	}

	int getSum(int x)
	{
		int res = 0;
		for (int i = x; i; i -= lowbit(i))
			res += tr[i];
		return res;
	}

	string minInteger(string num, int k) {
		n = num.size();
		tr.resize(n + 1);
		num = ' ' + num;
		queue<int> q[10];
		for (int i = 1; i <= n; i++)
			q[num[i] - '0'].push(i);
		string res;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (q[j].size())
				{
					int t = q[j].front();
					int pos = t + getSum(t);
					if (pos - i <= k)
					{
						k -= pos - i;
						res += to_string(j);
						q[j].pop();
						add(1, 1), add(t, -1);
						break;
					}
				}
			}
		}
		return res;
	}
};
