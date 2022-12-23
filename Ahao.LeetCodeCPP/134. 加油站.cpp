#include<vector>

using namespace std;


/*
134. 加油站
在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组gas和cost ，如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 如果存在解，则保证它是唯一的。
*/
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		for (int i = 0, j; i < n; i += j + 1)
		{
			int gas_left = 0;
			for (j = 0; j < n; j++)
			{
				int k = (i + j) % n;
				gas_left += gas[k] - cost[k];
				if (gas_left < 0)
					break;
			}
			if (j >= n) return i;
		}
		return -1;
	}
};