#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


/*
1553. �Ե� N �����ӵ���������
�������ܹ��� n �����ӣ������ÿһ��ѡ�����·�ʽ֮һ����Щ���ӣ�

�Ե�һ�����ӡ�
���ʣ�������� n �ܱ� 2 ��������ô����ԳԵ� n/2 �����ӡ�
���ʣ�������� n �ܱ� 3 ��������ô����ԳԵ� 2*(n/3) �����ӡ�
ÿ����ֻ�ܴ����� 3 �ַ�����ѡ��һ�ַ�����

���㷵�سԵ����� n �����ӵ�����������
*/
class Solution {
public:
	unordered_map<int, int> d;
	queue<int> q;

	void extend(int dist, int x)
	{
		if (d.count(x)) return;
		d[x] = dist + 1;
		q.push(x);
	}

	int minDays(int n) {
		q.push(n);
		d[n] = 1;
		if (n == 1) return 1;
		while (q.size())
		{
			auto t = q.front();
			if (t == 1) return d[t];
			q.pop();
			extend(d[t], t - 1);
			if (t % 2 == 0) extend(d[t], t / 2);
			if (t % 3 == 0) extend(d[t], t / 3);
		}
		return -1;
	}
};