#include<vector>

using namespace std;


/*
1872. ʯ����Ϸ VIII
Alice �� Bob ��һ����Ϸ���������������� Alice ���� ��

�ܹ��� n ��ʯ���ų�һ�С��ֵ�ĳ����ҵĻغ�ʱ�����ʯ�ӵ���Ŀ ���� 1 ������ִ�����²�����

ѡ��һ������ x > 1 ������ �Ƴ� ����ߵ� x ��ʯ�ӡ�
�� �Ƴ� ��ʯ�Ӽ�ֵ֮ �� �ۼӵ�����ҵķ����С�
��һ�� �µ�ʯ�� ��������ߣ�����ʯ�ӵ�ֵΪ���Ƴ�ʯ��ֵ֮�͡�
��ֻʣ�� һ�� ʯ��ʱ����Ϸ������

Alice �� Bob �� ����֮�� Ϊ (Alice �ķ��� - Bob �ķ���) �� Alice ��Ŀ���� ��� �����Bob ��Ŀ���� ��С�� �����

����һ������Ϊ n ���������� stones ������ stones[i] �� ������� �� i ��ʯ�ӵļ�ֵ�����㷵����˫�������� ���� ���Ե�����£�Alice �� Bob �� ����֮�� ��
*/
class Solution {
public:
	int stoneGameVIII(vector<int>& stones) {
		int n = stones.size();
		reverse(stones.begin(), stones.end());
		vector<int> f(n + 1), s(n + 1);
		for (int i = 1; i <= n; i++)
			s[i] = s[i - 1] + stones[i - 1];
		int v = s[n] - s[0] + f[1];
		for (int i = 2; i <= n; i++)
		{
			f[i] = v;
			v = max(v, s[n] - s[i - 1] - f[i]);
		}
		return f[n];
	}

};