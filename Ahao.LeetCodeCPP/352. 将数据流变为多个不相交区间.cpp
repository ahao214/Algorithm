#include<vector>
#include<map>


using namespace std;


/*
352. 将数据流变为多个不相交区间
 给你一个由非负整数 a1, a2, ..., an 组成的数据流输入，请你将到目前为止看到的数字总结为不相交的区间列表。

实现 SummaryRanges 类：

SummaryRanges() 使用一个空数据流初始化对象。
void addNum(int val) 向数据流中加入整数 val 。
int[][] getIntervals() 以不相交区间 [starti, endi] 的列表形式返回对数据流中整数的总结。
*/
class Solution {
public:
	map<int, int> L, R;
	void SummaryRanges() {

	}

	void addNum(int val) {
		if (L.size())
		{
			auto it = L.lower_bound(val);
			if (it != L.end() && it->second <= val) return;
		}

		int left = L.count(val - 1), right = R.count(val + 1);
		if (left && right)
		{
			R[L[val - 1]] = R[val + 1];
			L[R[val + 1]] = L[val - 1];
			L.erase(val - 1), R.erase(val + 1);
		}
		else if (left)
		{
			R[L[val - 1]] = val;
			L[val] = L[val - 1];
			L.erase(val - 1);
		}
		else if (right)
		{
			L[R[val + 1]] = val;
			R[val] = R[val + 1];
			R.erase(val + 1);
		}
		else
		{
			R[val] = L[val] = val;
		}
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> res;
		for (auto item : R) res.push_back({ item.first,item.second });
		return res;
	}
};