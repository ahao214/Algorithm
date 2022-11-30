#include<vector>
#include <string>
#include <stack>

using namespace std;



/*
224. ����������
����һ���ַ������ʽ s ������ʵ��һ�����������������㲢��������ֵ��

ע��:������ʹ���κν��ַ�����Ϊ��ѧ���ʽ��������ú��������� eval() ��
*/
class Solution {
public:
	void calc(stack<char>& op, stack<int>& num)
	{
		int y = num.top();
		num.pop();
		int x = num.top();
		num.pop();
		if (op.top() == '+') num.push(x + y);
		else num.push(x - y);
		op.pop();
	}

	int calculate(string s) {
		stack<char> op;
		stack<int> num;
		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			if (c == ' ') continue;
			if (c == '(' || c == '+' || c == '-') op.push(c);
			else if (c == ')')
			{
				op.pop();
				if (op.size() && op.top() != '(')
				{
					calc(op, num);
				}
			}
			else
			{
				int j = i;
				while (j < s.size() && isdigit(s[j])) j++;
				num.push(atoi(s.substr(i, j - i).c_str()));
				i = j - 1;
				if (op.size() && op.top() != '(')
				{
					calc(op, num);
				}
			}
		}
		return num.top();
	}
};
