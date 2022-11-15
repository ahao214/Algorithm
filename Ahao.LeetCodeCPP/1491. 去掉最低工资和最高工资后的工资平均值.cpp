#include<vector>

using namespace std;


/*
1491. 去掉最低工资和最高工资后的工资平均值
给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。

请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。
*/
class Solution {
public:
	double average(vector<int>& salary) {
		double sum = 0;
		int maxv = INT_MIN, minv = INT_MAX;
		for (auto x : salary)
		{
			sum += x;
			maxv = max(maxv, x);
			minv = min(minv, x);
		}
		return (sum - maxv - minv) / (salary.size() - 2);
	}
};

