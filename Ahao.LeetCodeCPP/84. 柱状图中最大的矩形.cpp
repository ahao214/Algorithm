#include<vector>
#include<stack>


using namespace std;


class Solution {
	/*
	84. ��״ͼ�����ľ���
	���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��

	���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
	*/
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
