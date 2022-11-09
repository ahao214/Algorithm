#include<vector>

using namespace std;


/*
1701. 平均等待时间
有一个餐厅，只有一位厨师。你有一个顾客数组 customers ，其中 customers[i] = [arrivali, timei] ：

arrivali 是第 i 位顾客到达的时间，到达时间按 非递减 顺序排列。
timei 是给第 i 位顾客做菜需要的时间。
当一位顾客到达时，他将他的订单给厨师，厨师一旦空闲的时候就开始做这位顾客的菜。每位顾客会一直等待到厨师完成他的订单。厨师同时只能做一个人的订单。厨师会严格按照 订单给他的顺序 做菜。

请你返回所有顾客需要等待的 平均 时间。与标准答案误差在 10-5 范围以内，都视为正确结果。
*/
class Solution {
public:
	double averageWaitingTime(vector<vector<int>>& customers) {
		double sum = 0, t = 0;
		for (auto c : customers)
		{
			//arrT到达时间 timei做菜时间
			int arrT = c[0], timei = c[1];
			/*
			厨师做完上一个客人所用的总时间>=下一位客户的到达时间
			厨师可以直接开始服务客户
			*/
			if (arrT >= t)
			{
				sum += timei;
				t = arrT + timei;
			}
			else
			{
				sum += t - arrT + timei;
				t += timei;
			}
		}
		return sum / customers.size();
	}
};