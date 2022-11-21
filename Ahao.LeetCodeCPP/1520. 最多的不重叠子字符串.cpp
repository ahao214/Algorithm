#include<vector>
#include <string>

using namespace std;


/*
1520. ���Ĳ��ص����ַ���
����һ��ֻ����Сд��ĸ���ַ��� s ������Ҫ�ҵ� s �������Ŀ�ķǿ����ַ�������������������

��Щ�ַ���֮�以���ص���Ҳ����˵���������������ַ��� s[i..j] �� s[k..l] ��Ҫô j < k Ҫô i > l ��
���һ�����ַ��������ַ� char ����ô s ������ char �ַ���Ӧ����������ַ����С�
�����ҵ���������������������ַ�����Ŀ������ж���ⷨ����ͬ�����ַ�����Ŀ���뷵����Щ���ַ����ܳ�����С��һ���⡣����֤����С�ܳ��Ƚ���Ψһ�ġ�

��ע�⣬������� ���� ˳�򷵻����Ž�����ַ�����
*/
class Solution {
public:
	vector<string> maxNumOfSubstrings(string s) {
		int n = s.size();
		s = ' ' + s;
		vector<vector<int>> sum(26, vector<int>(n + 1));
		vector<vector<int>> range(26, { INT_MAX,INT_MIN });
		for (int i = 1; i <= n; i++)
		{
			int t = s[i] - 'a';
			for (int j = 0; j < 26; j++)
			{
				sum[j][i] = sum[j][i - 1];
				if (j == t) sum[j][i]++;
			}
			range[t][0] = min(range[t][0], i);
			range[t][1] = max(range[t][1], i);
		}

		while (true)
		{
			bool flag = true;
			for (int i = 0; i < 26; i++)
			{
				auto cur = range[i];
				if (cur[0] > cur[1]) continue;
				for (int j = 0; j < 26; j++)
				{
					if (sum[j][cur[1]] - sum[j][cur[0] - 1])
					{
						cur[0] = min(cur[0], range[j][0]);
						cur[1] = max(cur[1], range[j][1]);
					}
				}
				if (cur != range[i])
				{
					range[i] = cur;
					flag = false;
				}
			}
			if (flag) break;
		}

		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (i != j && range[j][0] != INT_MAX && range[i][0] <= range[j][0] && range[i][1] >= range[j][1])
				{
					range[i] = { INT_MAX,INT_MIN };
				}
			}
		}
		vector<string> res;
		for (int i = 0; i < 26; i++)
		{
			int l = range[i][0], r = range[i][1];
			if (l <= r)
				res.push_back(s.substr(l, r - l + 1));
		}
		return res;
	}
};