#include<vector>
#include<stack>


using namespace std;


/*
84. ��״ͼ�����ľ���
���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��

���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
*/
class Solution {
public:
	/*
	Times:O(n^2)
	Space:O(1)
	*/
	int largestRectangleArea(vector<int>& heights) {
		//�洢�����±�
		stack<int> stk;
		int ans = 0;
		heights.push_back(-1);
		for (int i = 0; i < heights.size(); i++)
		{
			//��ջ��Ϊ�գ����ҵ�ǰ�����Ԫ��С��ջ��Ԫ��
			while (!stk.empty() && heights[i] < heights[stk.top()])
			{
				int idx = stk.top();
				stk.pop();
				int left = stk.empty() ? -1 : stk.top();
				ans = max(ans, (i - left - 1) * heights[idx]);
			}
			stk.push(i);
		}

		return ans;
	}
};




class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		stack<int> stk;
		vector<int>nextSmaller(n, n);
		for (int i = 0; i < heights.size(); i++)
		{
			while (!stk.empty() && heights[stk.top()] > heights[i])
			{
				nextSmaller[stk.top()] = i;
				stk.pop();
			}
			stk.push(i);
		}

		while (!stk.empty())
			stk.pop();
		vector<int>prevSmaller(n, -1);
		for (int i = 0; i < heights.size(); i++)
		{
			while (!stk.empty() && heights[stk.top()] > heights[i])
			{
				stk.pop();
			}
			if (!stk.empty())
			{
				prevSmaller[i] = stk.top();
			}
			stk.push(i);
		}

		int res = 0;
		for (int i = 0; i < n; i++)
		{
			int area = heights[i] * (nextSmaller[i] - prevSmaller[i] - 1);
			res = max(res, area);
		}
		return res;
	}
};



/*
84. ��״ͼ�����ľ���
���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��

���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
*/
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size(), ans = 0;
		heights.push_back(-1);
		stack<int> stk;
		for (int i = 0; i <= n; i++)
		{
			while (!stk.empty() && heights[i] < heights[stk.top()])
			{
				int cur = stk.top();
				stk.pop();
				if (stk.empty())
				{
					ans = max(ans, heights[cur] * i);
				}
				else
				{
					ans = max(ans, heights[cur] * (i - stk.top() - 1));
				}
			}
			stk.push(i);
		}
		return ans;
	}
};