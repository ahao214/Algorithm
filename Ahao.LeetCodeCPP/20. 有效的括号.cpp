using namespace std;
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>

class Solution {
public:
	bool isValid(string s) {
		unordered_map<char, char> pairs = {
			{'(',')'},{'[',']'},{'{','}'}
		};
		stack<char> stk;
		for (int i = 0; i < s.length(); i++) {
			if (pairs.find(s[i]) != pairs.end()) {
				stk.push(pairs[s[i]]);
			}
			else {
				if (stk.empty() || stk.top() != s[i]) {
					return false;
				}
				stk.pop();
			}
		}
		return stk.empty();
	}
};


/*
20. ��Ч������
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
*/
class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for (auto c : s)
		{
			if (c == ')')
			{
				if (stk.empty() || stk.top() != '(') return false;
				stk.pop();
			}
			else if (c == ']')
			{
				if (stk.empty() || stk.top() != '[') return false;
				stk.pop();
			}
			else if (c == '}')
			{
				if (stk.empty() || stk.top() != '{') return false;
				stk.pop();
			}
			else
				stk.push(c);
		}
		return stk.empty();
	}
};
