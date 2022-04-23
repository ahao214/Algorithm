using namespace std;
#include <string>
#include<stack>


class Solution {
	/*
	32. ���Ч����
	����һ��ֻ���� '(' �� ')' ���ַ�����
	�ҳ����Ч����ʽ��ȷ�������������Ӵ��ĳ��ȡ�
	*/
public:
	int longestValidParentheses(string s) {
		stack<int> stk;
		int ans = 0;
		for (int i = 0, start = -1; i < s.length(); i++) {
			if (s[i] == '(') {
				stk.push(i);
			}
			else {
				if (!stk.empty()) {
					stk.pop();
					if (!stk.empty()) {
						ans = max(ans, i - stk.top());
					}
					else {
						ans = max(ans, i - start);
					}
				}
				else {
					start = i;
				}
			}
		}
		return ans;
	}
};
