#include<vector>
#include <algorithm>
#include<string>

using namespace std;


/*
1850. ��λ��������С����
����һ����ʾ���������ַ��� num ����һ������ k ��

���ĳ�������� num �и�λ���ֵ�һ�� ���� ������ ֵ���� num ������������Ϊ ���� �����ܴ��ںܶ�����������ֻ��Ҫ��ע ֵ��С ����Щ��

���磬num = "5489355142" ��
�� 1 ����С������ "5489355214"
�� 2 ����С������ "5489355241"
�� 3 ����С������ "5489355412"
�� 4 ����С������ "5489355421"
����Ҫ�õ��� k �� ��С���� ��Ҫ�� num ִ�е� ����λ���ֽ�������С���� ��

���������ǰ����ڵ� k ����С���������ɵġ�
*/
class Solution {
public:
	int getMinSwaps(string num, int k) {
		string b = num;
		while (k--) next_permutation(b.begin(), b.end());

		int n = num.size();
		vector<int> c(n);
		int cnt[10] = { 0 };
		for (int i = 0; i < n; i++)
		{
			int x = num[i] - '0';
			cnt[x]++;
			int y = cnt[x];
			for (int j = 0; j < n; j++)
			{
				if (b[j] - '0' == x && --y == 0)
				{
					c[i] = j;
					break;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
				if (c[i] > c[j])
					res++;
		}
		return res;
	}

};