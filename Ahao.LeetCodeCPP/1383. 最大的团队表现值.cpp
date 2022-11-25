#include<vector>
#include <queue>

using namespace std;


/*
1383. �����Ŷӱ���ֵ
��˾�б��Ϊ 1 �� n �� n ������ʦ�������������� speed �� efficiency ������ speed[i] �� efficiency[i] �ֱ����� i λ����ʦ���ٶȺ�Ч�ʡ����㷵������� k ������ʦ��ɵ�����Ŷӱ���ֵ �����ڴ𰸿��ܴܺ����㷵�ؽ���� 10^9 + 7 ȡ���Ľ����

�Ŷӱ���ֵ �Ķ���Ϊ��һ���Ŷ��С����й���ʦ�ٶȵĺ͡��������ǡ�Ч��ֵ�е���Сֵ����
*/
class Solution {
public:
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		//С����
		priority_queue<int, vector<int>, greater<int>> heap;

		vector<pair<int, int>> engs;
		for (int i = 0; i < n; i++)
			engs.push_back({ efficiency[i],speed[i] });
		sort(engs.begin(), engs.end());

		long long res = 0, sum = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			heap.push(engs[i].second);
			sum += engs[i].second;
			if (heap.size() > k)
			{
				sum -= heap.top();
				heap.pop();
			}
			res = max(res, sum * engs[i].first);
		}
		return res % 1000000007;
	}
};