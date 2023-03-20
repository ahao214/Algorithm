#include<vector>
#include <queue>

using namespace std;



/*
658. �ҵ� K ����ӽ���Ԫ��

����һ�� ����� ������ arr ���������� k �� x �����������ҵ���� x������֮����С���� k ���������صĽ������Ҫ�ǰ������źõġ�

���� a ������ b ���ӽ� x ��Ҫ���㣺

|a - x| < |b - x| ����
|a - x| == |b - x| �� a < b
*/
class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		priority_queue<pair<int, int>> heap;
		for (auto v : arr)
		{
			heap.push({ abs(x - v),v });
			if (heap.size() > k)
				heap.pop();
		}
		vector<int> res;
		while (heap.size())
			res.push_back(heap.top().second), heap.pop();
		sort(res.begin(), res.end());
		return res;
	}
};
