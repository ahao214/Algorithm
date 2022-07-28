#include<vector>
#include<queue>

using namespace std;


/*
offer 40 最小的K个数
*/
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> ans;
		if (input.empty() || k < 1) return ans;
		int start = 0;
		int end = input.size() - 1;
		int index = Partition(input, start, end);
		while (index != k - 1)
		{
			if (index > k - 1)
			{
				end = index - 1;
				index = Partition(input, start, end);
			}
			else
			{
				start = index + 1;
				index = Partition(input, start, end);
			}
		}
		for (int i = 0; i < k && i < input.size(); ++i)
		{
			ans.push_back(input[i]);
		}
		return ans;
	}

	int Partition(vector<int>& arr, int low, int high)
	{
		int pivot = arr[low];
		while (low < high)
		{
			while (low < high && arr[high] >= pivot)
				high--;
			arr[low] = arr[high];
			while (low < high && arr[low] <= pivot)
				low++;
			arr[high] = arr[low];
		}
		arr[low] = pivot;
		return low;
	}

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		vector<int> ans;
		if (input.empty() || k < 1) return ans;
		priority_queue<int> pq;
		for (int i = 0; i < input.size(); ++i)
		{
			if (pq.size() < k)
			{
				pq.push(input[i]);
			}
			else if (input[i] < pq.top())
			{
				pq.pop();
				pq.push(input[i]);
			}
		}
		while (!pq.empty())
		{
			ans.push_back(pq.top());
			pq.pop();
		}
		return ans;
	}
};