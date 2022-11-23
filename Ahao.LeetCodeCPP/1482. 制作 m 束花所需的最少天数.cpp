#include<vector>
#include <algorithm>

using namespace std;


/*
1482. ���� m �����������������
����һ���������� bloomDay���Լ��������� m �� k ��

����Ҫ���� m ��������������ʱ����Ҫʹ�û�԰�� ���ڵ� k �仨 ��

��԰���� n �仨���� i �仨���� bloomDay[i] ʱʢ����ǡ�� �������� һ�� ���С�

���㷵�شӻ�԰��ժ m ������Ҫ�ȴ������ٵ��������������ժ�� m �����򷵻� -1 ��
*/
class Solution {
public:
	int get(int l, int r, int k)
	{
		return (r - l + 1) / k;
	}
	int minDays(vector<int>& bloomDay, int m, int k) {
		vector<pair<int, int>> q;

		for (int i = 0; i < bloomDay.size(); i++)
			q.push_back({ bloomDay[i],i + 1 });

		int n = bloomDay.size();
		vector<int> l(n + 2), r(n + 2);
		sort(q.begin(), q.end());
		int sum = 0;
		for (auto x : q)
		{
			int i = x.second;
			if (l[i - 1] && r[i + 1]) {
				sum = sum - get(l[i - 1], i - 1, k) - get(i + 1, r[i + 1], k) + get(l[i - 1], r[i + 1], k);
				r[l[i - 1]] = r[i + 1];
				l[r[i + 1]] = l[i - 1];
			}
			else if (l[i - 1]) {
				sum = sum - get(l[i - 1], i - 1, k) + get(l[i - 1], i, k);
				r[l[i - 1]] = i;
				l[i] = l[i - 1];
			}
			else if (r[i + 1]) {
				sum = sum - get(i + 1, r[i + 1], k) + get(i, r[i + 1], k);
				r[i] = r[i + 1];
				l[r[i + 1]] = i;
			}
			else {
				sum = sum + get(i, i, k);
				r[i] = l[i] = i;
			}
			if (sum >= m) return x.first;
		}
		return -1;
	}
};
