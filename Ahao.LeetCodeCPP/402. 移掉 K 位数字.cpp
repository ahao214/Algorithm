#include<vector>
#include <string>
#include <stack>

using namespace std;


/*
402. �Ƶ� K λ����
����һ�����ַ�����ʾ�ķǸ����� num ��һ������ k ���Ƴ�������е� k λ���֣�ʹ��ʣ�µ�������С���������ַ�����ʽ���������С�����֡�
*/
class Solution {
public:
	string removeKdigits(string num, int k) {
		stack<char> stk;
		for (auto x : num)
		{
			while (stk.size() && stk.top() > x && k)
			{
				stk.pop();
				k--;
			}
			stk.push(x);
		}
		//K��û������,��ջ����ʼɾ��
		while (k--) stk.pop();

		string res;
		while (stk.size())
		{
			res += stk.top();
			stk.pop();
		}
		reverse(res.begin(), res.end());
		int i = 0;
		//ȥ��ǰ���0
		while (i < res.size() && res[i] == '0') i++;
		if (i == res.size()) return "0";
		return res.substr(i);
	}
};
