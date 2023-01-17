#include<vector>
#include <string>

using namespace std;


/*
1249. �Ƴ���Ч������
����һ���� '('��')' ��Сд��ĸ��ɵ��ַ��� s��

����Ҫ���ַ�����ɾ��������Ŀ�� '(' ���� ')' ������ɾ������λ�õ�����)��ʹ��ʣ�µġ������ַ�������Ч��

�뷵������һ���Ϸ��ַ�����

��Ч�������ַ�����Ӧ���������� ����һ�� Ҫ��

���ַ�����ֻ����Сд��ĸ���ַ���
���Ա�д�� AB��A ���� B�����ַ��������� A �� B ������Ч�������ַ�����
���Ա�д�� (A) ���ַ��������� A ��һ����Ч�ġ������ַ�����
*/
class Solution {
public:
	string helper(string s, char open, char close)
	{
		int cnt = 0;
		string res;
		for (auto c : s)
		{
			if (c == open)
			{
				cnt++;
			}
			if (c == close)
			{
				if (cnt == 0)
				{
					continue;
				}
				cnt--;
			}
			res += c;
		}
		return res;
	}

	string minRemoveToMakeValid(string s) {
		string res;
		res = helper(s, '(', ')');
		reverse(res.begin(), res.end());
		res = helper(res, ')', '(');
		reverse(res.begin(), res.end());
		return res;
	}
};