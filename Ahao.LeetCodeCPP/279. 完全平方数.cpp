#include<vector>
#include <queue>

using namespace std;


/*
279. ��ȫƽ����
����һ������ n ������ ��Ϊ n ����ȫƽ�������������� ��

��ȫƽ���� ��һ����������ֵ������һ��������ƽ�������仰˵����ֵ����һ�������Գ˵Ļ���
���磬1��4��9 �� 16 ������ȫƽ�������� 3 �� 11 ���ǡ�
*/
class Solution {
public:
	int numSquares(int n) {
		queue<int> q;
		vector<int>dist(n + 1, INT_MAX);
		q.push(0);
		dist[0] = 0;
		while (q.size()) {
			int t = q.front();
			q.pop();
			if (t == n) return dist[t];
			for (int i = 1; i * i + t <= n; i++) {
				int j = t + i * i;
				if (dist[j] > dist[t] + 1) {
					dist[j] = dist[t] + 1;
					q.push(j);
				}
			}
		}
		return 0;
	}
};