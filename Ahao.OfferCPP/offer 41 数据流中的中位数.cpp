#include<vector>
#include<queue>

using namespace std;


/*
offer 41 数据流中的中位数
*/
class Solution {
public:
	void Insert(int num) {
		if (min.empty())
			min.push(num);
		else if (num < min.top())
		{
			if (min.size() == max.size())
			{
				max.push(num);
				min.push(max.top());
				max.pop();
			}
			else
			{
				max.push(num);
			}
		}
		else
		{
			if (min.size() == max.size())
			{
				min.push(num);
			}
			else
			{
				min.push(num);
				max.push(min.top());
				min.pop();
			}
		}
	}

	double GetMedian() {
		if (max.size() == min.size())
			return (max.top() + min.top()) / 2.0;
		else
			return min.top() / 1.0;
	}

private:
	priority_queue<int> max;	//大顶堆
	priority_queue<int, vector<int>, greater<int>> min;	//小顶堆
};