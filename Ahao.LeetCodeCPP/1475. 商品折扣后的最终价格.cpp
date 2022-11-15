#include<vector>
#include <stack>

using namespace std;



/*
1475. ��Ʒ�ۿۺ�����ռ۸�
����һ������ prices ������ prices[i] ���̵���� i ����Ʒ�ļ۸�

�̵������ڽ��д�����������Ҫ��� i ����Ʒ����ô����Եõ��� prices[j] ��ȵ��ۿۣ����� j ������ j > i �� prices[j] <= prices[i] �� ��С�±� �����û������������ j ���㽫û���κ��ۿۡ�

���㷵��һ�����飬�����е� i ��Ԫ�����ۿۺ��㹺����Ʒ i ������Ҫ֧���ļ۸�
*/
class Solution {
public:
	//����ջ
	vector<int> finalPrices(vector<int>& prices) {
		vector<int> res;
		stack<int> stk;
		for (int i = prices.size() - 1; i >= 0; i--)
		{
			int t = prices[i];
			while (stk.size() && stk.top() > t) stk.pop();
			if (stk.size()) res.push_back(t - stk.top());
			else res.push_back(t);
			while (stk.size() && stk.top() == t) stk.pop();
			stk.push(t);
		}

		return vector<int>(res.rbegin(), res.rend());
	}
};