#include<vector>
#include <algorithm>
#include <queue>

using namespace std;



/*
857. ��Ӷ K �����˵���ͳɱ�
�� n �����ˡ� ������������ quality �� wage �����У�quality[i]
��ʾ�� i �����˵Ĺ����������������������Ϊ wage[i] ��

�����������Ӷ k ���������һ�������顣�ڹ�Ӷ һ�� k ������ʱ��
���Ǳ��밴����������������֧�����ʣ�

�Թ������е�ÿ�����ˣ�Ӧ�����乤��������ͬ���������˵Ĺ��������ı�����
֧�����ʡ�
�������е�ÿ����������Ӧ���õ����ǵ�����������ʡ�
�������� k ����������������������ĸ���Ⱥ���������С��� ��
��ʵ�ʴ𰸵� 10-5 ���ڵĴ𰸽������ܡ���
*/
class Solution {
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
		int n = quality.size();
		vector<pair<double, int>> workers;
		for (int i = 0; i < n; i++)
			workers.push_back({ wage[i] * 1.0 / quality[i], quality[i] });
		sort(workers.begin(), workers.end());

		priority_queue<int> heap;
		double res = 1e9;
		int sum = 0;
		for (auto worker : workers)
		{
			heap.push(worker.second);
			sum += worker.second;
			if (heap.size() > k)
			{
				sum -= heap.top();
				heap.pop();
			}
			if (heap.size() == k) res = min(res, sum * worker.first);
		}
		return res;
	}
};