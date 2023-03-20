#include<vector>
#include <queue>

using namespace std;



/*
658. 找到 K 个最接近的元素

给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b
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
